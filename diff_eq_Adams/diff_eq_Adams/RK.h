#pragma once

#include <vector>
#include <iostream>

namespace RK {

	static const double a = 1.0;
	static const double b = 1.2;
	static const double ya = 1.0 / (2 * log(2));
	static long long max_iter = 1;

	std::vector<double> nodes_n(double a, double b, int n);
	std::vector<double> nodes_step(double a, double b, double h);
	double f(double x, double y);
	std::vector<double> Y(const std::vector<double>& x);
	//std::vector<double> runge_kutta(double a, double b, double y_a, double h = 0.1);
	std::vector<double> runge_kutta(double a, double b, double y_a, double h, double (*eval)(double, double));
	std::vector<double> eps_runge_kutta(double a, double b, double y_a, double eps, double h, int& iter);
	double cheb_norm(const std::vector<double>& x, const std::vector<double>& y);
	double elem_int(double eps, double a, double b, double y, int& iter);
	double init_val(int i);
}






