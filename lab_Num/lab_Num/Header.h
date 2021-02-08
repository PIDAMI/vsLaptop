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

void MaxErrMod(double* xMod, double* yMod, double* yDerMod, int n, int density, double* y_eval_mod, double* x_eval2, FILE* ffp);
void MaxErrUnMod(double* x, double* y, double* yDer, int n, int density, double* y_eval, double* x_eval, FILE* ffp);
void Mod(double* xMod, double* yMod, double* yDerMod, int n, int density, double* y_eval_mod, double* x_eval2, FILE* ffp);
void UnMod(double* x, double* y, double* yDer, int n, int density, double* y_eval, double* x_eval, FILE* ffp);
double* YDer(int n, double* x);
double* Y(int n, double* x);
double* mid_node(double* x, int n);
double* NodesMod(int n, double a, double b);
double* Nodes(int n, double a, double b);
double* HermInterChebNet(double x_0, double x_n, int n, double* x, double* y, double* yDer, int density, double* x_eval);
double* linspaces(int n, double x_0, double x_n);

#endif // !__HEADER__

