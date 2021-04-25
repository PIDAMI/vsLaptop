#include <iostream>
#include "Reduction.h"
#include <fstream>
#include <iomanip>
using namespace std;

void print_nodes(ofstream& file, const vector<double>& v) {
	for (auto& i : v)
		file << i << ' ';
}

void print_err(ofstream& file, const vector<double>& y_ex, const vector<double>& y_num) {
	for (size_t i = 0; i < y_ex.size(); i++)
		file << fabs(y_ex[i] - y_num[i]) << ' ';
}

double inf_norm(const vector<double>& x, const vector<double>& y) {
	double mx = fabs(x[0] - y[0]);
	for (size_t i = 1; i < x.size(); i++) {
		double tmp = fabs(x[i] - y[i]);
		if (tmp > mx)
			mx = tmp;
	}
	return mx;
}

int main(int argc, char** argv) {


	ofstream file("d.txt");
	if (!file.is_open()) {
		cout << "file not found";
		exit(1);
	}


	int action = 1; // 1 - init, 2 - err, 3 - max, 4 - init_val
	int coef = 1; // 1 - y(a) = A, 2 - 0.4 y(a) + 0.9 y'(a) = A, 1.2 + 0.5 
	double h = 0.25;

	if (argc > 1)
		h = strtod(argv[1], NULL);
	if (argc > 2)
		action = strtol(argv[2], NULL, 10);
	if (argc > 3)
		coef = strtol(argv[3], NULL, 10);

	vector<double> x, y_ex, y_num;

	Vector alpha, beta;

	if (coef == 1){
		alpha = { 1.0, 0.0 };
		beta = { 1.0, 0.0 };
	}
	else {
		alpha = { 1.0, 0.0 };
		beta = { 0.3, 0.9 };
	}
	
	double A = 0.0;
	double B = beta[0] + beta[1] * 2;

	if (action == 1 || action == 2) {
		x = nodes(a, b, h);
		y_ex = Y(x);
		y_num = reduction(a, b, h, alpha, beta, A, B);

	}

	file.precision(10);
	file << std::scientific;

	
	if (action == 1) {
		print_nodes(file, x);
		print_nodes(file, y_num);
	}
	if (action == 2) {
		print_nodes(file, x);
		print_err(file, y_ex, y_num);
	}
	else if (action == 3) {
		h = static_cast<int>(h);
		Vector mx;
		mx.reserve(h);
		for (int i = 1; i <= h; i++) {
			double step = pow(10, -i);
			x = nodes(a, b, step);
			y_ex = Y(x);
			y_num = reduction(a, b, step, alpha,beta,A,B);
			mx.push_back(inf_norm(y_ex, y_num));
		}
		print_nodes(file, mx);
	}


	if (action == 4) {
		h = static_cast<int>(h);
		Vector error, int_val;
		const double ya = 0;
		error.reserve(h);
		double step = 0.01;
		for (int i = 1; i <= h; i++) {
			double ivA = init_val(ya,i);
			A = alpha[0] * ivA;
			x = nodes(a, b, step);
			y_ex = Y(x);
			y_num = reduction(a, b, step, alpha, beta, A, B);
			error.push_back(inf_norm(y_ex, y_num));
			int_val.push_back(ivA - ya);
		}
		print_nodes(file, int_val);
		print_nodes(file, error);

	}

	return 0;
}