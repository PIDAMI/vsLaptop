#include "Adams.h"
#include "RK.h"
#include <iostream>

#include <iomanip>
#include <fstream>

using namespace std;


void print_nodes(ofstream& file, const vector<double>& v) {
	for (auto& i : v)
		file << i << ' ';
}

void print_err(ofstream& file, const vector<double>& y_ex, const vector<double>& y_num) {
	for (size_t i = 0; i < y_ex.size();i++)
		file << fabs(y_ex[i] - y_num[i]) << ' ';
}

double inf_norm(const vector<double>& x, const vector<double>& y) {
	double mx = fabs(x[0]-y[0]);
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
	int method = 1; // 1 - implicit, 2 - pc, 3 - explicit, 4 - rk
	double h = 0.1;
	//i: 1 0.576449
	//0.721348 0.641786 0.576531
	if (argc > 1)
		action = strtol(argv[1], NULL, 10);

	if (argc > 2)
		h = strtod(argv[2], NULL);

	if (argc > 3)
		method = strtol(argv[3], NULL, 10);

	std::vector<double>(*solver)(double, double, double, double);


	if (method == 1)
		solver = adams_implicit;
	else if (method == 2)
		solver = corrector_predictor;
	else if (method == 3)
		solver = rk;
	else
		solver = adams_explicit;

	vector<double> x, y_ex, y_num;

	if (action == 1 || action == 2) {
		x = nodes(a, b, h);
		y_ex = Y(x);
		y_num = solver(a, b, ya, h);
		cout << y_num[0] << ' ' << y_num[1] << ' ' << y_num[2] << endl;
		return 0;
	}




	if (action == 1) {
		print_nodes(file, x);
		print_nodes(file, y_num);
	}
	if (action == 2) {
		print_nodes(file, x);
		print_err(file, y_ex, y_num);
	}
	if (action == 3) {
		h = static_cast<int>(h);
		vector<double> mx;
		mx.reserve(h - 1);
		for (int i = 1; i <= h; i++) {
			double step = pow(10, -i)*0.5;
			x = nodes(a, b, step);
			y_ex = Y(x);
			y_num = solver(a, b, ya, step);
			mx.push_back(inf_norm(y_ex, y_num));
		}
		print_nodes(file, mx);
	}
	if (action == 4) {
		h = static_cast<int>(h);
		vector<double> error, int_val;

		error.reserve(h - 1);
		double step = 0.025;
		for (int i = 1; i <= h; i++) {
			double iv = init_val(i);
			x = nodes(a, b, step);
			y_ex = Y(x);
			y_num = solver(a, b, iv, step);
			error.push_back(inf_norm(y_ex, y_num));
			int_val.push_back(iv - ya);
		}
		print_nodes(file, int_val);
		print_nodes(file, error);

	}

	return 0;
}