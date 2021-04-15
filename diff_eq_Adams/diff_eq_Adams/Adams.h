#pragma once


#include <vector>


const static double a = 1;
const static double b = 1.4;
const double ya = 1.0 / (2 * log(2));


double f(double x, double y);
std::vector<double> Y(const std::vector<double> x);
double explicit_node(double h, const std::vector<double>& x, const std::vector<double>& y, int i);
std::vector<double> nodes(double a, double b, double h);

double pc_implicit_node(double h, const std::vector<double>& x, const std::vector<double>& y, double y_pred, int i);

std::vector<double> corrector_predictor(double a, double b, double ya, double h);
std::vector<double> adams_explicit(double a, double b, double ya, double h);
std::vector<double> adams_implicit(double a, double b, double ya, double h);
std::vector<double> first_nodes(const std::vector<double>& x, double ya);
std::vector<double> rk(double a, double b, double ya, double h);
double init_val(int i);

