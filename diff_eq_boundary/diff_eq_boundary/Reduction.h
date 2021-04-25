#pragma once

#include <vector>
typedef std::vector<double> Vector;

const double a = 0;
const double b = 1;




Vector f_heterogen(double x, double y, double z);
Vector f_homogen(double x, double y, double z);

Vector Y(const Vector& x);
Vector nodes(double a, double b, double h);
std::vector<Vector> runge_kutta(double a, double b, double h, double ya, double yya,
								Vector(*eval)(double, double, double));
Vector reduction(double a, double b, double h,
				const Vector& alpha, const Vector& beta, double A, double B);
double init_val(double ex, int i);