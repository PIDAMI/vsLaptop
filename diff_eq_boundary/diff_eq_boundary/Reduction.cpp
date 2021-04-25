#include "RK.h"
#include "Reduction.h"


Vector f_heterogen(double x, double y, double z) {
	return {
		z,
		pow(x,5) + 2 * x * x + 2 - x * z - y * x * x * x
	};
}


Vector f_homogen(double x, double y, double z) {
	return {
		z,
		- x * z - y * x * x * x
	};
}

Vector Y(const Vector& x) {
	Vector res;
	for (const auto& i : x) {
		res.push_back(i * i);
	}
	return res;
}
Vector nodes(double a, double b, double h) {
	Vector res;
	long n = lround((b - a) / h);
	for (long i = 0; i <= n; i++) {
		res.push_back(a + i * h);
	}


	return res;
}
std::vector<Vector> runge_kutta(double a, double b, double h, double ya, double yya,
					Vector (*eval)(double,double,double)) {
	Vector y, yy;
	y.push_back(ya);
	yy.push_back(yya);
	auto x = nodes(a, b, h);

	for (int i = 0; i < x.size() - 1; i++)
	{
		auto k1 = eval(x[i], y[i], yy[i]);
		auto k2 = eval(x[i] + h / 3, y[i] + h * k1[0] / 3, yy[i] + h * k1[1] / 3);
		auto k3 = eval(x[i] + 2 * h / 3, y[i] + 2 * h * k2[0] / 3, yy[i] + 2 * h * k2[1] / 3);
		y.push_back(y[i] + h / 4 * (k1[0] + 3 * k3[0]));
		yy.push_back(yy[i] + h / 4 * (k1[1] + 3 * k3[1]));

		std::cout << "k1 " << k1[0] << ' ' <<  k1[1] <<std::endl;
		std::cout << "k2 " << k2[0] << ' ' << k2[1] << std::endl;
		std::cout << "k3 " << k3[0] << ' ' << k3[1] << std::endl;
		std::cout << "y " << y[i + 1] << std::endl;
		std::cout << "y\' " << yy[i + 1] << std::endl;

	}
	std::vector<Vector> res = {y,yy};

	return res;



}


Vector reduction(double a, double b, double h, 
				const Vector& alpha, const Vector& beta, double A, double B) {
	Vector res;
	double ua, uua;
	double va, vva;

	va = -alpha[1];
	vva = alpha[0];
	if (!alpha[1]) {
		ua = A / alpha[0];
		uua = 0;
	}
	else {
		uua = A / alpha[1];
		ua = 0;
	}
	std::cout << "U: " << std::endl;
	auto U = runge_kutta(a, b, h, ua, uua, f_heterogen);
	std::cout << "V: " << std::endl;
	auto V = runge_kutta(a, b, h, va, vva, f_homogen);
	Vector u = U[0];
	Vector uu = U[1];
	Vector v = V[0];
	Vector vv = V[1];

	double C = ((B - beta[0] * u[u.size() - 1] - beta[1] * uu[uu.size() - 1])
		/ (beta[0] * v[v.size() - 1] + beta[1] * vv[vv.size() - 1]));
	std::cout <<  "C " << C << std::endl;
	for (int i = 0; i < u.size(); i++) {
		res.push_back(u[i] + C * v[i]);
		std::cout << "y" << i << ' ' <<res[i] << std::endl;
	}
	

	return res;
}



double init_val(double ex, int i) {
	return ex + pow(10, -i);
}