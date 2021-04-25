#include "integral.h"
#include <tuple>
using namespace std;
// n = 4



tuple<int, double> f() {
	return { 2,2.4 };
}

vector<double> nk::nodes(double a, double b, int n, double H) {
	vector<double> res;
	double h = H / 2;
	res.push_back(a + h);
	for (int i = 1; i < n; i++)
		res.push_back(res[i - 1] + H);
	return res;
}



// n = 1
double nk::trapezoidal(const vector<double>& x,const vector <double>& y) {
	vector <double> res;
	double sum = 0;
	int n = x.size();
	double h = x[1] - x[0];
	for (int i = 0; i < n - 1; i++) { // 
		res.push_back(h * (y[i] + y[i + 1]) / 2);
	}
	// 1 2 3
	// f1 f2
	if (!(n % 2))
		res[0] += res[n - 2];
	for (int step = 1; step < n ; step *= 2) {
		for (int i = 0; i < n - step - 1; i += 2 * step) { // 
			res[i] = res[i] + res[i + step];
			res[i + step] = 0;
		//	cout << res[i] << endl << res[i + step] << endl;
		}
	}
	return res[0];
}


double nk::simple_trapezoidal(const vector<double>& x, const vector <double>& y) {
	vector <double> res;
	double sum = 0;
	int n = x.size();
	double h = x[1] - x[0];
	for (int i = 0; i < n - 1; i++) {
		sum += h * (y[i] + y[i + 1]) / 2;
	}
	return sum;
}

double nk::rect_sum(const vector<double>& v) {
	double res=0;
	for (auto& i : v)
		res += i;
	return res;
}




vector<double> nk::Y(const vector<double>& x) {
	vector<double> res;
	for (auto& node : x) {
		res.push_back(cos(0.4*node)*(pow(node, 5) - 5.2 * pow(node, 3) + 
					  5.5 * pow(node, 2) - 7 * node - 3.5));
	}

	trap_calls += x.size();
	return res;
}




// - (b-a)/12 h^2 f''
vector<double> nk::trap(double eps, double a, double b, double yy_a, double yy_b, int action) {
	int n = 1;
	double H = b - a;
	double I_trap_prev, I_trap_next;
	I_trap_next = H / 2 * (yy_b + yy_a);
	double I_rect;
	vector <double> x;
	vector <double> y;
	//printf("x0 = %lf, x1 = %lf\n", a, b);
	//printf("y0 = %lf, y1 = %lf\n", yy_a, yy_b);
	//printf("1: %lf\n\n", I_trap_next);
	do {
		I_trap_prev= I_trap_next;
		x = nodes(a, b, n, H);
		y = Y(x);
		I_rect = H * rect_sum(y);
		H /= 2;
		n *= 2;
		I_trap_next = (I_rect + I_trap_prev) / 2;
		
		//print(x);
		//printf("\n");
		//print(y);
		
		//printf("iter %d: %lf, ex_er %lf,runge %lf\n", n, I_trap_next, I_trap_next - exact_val, fabs(I_trap_next - I_trap_prev)/3);
	} while (fabs(I_trap_next - I_trap_prev) > 3 * eps);

	double calls = trap_calls;
	trap_calls = 0;

	return { I_trap_next , log2(n), calls };

	//if (action == 1)
	//	return { static_cast<double>(n) };
	//else if (action == 2)
	//	return { fabs(I_trap_next - I_trap_prev)/3 };
	//else if (action == 3)
	//	return { theor_min_err(a,b,n),theor_max_err(a,b,n), I_trap_next - exact_val };
}


double nk::theor_max_err(double a, double b, int n) {
	double h = (b - a) / n;
	return fabs((a - b) / 12 * pow(h, 2) * Y_MAX);
}

double nk::theor_min_err(double a, double b, int n) {
	double h = (b - a) / n;
	return fabs((a - b) / 12 * pow(h, 2) * Y_MIN);
}