#include "Adams.h"
#include "RK.h"

using namespace std;


std::vector<double> nodes(double a, double b, double h) {
	
	return RK::nodes_step(a, b, h);
}

double f(double x, double y) {
	return RK::f(x, y);
	//return 2 * x * (x * x + y) ;
}

vector<double> Y(const vector<double> x) {
	vector<double> res;
	//for (const auto& i : x) {
	//	res.push_back(exp(i * i) - i * i - 1);
	//}
	auto yy = RK::Y(x);
	return yy;
}

double explicit_node(double h, const vector<double>& x, const vector<double>& y, int i) {
	
	return y[i] + h / 12 * (23 * f(x[i], y[i]) - 16 * f(x[i-1], y[i-1]) + 5 * f(x[i-2], y[i-2]));
}

vector<double> adams_explicit(double a, double b, double ya, double h) {
	auto x = RK::nodes_step(a, b, h);
	//auto y = RK::runge_kutta(a, b, ya, h, f);
	auto y = first_nodes(x, ya);
	for (size_t i = 2; i < x.size() - 1; i++) {
		y.push_back(explicit_node(h, x, y, i));
		//y.push_back(implicit_node(h,x,y,i)/* - 19.0 / 270 * (y_cor - y_pred)*/);
	}
	return y;
}


double pc_implicit_node(double h, const vector<double>& x, const vector<double>& y, double y_pred, int i) {
	
	return y[i] + h / 12 * (5 * f(x[i + 1], y_pred) + 8 * f(x[i], y[i]) - f(x[i - 1], y[i - 1]));
}

double implicit_node(double h, const vector<double>& x, const vector<double>& y, int i) {
	
	return (6 * y[i] + h / 2 * (10 * pow(x[i + 1], 3) + 8 * f(x[i], y[i]) - f(x[i - 1], y[i - 1])))
			/ (6 - 5 * h * x[i + 1]);
}


vector<double> corrector_predictor(double a, double b, double ya, double h) {
	auto x = RK::nodes_step(a, b, h);
	//auto y = RK::runge_kutta(x[0], x[2], ya, h, f);
	auto y = first_nodes(x, ya);
	for (size_t i = 2; i < x.size() - 1; i++) {
		double y_pred = explicit_node(h, x, y, i);
		double y_cor = pc_implicit_node(h, x, y, y_pred, i);
		y.push_back(y_cor /*- 19.0 / 270 * (y_cor - y_pred)*/);
	}

	//auto y_ex = Y(x);
	//cout << "pc " << y[1] - y_ex[1] << ' ' << y[2] - y_ex[2] << ' ' << y[3] - y_ex[3] << endl;
	return y;
}

//vector<double> first_nodes(const vector<double>& x, double ya) {
//	vector<double> res;
//	auto y_ex = Y(x);
//	for (int i = 0; i <= 2; i++)
//		res.push_back(y_ex[i]);	
//	return res;
//}
vector<double> first_nodes(const vector<double>& x, double ya) {
	vector<double> y;
	y.push_back(ya);

	for (int i = 0; i < 2; i++)
	{
		double h = x[i+1] - x[i];
		double k1 = f(x[i], y[i]);
		double k2 = f(x[i] + h / 3, y[i] + h * k1 / 3);
		double k3 = f(x[i] + 2 * h / 3, y[i] + 2 * h * k2 / 3);
		y.push_back(y[i] + h / 4 * (k1 + 3 * k3));
		cout << "k1 " << k1 << endl;
		cout << "k2 " << k2 << endl;
		cout << "k3 " << k3 << endl;
		cout << "y " << y[i + 1] << endl;


	}

	return y;
}


std::vector<double> rk(double a, double b, double ya, double h) {
	auto y = RK::runge_kutta(a, b, ya, h, f);
	//auto y_ex = Y(nodes(a, b, h));

	//cout << "rk " << y[1] - y_ex[1] << ' ' << y[2] - y_ex[2] << ' ' << y[3] - y_ex[3] << endl;
	return y;
}


vector<double> adams_implicit(double a, double b, double ya, double h) {
	auto x = RK::nodes_step(a, b, h);
	//auto y = RK::runge_kutta(a, x[1], ya, h, f);
	auto y = first_nodes(x, ya);
	y.resize(2);
	for (size_t i = 1; i < x.size() - 1; i++) {
		double y_RK = RK::runge_kutta(x[i],x[i+1],y[i],h,f)[1];	
		cout << "RK i: " << i << ' ' << y_RK << endl;
		double y_impl = pc_implicit_node(h, x, y, y_RK, i);
		y.push_back(y_impl);
		cout << "implicit i: "<< y_impl << endl;
		//y.push_back(implicit_node(h,x,y,i));
	}

	auto y_ex = Y(x);

	cout << "adams " << y[3]<< ' ' << y[4]<< endl;// << ' ' << y[3] - y_ex[3] << endl;
	return y;
}



double init_val(int i) {

	return  ya + pow(10, -i) * 2.5;
}
