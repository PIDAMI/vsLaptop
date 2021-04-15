#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#define STEP 0.01

// solve tridiagonal system
std::vector<double> thomas(std::vector <double> diag, std::vector<double> up,
							std::vector<double> down, std::vector<double> rhs);
// nodes of uniform grid, x_0 = a, x_n = b
std::vector <double> node(size_t n, double a, double b);

// evaluate tan(0.5 x + 0.2) - x^2 at x points
std::vector <double> Y(const std::vector<double>& x);

// evaluate (tan (0.5 x + 0.2) - x^2) |x - 6| at x points
std::vector <double> Y_mod(std::vector<double>& x);

// calculate coefficients of the spline, df_a,b - values of derivative in points a and b
std::vector<std::vector<double>> get_coef(const std::vector<double>& x, const std::vector<double>& y, double df_a, double df_b);

std::vector <double> linspace(double a, double b, double step);

// calculate values of spline in x_eval points 
std::vector <double> inter(const std::vector<double>& M, const std::vector<double>& C,
							const std::vector<double>& D, const std::vector<double>& nodes,
							const std::vector<double>& x_eval, const std::vector<double>& h);
// calculate x_{i+1} - x_i
std::vector <double> dx(const std::vector<double>& x);

// print points and error in points
void print_error(std::ofstream& file, std::vector<double>& x_eval,
				std::vector<double>& y_eval, std::vector<double>& y);


// print points and spline value in points
void print_init(std::ofstream& file, std::vector<double>& x_eval, std::vector<double>& y_eval);

// print nodes and error in nodes, x - nodes, y - init func val in nodes, y_eval_nodes - spline val in nodes
void print_nodes(std::ofstream& file, std::vector<double>& x, std::vector<double>& y, std::vector<double>& y_eval_nodes);


// print max error, y_eval - spline, y - init func
void print_max(std::ofstream& file, std::vector<double>& y_eval, std::vector<double>& y);


// 1.5 a + 1.5 (b-a) i / n;
double unmod_lim(double exact_val, int i, int n);


// 1.5 a + 1.5 (b-a) i / n;
double mod_lim(double exact_val, int i, int n);
