//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <iomanip>
//#include <fstream>
//#define STEP 0.01
//
//using namespace std;
//
//
//vector<double> thomas(vector <double> diag, vector<double> up, vector<double> down, vector<double> rhs) {
//	vector <double> res;
//	vector <double> k;
//	vector <double> b;
//	size_t n = diag.size();
//	up.push_back(0);
//	down.insert(down.begin(), 1, 0);
//	k.push_back(-up[0] / diag[0]);
//	b.push_back(rhs[0] / diag[0]);
//	for (size_t i = 1; i < n - 1; i++) {
//		k.push_back(-up[i] / (down[i] * k[i - 1] + diag[i]));
//		b.push_back((rhs[i] - down[i] * b[i - 1]) / (down[i] * k[i - 1] + diag[i]));
//	}
//	k.push_back(0);
//	b.push_back((rhs[n - 1] - down[n - 1] * b[n - 2]) / (down[n - 1] * k[n - 2] + diag[n - 1]));
//	reverse(k.begin(), k.end()); 
//	reverse(b.begin(), b.end());
//	
//
//	res.push_back(b[0]);//res[3]
//	for (int i = 1; i < k.size(); i++) {
//		res.push_back( k[i] * res[i-1] + b[i]);
//	}
//	reverse(res.begin(), res.end());
//	return res;
//}
//
//vector <double> node(size_t n, double a, double b) {
//	vector <double> nodes;
//	double diff = b - a;
//	for (size_t i = 0; i <= n; i++) {
//		nodes.push_back(a + i * diff / n);
//	}
//	return nodes;
//}
//
//
//vector <double> node_mod(size_t n, double a, double b) {
//	vector <double> nodes;
//	double diff = b - a;
//	for (size_t i = 0; i <= n; i++) {
//		nodes.push_back(a + diff * i / n * i / n);
//	}
//	return nodes;
//}
//
//
//vector <double> Y(vector<double>& x) {
//	vector <double> y;
//	for (auto val : x) {
//		y.push_back(tan(val / 2 + 0.2) - val * val);
//	}
//	return y;
//}
//
//vector <double> Y_mod(vector<double>& x) {
//	vector <double> y;
//	for (auto val : x) {
//		y.push_back((tan(val / 2 + 0.2) - val * val)*abs(val-6));
//	}
//	return y;
//}
//
//
//
//vector<vector<double>> get_coef(const vector<double>& x, const vector<double>& y, double df_a, double df_b) {
//	vector <double> diag;
//	vector <double> up;
//	vector <double> down;	
//	vector <double> rhs;
//	vector<double> h, delt; // dx_i & dy_i 
//	// left limit derrivative condition
//	h.push_back(x[1] - x[0]);
//	delt.push_back((y[1] - y[0]));
//	diag.push_back(h[0] * 2 / 3);
//	up.push_back(-h[0] / 6);
//	rhs.push_back(df_a - delt[0] / h[0]);
//	
//	
//	size_t size = x.size();
//	double  h_sum;
//	for (size_t i = 1; i < size-1; i++) {
//		h.push_back(x[i + 1] - x[i]);
//		delt.push_back(y[i + 1] - y[i]);
//		h_sum = h[i] + h[i-1];
//		down.push_back(h[i-1]/ h_sum);
//		diag.push_back(2);
//		up.push_back(h[i]/ h_sum);
//		//rhs.push_back(3 / h_sum * (delt[i] / h[i] - delt[i - 1] / h[i - 1]));
//
//		rhs.push_back(6 / h_sum * (delt[i] / h[i] - delt[i-1] / h[i-1]));
//	}
//	h.push_back(x[size-1] - x[size-2]);
//	delt.push_back(y[size - 1] - y[size - 2]);
//	
//	//right limit derrivative condition
//	down.push_back(h[size - 1] / 6);//6
//	diag.push_back(h[size - 1] / 3);//3
//	rhs.push_back(df_b - delt[size-1] / h[size-1]);
//	
//
//	vector <double> M = thomas(diag, up, down, rhs);
//	vector<double> C, D;
//	for (size_t i = 1; i < size; i++) {
//		D.push_back(y[i - 1] - M[i - 1] * pow(h[i - 1], 2) / 6);
//		C.push_back(delt[i - 1] / h[i - 1] - h[i - 1] / 6 * (M[i] - M[i - 1]));
//	}
//	vector <vector <double>> coef;
//	
//	//coef.push_back(diag);
//	//coef.push_back(up);
//	//coef.push_back(down);
//	//coef.push_back(rhs);
//	//coef.push_back(M);
//
//	coef.push_back(M);
//	coef.push_back(C);
//	coef.push_back(D);
//	return coef;
//}
//
//vector <double> linspace(double a, double b, double step) {
//	vector <double> lp;
//	while (a <= b) {
//		lp.push_back(a);
//		a += step;
//	}
//	return lp;
//}
//
//vector <double> inter(const vector<double>& M, const vector<double>& C,
//					const vector<double>& D, const vector<double>& nodes,
//					 const vector<double>& x_eval, const vector<double>& h) {
//	vector<double> val;
//	size_t j = 0;
//	size_t size = nodes.size();
//	
//	for (size_t i = 1; i < size; i++) {
//		while (j < x_eval.size() && x_eval[j] < nodes[i]) {
//			val.push_back(M[i - 1] * pow((nodes[i] - x_eval[j]), 3) / (6 * h[i - 1])
//						+ M[i] * pow((x_eval[j] - nodes[i - 1]), 3) / (6 * h[i - 1])
//						+ C[i-1] * (x_eval[j] - nodes[i - 1])
//						+ D[i-1]);
//			j++;
//		}
//	}
//
//	if (nodes == x_eval) {
//		val.push_back(M[size-2] * pow((nodes[size - 1] - x_eval[size - 1]), 3) / (6 * h[size - 2])
//			+ M[size - 1] * pow((x_eval[size - 1] - nodes[size - 2]), 3) / (6 * h[size - 2])
//			+ C[size - 2] * (x_eval[size - 1] - nodes[size - 2])
//			+ D[size - 2]);
//	}
//
//	return val;
//}
//
//vector <double> dx(const vector<double>& x) {
//	vector <double> grid;
//	for (size_t i = 0; i < x.size() - 1; i++) {
//		grid.push_back(x[i + 1] - x[i]);
//	}
//	return grid;
//}
//
//void print_error(ofstream& file, vector<double>& x_eval,
//				vector<double>& y_eval, vector<double>& y) {
//	for (size_t i = 0; i < x_eval.size(); i++) {
//		file << x_eval[i] << ' ';
//	}
//	for (size_t i = 0; i < y_eval.size(); i++) {
//		file << y[i] - y_eval[i] << ' ';
//	}
//}
//
//void print_init(ofstream& file, vector<double>& x_eval, vector<double>& y_eval) {
//	for (size_t i = 0; i < x_eval.size(); i++) {
//		file << x_eval[i] << ' ';
//	}
//	for (size_t i = 0; i < y_eval.size(); i++) {
//		file << y_eval[i] << ' ';
//	}
//}
//
//
//void print_nodes(ofstream& file, 
//				vector<double>& x, vector<double>& y,
//				vector<double>& y_eval_nodes) {
//	for (size_t i = 0; i < x.size(); i++) {	
//		file << x[i] << ' ';
//	}
//	for (size_t i = 0; i < y.size(); i++) {
//		file << y[i] - y_eval_nodes[i] << ' ';
//	}
//}
//
//
//void print_max(ofstream& file, vector<double>& y_eval, vector<double>& x_eval, vector<double>& y) {
//	double mx = 0;
//	for (size_t i = 0; i < y.size(); i++) {
//		if (mx < fabs(y[i] - y_eval[i]))
//			mx = fabs(y[i] - y_eval[i]);
//	}
//	file << mx;
//}
//// 1.5 a + 1.5 (b-a) i / n;
//// df_a_exact = 24.1188 = b = -a
//// df_b_exact = -13.9197
//double unmod_lim(double exact_val, int i, int n) {
//	return (exact_val - 2 * exact_val * i / n);
//
//}
//
//// 1.5 a + 1.5 (b-a) i / n;
//// df_a_mod = 89.0531
//// df_b_mod = -90.0617
//double mod_lim(double exact_val, int i, int n) {
//	return (exact_val - 2 * exact_val * i / n);
//
//}
//
//
//
//int main(int argc, char** argv) {
//	
//
//	double mx=0;
//
//	double a = 3;
//	double b = 8;
//	size_t n = 5;
//	int action = 1;
//	int grid = 1;
//	if (argc > 1)
//		n = static_cast<int>(atoi(argv[1]));
//	if (argc > 2)
//		action = atoi(argv[2]);
//	if (argc > 3)
//		grid = atoi(argv[3]);
//
//
//	fstream file("d.txt");
//
//	vector <double> x = node(n, a, b);
//
//	vector <double> h = dx(x);
//	vector <double> y;
//	vector <double> x_eval = linspace(a, b, STEP);
//	double df_a, df_b;
//
//
//	vector <double> mx_er;
//	vector <double> dfs_a;
//	vector <double> dfs_b;
//	int num_of_tests = 50;
//	for (int i = 0; i <= num_of_tests; i++) {
//		
//		action = 3;
//		if (grid == 1) {
//			y = Y(x);
//			df_a = unmod_lim(0.5 * pow(cos(a / 2 + 0.2), -2) - 2 * a, i, num_of_tests);
//			df_b = unmod_lim(0.5 * pow(cos(b / 2 + 0.2), -2) - 2 * b, i, num_of_tests);
//		}
//		else {
//			y = Y_mod(x);
//			df_a = mod_lim(3 * (a * a - 4 * a) - 0.5 * (a - 6) * pow(cos(a / 2 + 0.2), -2) - tan(a / 2 + 0.2)
//							, i, num_of_tests);
//			df_b = mod_lim(-3 * (b * b - 4 * b) + 0.5 * (b - 6) * pow(cos(b / 2 + 0.2), -2) + tan(b / 2 + 0.2)
//							, i, num_of_tests);
//		}
//		dfs_a.push_back(df_a);
//		dfs_b.push_back(df_b);
//		
//		vector <vector<double>> coef = get_coef(x, y, df_a, df_b);
//
//
//
//
//
//		vector <double> y_eval = inter(coef[0], coef[1], coef[2], x, x_eval, h);
//
//
//		vector <double> y_ex;//exact values in points 3:0.01:8
//		if (grid == 2)
//			y_ex = Y_mod(x_eval);
//		else
//			y_ex = Y(x_eval);
//
//			
//		for (size_t j = 0; j < y_ex.size(); j++) {
//			if (mx < fabs(y_ex[j] - y_eval[j]))
//				mx = fabs(y_ex[j] - y_eval[j]);
//		}
//
//		mx_er.push_back(mx);
//		mx = 0;
//
//	}
//	file << num_of_tests << endl;
//	for (auto& val : mx_er) {
//		file << val << ' ';
//	}
//	for (auto& val : dfs_a) {
//		file << val << ' ';
//	}
//	for (auto& val : dfs_b) {
//		file << val << ' ';
//	}
//
//	
//	file.close();
//	return 0;
//}



#include <iostream>

#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
#define STEP 0.01

using namespace std;


vector<double> thomas(vector <double> diag, vector<double> up, vector<double> down, vector<double> rhs) {
	vector <double> res;
	vector <double> k;
	vector <double> b;
	size_t n = diag.size();
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
	for (int i = 1; i < k.size(); i++) {
		res.push_back(k[i] * res[i - 1] + b[i]);
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


vector <double> node_mod(size_t n, double a, double b) {
	vector <double> nodes;
	double diff = b - a;
	for (size_t i = 0; i <= n; i++) {
		nodes.push_back(a + diff * i / n * i / n);
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
	// left limit derrivative condition
	h.push_back(x[1] - x[0]);
	delt.push_back((y[1] - y[0]));
	diag.push_back(h[0] * 2 / 3);
	up.push_back(-h[0] / 6);
	rhs.push_back(df_a - (y[1] - y[0]) / (x[1] - x[0]));


	size_t size = x.size();
	double  h_sum;
	for (size_t i = 1; i < size - 1; i++) {
		h.push_back(x[i + 1] - x[i]);
		delt.push_back(y[i + 1] - y[i]);
		h_sum = h[i] + h[i - 1];
		down.push_back((x[i] - x[i-1])/ (x[i+1]-x[i-1]));//h[0] = x[1]-x[0]
		diag.push_back(2);
		up.push_back((x[i + 1] - x[i]) / (x[i + 1] - x[i - 1]));
		//rhs.push_back(3 / h_sum * (delt[i] / h[i] - delt[i - 1] / h[i - 1]));

		rhs.push_back(6 / (x[i + 1] - x[i - 1]) * ((y[i + 1] - y[i]) / (x[i + 1] - x[i]) - (y[i] - y[i - 1]) / (x[i] - x[i-1])));
	}
	h.push_back(x[size - 1] - x[size - 2]);
	delt.push_back(y[size - 1] - y[size - 2]);

	//right limit derrivative condition
	down.push_back((x[size - 1] - x[size - 2]) / 6);//6
	diag.push_back((x[size - 1] - x[size - 2]) / 3);//3
	rhs.push_back(df_b - (y[size - 1] - y[size - 2]) / (x[size - 1] - x[size - 2]));


	vector <double> M = thomas(diag, up, down, rhs);
	vector<double> C, D;
	for (size_t i = 1; i < size; i++) {
		D.push_back(y[i - 1] - M[i - 1] * pow((x[i] - x[i - 1]), 2) / 6);//h[0]
		C.push_back((y[i] - y[i - 1]) / (x[i] - x[i - 1]) - (x[i] - x[i - 1]) / 6 * (M[i] - M[i - 1]));
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
					const vector<double>& x_eval, const vector<double>& h,
					double df_a) {
	vector<double> val;
	size_t j = 0;
	size_t size = nodes.size();



	for (size_t i = 1; i < size; i++) {
		while (j < x_eval.size() && x_eval[j] < nodes[i]) {
			val.push_back(M[i - 1] * pow((nodes[i] - x_eval[j]), 3) / (6 * (nodes[i] - nodes[i-1]))
				+ M[i] * pow((x_eval[j] - nodes[i - 1]), 3) / (6 * (nodes[i] - nodes[i-1]))
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
	for (size_t i = 0; i < x_eval.size(); i++) {
		file << x_eval[i] << ' ';
	}
	for (size_t i = 0; i < y_eval.size(); i++) {
		file << y[i] - y_eval[i] << ' ';
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


void print_nodes(ofstream& file,
	vector<double>& x, vector<double>& y,
	vector<double>& y_eval_nodes) {
	for (size_t i = 0; i < x.size(); i++) {
		file << x[i] << ' ';
	}
	for (size_t i = 0; i < y.size(); i++) {
		file << y[i] - y_eval_nodes[i] << ' ';
	}
}


void print_max(ofstream& file, vector<double>& y, vector<double>& y_eval) {
	double mx = 0;
	for (size_t i = 0; i < y.size(); i++) {
		if (mx < fabs(y[i] - y_eval[i]))
			mx = fabs(y[i] - y_eval[i]);
	}
	file << mx;
}
// 1.5 a + 1.5 (b-a) i / n;
// df_a_exact = 24.1188 = b = -a
double unmod_lim(double lim, int i, int n) {
	double exact_val = 0.5 * pow(cos(lim / 2 + 0.2), -2) - 2 * lim;
	return 1.5 * (exact_val - 2 * exact_val * i / n);
}

// 1.5 a + 1.5 (b-a) i / n;
// df_a_exact = 24.1188 = b = -a
double mod_lim(double lim, int i, int n) {
	double exact_val = -3 * (lim * lim - 4 * lim) + 0.5 * (lim - 6) * pow(cos(lim / 2 + 0.2), -2) + tan(lim / 2 + 0.2);
	return 1.5 * (-exact_val + 2 * exact_val * i / n);

}



int main(int argc, char** argv) {

	double df_a;
	double df_b;
	double a = 3;
	double b = 8;
	size_t n = 3;
	int action = 1;
	int grid = 1;
	if (argc > 1)
		n = static_cast<int>(atoi(argv[1]));
	if (argc > 2)
		action = atoi(argv[2]);
	if (argc > 3)
		grid = atoi(argv[3]);


	ofstream file("d.txt");

	vector <double> x = node(n, a, b);

	vector <double> h = dx(x);
	vector <double> y;

	if (grid == 2) {
		y = Y_mod(x);
		df_a = 3 * (a * a - 4 * a) - 0.5 * (a - 6) * pow(cos(a / 2 + 0.2), -2) - tan(a / 2 + 0.2);
		df_b = -3 * (b * b - 4 * b) + 0.5 * (b - 6) * pow(cos(b / 2 + 0.2), -2) + tan(b / 2 + 0.2);
	}
	else {
		y = Y(x);
		df_a = 0.5 * pow(cos(a / 2 + 0.2), -2) - 2 * a;
		df_b = 0.5 * pow(cos(b / 2 + 0.2), -2) - 2 * b;

	}
	df_a = -df_a;


	

	vector <vector<double>> coef = get_coef(x, y, df_a, df_b);



	//for (auto& vec : coef) {
	//	for (auto val : vec) {
	//		file << val << ' ';
	//	}
	//	file << endl;
	//}


	vector <double> x_eval = linspace(a, b, STEP);
	vector <double> y_eval = inter(coef[0], coef[1], coef[2], x, x_eval, h, df_a);


	vector <double> y_eval_nodes = inter(coef[0], coef[1], coef[2], x, x, h,df_a);//spline val in nodes




	vector <double> zeros;
	for (size_t i = 0; i < y_eval_nodes.size(); i++)
		zeros.push_back(0);


	vector <double> y_ex;//exact values in points 3:0.01:8
	if (grid == 2)
		y_ex = Y_mod(x_eval);
	else
		y_ex = Y(x_eval);

	for (auto kef : coef) {
		for (auto c : kef) {
			file << c << ' ';
		}
	}
	for (auto c : h) {
		file << c << ' ';
	}
	for (auto c : x) {
		file << c << ' ';
	}
	file.close();
	return 0;


	if (action == 1) { // initial fun + nodes
		print_init(file, x_eval, y_eval);
		print_nodes(file, x, y, zeros);
	}
	else if (action == 2) { // error + nodes
		print_error(file, x_eval, y_eval, y_ex);
		print_nodes(file, x, y, y_eval_nodes);
	}
	else if (action == 3) { // max_error
		
		file.setf(ios::scientific);
		print_max(file, y_ex, y_eval);
	}

	file.close();
	return 0;
}


