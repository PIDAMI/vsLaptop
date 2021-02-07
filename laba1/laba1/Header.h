#pragma once
#ifndef __HEADER__
#define __HEADER__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10
#define TESTS 1
#define FILE_NOT_FOUND 1;
#define STEP_EVAL 0.01
#define PI 3.14159265
#define X0 3.0
#define XN 8.0
typedef struct {
	double matrix[SIZE][SIZE];
} mtr;

double MatrixInfNorm(mtr m);
void NthVectorFromMatrix(double* vector, mtr mat, int n);
double VectorNormInf(double* vector);
mtr BuildHouseholderMatrixNRow(double* a, int n);
mtr MatrixProduct(const mtr m1, const mtr  m2);
void RightSideProduct(mtr m, double* b, double* container);
void PrintMatrix(const mtr* m);
double SolveTrianglSystem(const mtr m, const double* b, const double* X);
int JacobiSyst(const mtr m, const double* b, double eps, double* xExact);
double VectorNorm2(double* vector, int k);

#endif // !__HEADER__

