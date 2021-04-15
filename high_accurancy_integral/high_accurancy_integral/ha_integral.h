#pragma once


#include <vector>
const static double _a = 0.5;
const static double _b = 2.0;
const static double exact_val = (170755 * cos(4.0 / 5)) / 8 - (1913465 * cos(1.0 / 5)) / 64
								- (376101 * sin(1.0 / 5)) / 64 + (173823 * sin(4.0 / 5)) / 8;

std::vector<double> nodes();
std::vector<double> Y(const double a, const double b, const std::vector<double>& x);

std::vector<double> YModCont(const double a, const double b, const std::vector<double>& x);
std::vector<double> YModTail(const double a, const double b, const std::vector<double>& x);
std::vector<double> gauss_lobato_discont(const double eps, const double a, const double b);

double elem_interval_integral(const std::vector<double>& y, const double a, const double b);
std::vector<double> linspace(double a, const double b, const int n);
std::vector<double> gauss_lobato(const double eps, const double a, const double b);