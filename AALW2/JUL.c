#include "AAL2.h"

//JUL: Фрактальное множество Жюлиа
//Математическое моделирование : преобразование координат.
point_t Transform(point_t p, rect_t const* from, rect_t const* to) {
    double tx1 = (double)to->X1;
    double tx2 = (double)to->X2;
    double fx1 = (double)from->X1;
    double fx2 = (double)from->X2;
    double ty1 = (double)to->Y1;
    double ty2 = (double)to->Y2;
    double fy1 = (double)from->Y1;
    double fy2 = (double)from->Y2;


    double x_trans = (tx2 - tx1) * (p.x - fx1) / (fx2 - fx1) + tx1;
    double y_trans = (ty2 - ty1) * (p.y - fy1) / (fy2 - fy1) + ty1;
    point_t new = { x_trans,y_trans };
    return  new;
}


labbool_t IsInsideDisk(point_t p) {
    return (p.x * p.x + p.y * p.y <= 1.0) ? LAB_TRUE : LAB_FALSE;
}

void DrawDisk(rect_t const* math, rect_t const* screen) {
    for (int i = screen->X1; i < screen->X2; i++) {
        for (int j = screen->Y1; j < screen->Y2; j++) {
            point_t tmp = { i,j };
            if (IsInsideDisk(Transform(tmp, screen, math)) == LAB_TRUE) {
                LabDrawPoint((int)tmp.x, (int)tmp.y);
            }
        }

    }
    return;
}

point_t Iteration(point_t *z,point_t c) {

    point_t nxt = { z->x * z->x - z->y * z->y + c.x,
                    2 * z->x * z->y + c.y };
    return nxt;
}


// в задании прототип функции, проверяющей, находится ли точка в окружности
// не подразумевает параметра, отвечающего за радиус, так что
// для пункта с множеством Жюлина используется функция, отличная
// от той, что была в пункте 2
labbool_t IsInsideDisk2R(point_t p) {
    return (p.x * p.x + p.y * p.y <= 4.0) ? LAB_TRUE : LAB_FALSE;
}

labbool_t IsInsideJulia(point_t p) {
    point_t c = { -0.12375, 0.56508 };
    for (int i = 0; i < NMAXJULIAN; i++) {
        p = Iteration(&p,c);
        if (IsInsideDisk2R(p) == LAB_FALSE) {
            return LAB_FALSE;
        }
    }
    return LAB_TRUE;
}

void DrawJulia(rect_t const* math, rect_t const* screen) {
    for (int i = screen->X1; i < screen->X2; i++) {
        for (int j = screen->Y1; j < screen->Y2; j++) {
            point_t tmp = { i,j };
            if (IsInsideJulia(Transform(tmp, screen, math)) == LAB_TRUE) {
                LabDrawPoint((int)tmp.x, (int)tmp.y);
            }
        }

    }
    return;
}

//int main(void){
// 
//    if (LabInit())
//    {
//        
//        // yзнать размеры окна
//        int width = LabGetWidth();
//        int height = LabGetHeight();
//        point_t c = { -0.12375, 0.56508 };
//        
//        // для левой половины экрана
//        point_t mzero = { 0,0 };
//        const rect_t screen_left = { 0,0,width/2, height };
//        const rect_t math_left = { -2, 3, 2, -3 };
//        point_t szero = Transform(mzero, &math_left, &screen_left);
//        
//        // для правой половины экрана
//        point_t mzero2 = { 0,0 };
//        const rect_t screen_right = { width / 2, 0, width, height };
//        const rect_t math_right = { -2, 3, 2, -3 };// -2<x<2; -3<y<3
//        point_t szero2 = Transform(mzero2, &math_right, &screen_right);
//        
//        
//        // нарисовать оси для левой половины
//        LabSetColor(LABCOLOR_GREEN);
//        LabDrawLine(0, (int)szero.y, width/2, (int)szero.y);
//        LabDrawLine((int)szero.x, 0, (int)szero.x, height);
//        //нарисовать красный диск с центром в начале осей
//        LabSetColor(LABCOLOR_RED);        
//        DrawDisk(&math_left,&screen_left);
//
//
//
//        // Вторая половина окна
//
//        // нарисовать оси для второй половины
//        LabSetColor(LABCOLOR_GREEN);
//        LabDrawLine(width/2, (int)szero2.y, width, (int)szero2.y);
//        LabDrawLine((int)szero2.x, 0, (int)szero2.x, height);
//        // закрасить множество Жюлиана
//        LabSetColor(LABCOLOR_RED);
//        DrawJulia(&math_right, &screen_right);
//
//
//        
//        LabDrawFlush();
//
//        // нажатие любой клавиши, чтобы выйти из программы
//        LabInputKey();
//        LabTerm();
//    }
//    return 0;
//}