#include "spline.h"
using namespace std;

vector<double> thomas(vector <double> diag, vector<double> up, vector<double> down, vector<double> rhs) {
	vector <double> res;
	vector <double> k;
	vector <double> b;
	auto n = diag.size();
	up.push_back(0);
	down.insert(down.begin(), 1, 0);
	k.push_back(-up[0] / diag[0]);
	b.push_back(rhs[0] / diag[0]);
	for (size_t i = 1; i < n - 1; i++) {
		k.push_back(-up[i] / (down[i] * k[i - 1] + diag[i]));
		b.push_back((rhs[i] - down[i] * b[i - 1]) / (down[i] * k[i - 1] + diag[i]));
	}
	k.push_back(0);
	b.push_back((rhs[n - 1] - down[n - 1] * b[n - 2]) / (down[n - 1] * k[n - 2] + diag[n - 1]));
	reverse(k.begin(), k.end());
	reverse(b.begin(), b.end());


	res.push_back(b[0]);//res[3]
	for (auto i = 1; i < k.size(); i++) {
		res.push_back(k[i] * res[i - 1] + b[i]);
	}
	reverse(res.begin(), res.end());
	return res;
}

vector <double> node(size_t n, double a, double b) {
	vector <double> nodes;
	auto diff = b - a;
	for (size_t i = 0; i <= n; i++) {
		nodes.push_back(a + i * diff / n);
	}
	return nodes;
}


vector <double> node_mod(size_t n, double a, double b) {
	vector <double> nodes;
	auto diff = b - a;
	for (size_t i = 0; i <= n; i++) {
		nodes.push_back(a + diff * i / n * i / n);
	}
	return nodes;
}


vector <double> Y(const vector<double>& x) {
	vector <double> y;
	for (auto val : x) {
		y.push_back(tan(val / 2 + 0.2) - val * val);
	}
	return y;
}

vector <double> Y_mod(vector<double>& x) {
	vector <double> y;
	for (auto val : x) {
		y.push_back((tan(val / 2 + 0.2) - val * val) * abs(val - 6));
	}
	return y;
}



vector<vector<double>> get_coef(const vector<double>& x, const vector<double>& y, double df_a, double df_b) {
	vector <double> diag;
	vector <double> up;
	vector <double> down;
	vector <double> rhs;
	vector<double> h, delt; // dx_i & dy_i 
	// left limit derivative condition
	h.push_back(x[1] - x[0]);
	delt.push_back((y[1] - y[0]));
	diag.push_back(-h[0] / 3);
	up.push_back(-h[0] / 6);
	rhs.push_back(df_a - delt[0] / h[0]);


	auto size = x.size();
	double  h_sum;
	for (size_t i = 1; i < size - 1; i++) {
		h.push_back(x[i + 1] - x[i]);
		delt.push_back(y[i + 1] - y[i]);
		h_sum = h[i] + h[i - 1];
		down.push_back(h[i - 1] / h_sum);
		diag.push_back(2);
		up.push_back(h[i] / h_sum);

		rhs.push_back(6 / h_sum * (delt[i] / h[i] - delt[i - 1] / h[i - 1]));
	}
	h.push_back(x[size - 1] - x[size - 2]);
	delt.push_back(y[size - 1] - y[size - 2]);

	//right limit derrivative condition
	down.push_back(h[size - 1] / 6);
	diag.push_back(h[size - 1] / 3);
	rhs.push_back(df_b - delt[size - 1] / h[size - 1]);


	auto M = thomas(diag, up, down, rhs);
	vector<double> C, D;
	for (size_t i = 1; i < size; i++) {
		D.push_back(y[i - 1] - M[i - 1] * pow(h[i - 1], 2) / 6);
		C.push_back(delt[i - 1] / h[i - 1] - h[i - 1] / 6 * (M[i] - M[i - 1]));
	}
	vector <vector <double>> coef_;

	//coef_.push_back(diag);
	//coef_.push_back(up);
	//coef_.push_back(down);
	//coef_.push_back(rhs);
	//coef_.push_back(M);

	coef_.push_back(M);
	coef_.push_back(C);
	coef_.push_back(D);
	return coef_;
}

vector <double> linspace(double a, double b, double step) {
	vector <double> lp;
	while (a <= b) {
		lp.push_back(a);
		a += step;
	}
	return lp;
}


// spline s_i(x) = M_{i-1} (x_i - x)^3 / (6 h) + M_i (x - x_{i-1})^3 / (6 h) + C_i (x - x_{i-1}) + D_i
vector <double> inter(const vector<double>& M, const vector<double>& C,
	const vector<double>& D, const vector<double>& nodes,
	const vector<double>& x_eval, const vector<double>& h) {
	vector<double> val;
	size_t j = 0;
	auto size = nodes.size();

	for (size_t i = 1; i < size; i++) {
		while (j < x_eval.size() && x_eval[j] < nodes[i]) {
			val.push_back(M[i - 1] * pow((nodes[i] - x_eval[j]), 3) / (6 * h[i - 1])
				+ M[i] * pow((x_eval[j] - nodes[i - 1]), 3) / (6 * h[i - 1])
				+ C[i - 1] * (x_eval[j] - nodes[i - 1])
				+ D[i - 1]);
			j++;
		}
	}

	if (nodes == x_eval) {
		val.push_back(M[size - 2] * pow((nodes[size - 1] - x_eval[size - 1]), 3) / (6 * h[size - 2])
			+ M[size - 1] * pow((x_eval[size - 1] - nodes[size - 2]), 3) / (6 * h[size - 2])
			+ C[size - 2] * (x_eval[size - 1] - nodes[size - 2])
			+ D[size - 2]);
	}

	return val;
}

vector <double> dx(const vector<double>& x) {
	vector <double> grid;
	for (size_t i = 0; i < x.size() - 1; i++) {
		grid.push_back(x[i + 1] - x[i]);
	}
	return grid;
}

void print_error(ofstream& file, vector<double>& x_eval,
	vector<double>& y_eval, vector<double>& y) {
	for (auto i : x_eval)
	{
		file << i << ' ';
	}
	for (size_t i = 0; i < y_eval.size(); i++) {
		file << y[i] - y_eval[i] << ' ';
	}
}

void print_init(ofstream& file, vector<double>& x_eval, vector<double>& y_eval) {
	for (auto i : x_eval){
		file << i << ' ';
	}
	for (auto i : y_eval){
		file << i << ' ';
	}
}


void print_nodes(ofstream& file,
	vector<double>& x, vector<double>& y,
	vector<double>& y_eval_nodes) {
	for (auto i : x)
	{
		file << i << ' ';
	}
	for (size_t i = 0; i < y.size(); i++) {
		file << y[i] - y_eval_nodes[i] << ' ';
	}
}


void print_max(ofstream& file, vector<double>& y_eval, vector<double>& y) {
	double mx = 0;
	for (size_t i = 0; i < y.size(); i++) {
		if (mx < fabs(y[i] - y_eval[i]))
			mx = fabs(y[i] - y_eval[i]);
	}
	file << mx;
}
// 1.5 a + 1.5 (b-a) i / n;
// df_a_exact = 24.1188 = b = -a
// df_b_exact = -13.9197
double unmod_lim(double exact_val, int i, int n) {
	return 2 * exact_val - 3 * exact_val * i / n;

}

// 1.5 a + 1.5 (b-a) i / n;
// df_a_mod = 89.0531
// df_b_mod = -90.0617
double mod_lim(double exact_val, int i, int n) {
	return 2 * exact_val - 3 * exact_val * i / n;

}