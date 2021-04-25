#include "ha_integral.h"

#include <iomanip>
#include <iostream>
using namespace std;

// cos(0.4 x) (x^5 - 5.2 x^3 + 5.5 x^2 - 7 x - 3.5)
// [a,b] - > [-1,1] thru (a + b) / 2 + x (b - a) / 2;
// x: -1, -sqrt(0.2) sqrt(0.2) 1
// A: 1/6, 5/6, 5/6, 1/6


vector<double> gl::nodes() {
	vector<double> res;
	res.push_back(1);
	res.push_back(sqrt(0.2));
	res.push_back(-sqrt(0.2));
	res.push_back(-1);
	reverse(res.begin(), res.end());
	return res;
}


vector<double> gl::Y(const double a,const double b, const vector<double>& x)
{
	vector<double> y;
	const auto c = (a + b) / 2;
	const auto k = (b - a) / 2;
	for (const auto& val:x)
	{
		const auto t = (c + k * val);
		y.push_back(cos(0.4 * t) * (pow(t, 5) - 5.2 * pow(t, 3)
									+ 5.5 * pow(t, 2) - 7 * t - 3.5) );
	}
	
	gauss_calls += x.size();
	return y;
}
	

vector<double> gl::YModCont(const double a, const double b, const vector<double>& x)
{
	vector<double> y;
	const auto c = (a + b) / 2;
	const auto k = (b - a) / 2;
	for (const auto& val : x)
	{
		const auto t = (c + k * val);
		y.push_back(cos(0.4 * t) * (pow(t, 4) + 1.25 * pow(t, 3) - 291.0/80 * pow(t, 2)
						+ 61.0/64 * t - 1487.0/256));
	}
	return y;
}




// n = 3,
// f = cos(0.4 x) (x - 1.25) (x^4 + ...) - 10.76 (x - 1.25)^3 / 4!
vector<double> gl::YModTail(const double a, const double b, const vector<double>& x)
{
	vector<double> y;
	const auto c = (a + b) / 2;
	const auto k = (b - a) / 2;
	for (const auto& val : x)
	{
		const auto t = (c + k * val);
		y.push_back(-11019.0/1024*(-0.4*sin(0.5) -0.08*cos(0.5)*(t-1.25) + 0.032/3*sin(0.5)*pow(t-1.25,2)));
	}
	return y;
}


double gl::elem_interval_integral(const vector<double>& y, const double a, const double b)
{
	return (b - a) / 2 * (y[0] + y[3] + 5 * (y[1] + y[2])) / 6;

}

vector<double> gl::linspace(double a, const double b, const int n)
{
	vector<double> res;
	const auto step = (b - a) / n;
	while (a <= b)
	{
		res.push_back(a);
		a += step;
	}
	return res;
}




vector<double> gl::gauss_lobato(const double eps, const double a, const double b)
{
	const auto x = nodes();
	auto y = Y(a, b, x);
	auto cur = elem_interval_integral(y,a,b);
	double prev = 0;
	int n = 1;
	//cout << "Iter: 0 " << scientific <<cur << endl;
	do  {
		n *= 2;
		prev = cur;
		auto intervals = linspace(a, b, n);
		cur = 0;
		for (auto i = 0; i < n; i++) {
			y = Y(intervals[i], intervals[i + 1], x);
			//for (auto val:y)
			//{
			//	cout << val << ' ';
			//}
			//cout << endl;
			auto elem_int = elem_interval_integral(y, intervals[i], intervals[i + 1]);
			//cout << "_" << scientific << elem_int << "_" << endl;
			cur += elem_int;
		}
		
		//cout << "Iter: " << log2(n) << ' ' << fixed << setprecision(8) << cur/*-exact_val*/ <<" " << (cur-prev)/63 << endl;

	} while (fabs(prev - cur) > 63 * eps); // p = 2 n - 2 = 6; 2^6 - 1
	//return { fabs(cur  - exact_val), log2(n) };
	double calls = gauss_calls;
	gauss_calls = 0;
	return { cur, log2(n), calls };
}



