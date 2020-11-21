#pragma once
#ifndef  AAL2
#define AAL2

// �.�. � ����������� ����� ����� ���� � �� ��
// ������� � ���������, ������� �� ��������� 
// � ����� ������������ ����, ��� �����������
// � ����� � ��-��� ������� JUL.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include "labengine.h"
#define NMAXJULIAN 100
#define NMAXMANDELBROD 1023
typedef struct point_t { // ���������� ����� � ��� ���������
    double x;
    double y;
} point_t;

typedef struct rect_t { // �������� ���������
    int X1;
    int Y1;
    int X2;
    int Y2;
} rect_t;
point_t Transform(point_t p, rect_t const* from, rect_t const* to);
labbool_t IsInsideDisk(point_t p);
void DrawDisk(rect_t const* math, rect_t const* screen);
labbool_t IsInsideDisk(point_t p);
labbool_t IsInsideDisk2R(point_t p);
point_t Iteration(point_t* z, point_t c);

#endif // ! AAL2
