#include "AAL2.h"

//THR: Бросок под углом к горизонту
//Математическое моделирование : динамика.
//Рассчитайте траекторию полёта снаряда, выпущенного из пушки, стоящей в начале
//координат, под углом a = pi/3 со скоростью v0 = 20 м/с.

typedef struct {
    double x;
    double y;
}vec_t;

void DrawAnalyticalPath(
    rect_t const* math, rect_t const* screen,
    vec_t r0, vec_t v0, vec_t a0, double dt) {
    vec_t r1 = r0;
    vec_t r2 = r0;
    point_t r1math = { r0.x,r0.y };
    r1math = Transform(r1math, math, screen);
    LabSetColor(LABCOLOR_DARK_GREEN);
    for (double i = 0; i <= 2 * v0.y / (-a0.y); i += dt) {
        r2.x = r0.x + i * v0.x + i * i * a0.x / 2;
        r2.y = r0.y + i * v0.y + i * i * a0.y / 2;
        point_t r2math = { r2.x, r2.y };
        r2math = Transform(r2math, math, screen);
        LabDrawLine((int)r1math.x, (int)r1math.y, (int)r2math.x, (int)r2math.y);
        r1 = r2;
        r1math = r2math;
    }

    return;
}

void DrawEulerPath(
    rect_t const* math, rect_t const* screen,
    vec_t r0, vec_t v0, vec_t a0, double dt) {
    vec_t v1 = v0;
    vec_t v2 = v0;
    vec_t r1 = r0;
    vec_t r2 = r0;
    point_t r1math = { r0.x,r0.y };
    r1math = Transform(r1math, math, screen);
    LabSetColor(LABCOLOR_RED);
    while(r2.y>=0) {
        r2.x = r1.x + v2.x * dt;
        r2.y = r1.y + v2.y * dt;
        point_t r2math = { r2.x, r2.y };
        r2math = Transform(r2math, math, screen);
        LabDrawLine((int)r1math.x, (int)r1math.y, (int)r2math.x, (int)r2math.y);
        v2.x = v1.x + a0.x * dt;
        v2.y = v1.y + a0.y * dt;
        r1 = r2;
        r1math = r2math;
        v1 = v2;
    }
    
    
    return;
}


void SimulateEulerPath(
    rect_t const* math, rect_t const* screen,
    vec_t r0, vec_t v0, vec_t a0) {
    LARGE_INTEGER count2;
    LARGE_INTEGER count1;
    LARGE_INTEGER freq;
    LARGE_INTEGER countStart;
    double dt;
    double fr;
    QueryPerformanceFrequency(&freq);
    fr = (double)freq.QuadPart;
    vec_t v1 = v0;
    vec_t v2 = v0;
    vec_t r1 = r0;
    vec_t r2 = r0;
    point_t r1math = { r0.x,r0.y };
    r1math = Transform(r1math, math, screen);

    LabSetColor(LABCOLOR_YELLOW);
    QueryPerformanceCounter(&countStart); // t_0
    QueryPerformanceCounter(&count1); // t_n
    dt = ((double)(count1.QuadPart) - (double)(countStart.QuadPart)) / fr;
    // рисовать до тех пор, пока не пройдет примерно 3.5 секунды
    while ((((double)(count1.QuadPart) - (double)(countStart.QuadPart)) / fr) < 3.5) {
        r2.x = r1.x + v2.x * dt;
        r2.y = r1.y + v2.y * dt;
        point_t r2math = { r2.x, r2.y };
        r2math = Transform(r2math, math, screen);
        LabDrawLine((int)r1math.x, (int)r1math.y, (int)r2math.x, (int)r2math.y);
        v2.x = v1.x + a0.x * dt;
        v2.y = v1.y + a0.y * dt;
        r1 = r2;
        r1math = r2math;
        v1 = v2;

        QueryPerformanceCounter(&count2); // t_{n+1}
        dt = ((double)(count2.QuadPart) - (double)(count1.QuadPart)) / fr;
        count1 = count2;
    }
    return;
}



//
//int main(void){
//   
//    
//    if (LabInit())
//    {
//       
//        int width = LabGetWidth();
//        int height = LabGetHeight();
//        double v0length = 20;
//        const rect_t screen = { 0,0,width, height };
//        const rect_t math = { -3, 28, 41, -5 };
//        vec_t r0 = { 0,0 };
//        vec_t v0 = { v0length * cos(pi / 3), v0length * sin(pi / 3) };
//        vec_t a0 = { 0,-9.81 };
//        point_t mzero = { 0,0 };
//        point_t szero = Transform(mzero, &math, &screen);
//
//        // рисуем оси 
//        LabSetColor(LABCOLOR_BLUE);
//        LabDrawLine(0, (int)szero.y, width, (int)szero.y);
//        LabDrawLine((int)szero.x, 0, (int)szero.x, height);
//
//        // аналитическое решение, зеленым цветом
//        DrawAnalyticalPath(&math, &screen, r0, v0, a0, 1);
//        DrawAnalyticalPath(&math, &screen, r0, v0, a0, 0.5);
//        
//        // численное с дискретным временем, красным
//        DrawEulerPath(&math, &screen, r0, v0, a0, 1);
//        DrawEulerPath(&math, &screen, r0, v0, a0, 0.5);
//        
//        // численное с почти непрерывным временем, желтым
//        SimulateEulerPath(&math, &screen, r0, v0, a0);
//        
//        LabDrawFlush();
//
//        // нажатие любой клавиши, чтобы выйти из программы
//        LabInputKey();
//        LabTerm();
//    }
//    return 0;
//}