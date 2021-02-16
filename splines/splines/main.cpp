#include "splines.h"
#include <algorithm>
#include <cmath>
#include "..\cpp_alglib\src\linalg.h"
#include <iomanip>
#include <fstream>
#define STEP 0.05

using namespace std;


vector<double> thomas(vector <double> diag, vector<double> up, vector<double> down, vector<double> rhs) {
	vector <double> res;
	vector <double> k;
	vector <double> b;
	



	size_t n = diag.size();
	//up.push_back(0);
	//down.insert(down.begin(), 1, 0);
	k.push_back(-up[0] / diag[0]);
	b.push_back(rhs[0] / diag[0]);
	for (size_t i = 1; i < n - 1; i++) {
		k.push_back(-up[i] / (down[i] * k[i - 1] + diag[i]));
		b.push_back((rhs[i] - down[i] * b[i - 1]) / (down[i] * k[i - 1] + diag[i]));
	}
	k.push_back(0);
	b.push_back((rhs[n - 1] - down[n - 1] * b[n - 2]) / (down[n - 1] * k[n - 2] + diag[n - 1]));
	
	
	res.push_back(b[n - 1]);//res[3]
	for (int i = static_cast<int>(n) - 2; i >= 0; i--) {
		res.push_back( k[i] * res[n-2-i] + b[i]);
	}
	reverse(res.begin(), res.end());
	return res;
}

vector <double> node(size_t n, double a, double b) {
	vector <double> nodes;
	double diff = b - a;
	for (size_t i = 0; i <= n; i++) {
		nodes.push_back(a + i * diff / n);
	}
	return nodes;
}


vector <double> Y(vector<double>& x) {
	vector <double> y;
	for (auto val : x) {
		y.push_back(tan(val / 2 + 0.2) - val * val);
	}
	return y;
}


vector<vector<double>> get_coef(const vector<double>& x, const vector<double>& y, double df_a, double df_b) {
	vector <double> diag;
	vector <double> up;
	vector <double> down;	
	vector <double> rhs;
	vector<double> h, delt;
	// left limit derrivative condition
	
	h.push_back(x[1] - x[0]);
	delt.push_back((y[1] - y[0]));
	
	diag.push_back(h[0]*2/3);
	up.push_back(-h[0]/6);
	rhs.push_back(df_a - delt[0]/h[0]);
	
	size_t size = x.size();
	double  h_sum;
	for (size_t i = 1; i < size-1; i++) {
		h.push_back(x[i + 1] - x[i]);
		delt.push_back(y[i + 1] - y[i]);
		h_sum = h[i] + h[i-1];
		down.push_back(h[i-1]/ h_sum);
		diag.push_back(2);
		up.push_back(h[i]/ h_sum);
		rhs.push_back(6 / h_sum * (delt[i] / h[i] - delt[i-1] / h[i-1]));
	}
	h.push_back(x[size-1] - x[size-2]);
	delt.push_back(y[size - 1] - y[size - 2]);

	diag.push_back(h[size-1]/3);
	down.push_back(h[size-1]/6);
	rhs.push_back(df_b - delt[size-1] / h[size-1]);
	

	up.push_back(0);
	down.insert(down.begin(), 1, 0);


	vector <double> M = thomas(diag, up, down, rhs);
	vector<double> C, D;
	for (size_t i = 1; i < size; i++) {
		D.push_back(y[i - 1] - M[i - 1] * pow(h[i - 1], 2) / 6);
		C.push_back(delt[i - 1] / h[i - 1] - h[i - 1] / 6 * (M[i] - M[i - 1]));
	}
	vector <vector <double>> coef;
	
	//coef.push_back(diag);
	//coef.push_back(up);
	//coef.push_back(down);
	//coef.push_back(rhs);
	//coef.push_back(M);

	coef.push_back(M);
	coef.push_back(C);
	coef.push_back(D);
	return coef;
}

vector <double> linspace(double a, double b, double step) {
	vector <double> lp;
	while (a <= b) {
		lp.push_back(a);
		a += step;
	}
	return lp;
}

vector <double> inter(const vector<double>& M, const vector<double>& C,
					const vector<double>& D, const vector<double>& nodes,
					const vector<double>& h) {
	vector<double> val;
	vector<double> x_eval = linspace(nodes[0],nodes[nodes.size()-1],STEP);
	size_t j = 0;
	size_t size = nodes.size();
	
	for (size_t i = 1; i < size; i++) {
		while (j < x_eval.size() && x_eval[j] < nodes[i]) {
			val.push_back(M[i - 1] * pow((nodes[i] - x_eval[j]), 3) / (6 * h[i - 1])
				+ M[i] * pow((x_eval[j] - nodes[i - 1]), 3) / (6 * h[i - 1])
				+ C[i-1] * (x_eval[j] - nodes[i - 1])
				+ D[i-1]);
			j++;
		}
	}
	return val;
}

vector <double> dx(const vector<double>& x) {
	vector <double> grid;
	double step = x[1] - x[0];
	for (size_t i = 0; i < x.size() - 1; i++) {
		grid.push_back(step);
	}
	return grid;
}

void print_error(ofstream& file, vector<double>& x_eval,
				vector<double>& y_eval) {
	for (size_t i = 0; i < x_eval.size(); i++) {
		file << x_eval[i] << ' ';
	}
	vector<double> y = Y(x_eval);
	for (size_t i = 0; i < y_eval.size(); i++) {
		file <<y[i] - y_eval[i]<< ' ';
	}
}

void print_init(ofstream& file, vector<double>& x_eval, vector<double>& y_eval) {
	for (size_t i = 0; i < x_eval.size(); i++) {
		file << x_eval[i] << ' ';
	}
	for (size_t i = 0; i < y_eval.size(); i++) {
		file << y_eval[i] << ' ';
	}
}


void print_nodes(ofstream& file, vector<double>& x, vector<double>& y) {
	for (size_t i = 0; i < x.size(); i++) {
		file << x[i] << ' ';
	}
	for (size_t i = 0; i < y.size(); i++) {
		file << y[i] << ' ';
	}
}


void print_max(ofstream& file, vector<double>& y_eval, vector<double>& x_eval) {
	vector<double> y = Y(x_eval);
	double mx = 0;
	for (size_t i = 0; i < y.size(); i++) {
		if (mx < fabs(y[i] - y_eval[i]))
			mx = fabs(y[i] - y_eval[i]);
	}
	file <<mx;
}

int main(int argc, char** argv) {
	
	vector <double> c = thomas({ 12.2,11.5,11,32,31,15.2 }, { 1,1,2,6,3,0 }, { 0,2,1,2,1,4 }, { 1,2,3,4,5,6 });
	for (auto i : c) {
		cout << i << ' ';
	}
	return 0;


	double a = 3;
	double b = 8;
	double df_a = 0.5 * pow(cos(a / 2 + 0.2), -2) - 2 * a;
	double df_b = 0.5 * pow(cos(b / 2 + 0.2), -2) - 2 * b;
	size_t n = 3;
	if (argc > 1)
		n = static_cast<int>(atoi(argv[1]));

	vector <double> x = node(n, a, b);

	vector <double> h = dx(x);
	vector <double> y = Y(x);
	vector <vector<double>> coef = get_coef(x, y, df_a, df_b);
	
	ofstream file("d.txt");
	file.setf(ios::scientific);
	
	//for (auto& vec : coef) {
	//	for (auto val : vec) {
	//		file << val << ' ';
	//	}
	//	file << endl;
	//}


	vector <double> x_eval = linspace(a,b,STEP);
	vector <double> y_eval = inter(coef[0], coef[1], coef[2], x, h);



	
	//print_error(file, x_eval, y_eval);
	print_max(file, y_eval, x_eval);

	file.close();


	return 0;
}