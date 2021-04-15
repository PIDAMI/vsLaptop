#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
const static double exact_val = -1791.0 / 128.0;

#define A 0.5
#define B 2.0
#define Y_A -6.24375
#define Y_B -5.1
#define Y_MAX 108.6
#define Y_MIN -3.99909
double integral();

#define print(v) for (auto&i:v) cout << i << ' '; cout << endl;
std::vector<double> nodes(double a, double b, int n, double H);
double rect_sum(const std::vector<double>& v);
std::vector<double> Y(const std::vector<double>& x);

double simple_trapezoidal(const std::vector<double>& x, const std::vector <double>& y);
double trapezoidal(const std::vector<double>& x, const std::vector <double>& y);
std::vector<double> trap(double eps, double a, double b, double yy_a, double yy_b, int action);

double theor_max_err(double a, double b, int n);
double theor_min_err(double a, double b, int n);

