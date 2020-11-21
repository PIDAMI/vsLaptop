#include "AAL2.h"

typedef struct color_t {
    int red;
    int green;
    int blue;
} color_t;


labbool_t IsOutsideDisk2R(point_t p) {
    return (p.x * p.x + p.y * p.y <= 4.0) ? LAB_FALSE : LAB_TRUE;
}

int IsOutsideJulia(point_t z, point_t c) {
    for (int i = 0; i < NMAXMANDELBROD; i++) {
        z = Iteration(&z, c);

        if (IsOutsideDisk2R(z) == LAB_TRUE) {
            return (NMAXMANDELBROD-i);
        }
    }
    return -1; // -1 ������ ���� ��-�� �������� ������������� �������� �������
}


int IsOutsideMandelbrot(point_t c) {
    point_t z = { 0,0 };
    for (int i = 0; i < NMAXMANDELBROD; i++) {
        z = Iteration(&z, c);
        if (IsOutsideDisk2R(z) == LAB_TRUE) {
            return (NMAXMANDELBROD - i);
        }
    }
    return -1;
}

static color_t s_palette[] = {
{0x00, 0x00, 0xFF}, {0x00, 0xFF, 0xFF}, {0xFF, 0xFF, 0x00},
{0xFF, 0x00, 0x00}, {0xFF, 0xFF, 0x00}, {0x00, 0xFF, 0xFF},
{0x00, 0x00, 0xFF},
};
color_t Interpolate(double alpha, color_t* palette, int k) {
    color_t interp = { 0,0,0 };
        interp.red = (1 - alpha) * palette[k].red + alpha * palette[k + 1].red;
        interp.green = (1 - alpha) * palette[k].green + alpha * palette[k + 1].green;
        interp.blue = (1 - alpha) * palette[k].blue + alpha * palette[k + 1].blue;
    return interp;
}

// ������� �� ������ ��������� ��������:
// ������ ������ ����� �� ����� - ������.
// ������������ ����� �� ������� ��� ������������
// ��� � � �������, �������� ��-�� ������������
// �������, �������, �������� ���������
// �� ����������, � ��� ��������
void DrawJulian(rect_t const* math, rect_t const* screen, point_t c, color_t* palette) { 
    for (int i = screen->X1; i < screen->X2; i++) {
        for (int j = screen->Y1; j < screen->Y2; j++) {
            point_t tmp = { i,j };
            double f = (double)IsOutsideJulia(Transform(tmp, screen, math), c);
            double t = 7 * pow(f / ((double)NMAXMANDELBROD + 1), 3); // 7 - ���-�� ������ � ������� 
            double alpha = t - floor(t); // ������� ����� t
            color_t RGB = Interpolate(alpha, palette, (int)t);
            if (f > 0) {
                LabSetColorRGB(RGB.red, RGB.green, RGB.blue);
                LabDrawPoint((int)tmp.x, (int)tmp.y);
            }
        }
    }
    return;
}



void DrawMandelbrot(rect_t const* math, rect_t const* screen, color_t *palette) {
    for (int i = screen->X1; i < screen->X2; i++) {
        for (int j = screen->Y1; j < screen->Y2; j++) {
            point_t tmp = { i,j };
            double f = (double)IsOutsideMandelbrot(Transform(tmp, screen, math));
            double t = 7 * pow((double)f / ((double)NMAXMANDELBROD+1),3); // 7 - ���-�� ������ � ������� 
            double alpha = t - floor(t);
            color_t RGB = Interpolate(alpha, palette, (int)t);
            if (f > 0) {
                LabSetColorRGB(RGB.red, RGB.green, RGB.blue);
                LabDrawPoint((int)tmp.x, (int)tmp.y);
            }
            
        }

    }
    return;
}

//
//int main(void) {
//    
//
//    if (LabInit())
//    {
//        // ������ ������� ����
//        int width = LabGetWidth();
//        int height = LabGetHeight();
//        point_t c = { -0.835, 0.2321 };
//
//        // ��� ����� ����� 
//        const rect_t screen_left = { 0,0,width / 2, height };
//        const rect_t math_left = { -2, 3, 2, -3 };
//        
//        // ��� ������ �����
//        const rect_t screen_right = { width / 2, 0, width, height };
//        const rect_t math_right = { -0.7454356, 0.113019, -0.7454215, 0.1129986 };
//        // ��������� ��������� �������
//        DrawJulian(&math_left, &screen_left,c,s_palette);
//       
//        //��������� ��������� ������������
//        DrawMandelbrot(&math_right, &screen_right,s_palette);
//
//        LabDrawFlush();
//
//        // ������� ����� �������, ����� ����� �� ���������
//        LabInputKey();
//        LabTerm();
//    }
//    return 0;
//}



