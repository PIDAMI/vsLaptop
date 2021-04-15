#include "RK.h"

using namespace std;

vector<double> nodes_n(double a, double b, int n)
{
	vector<double> res;
	for (int i = 0; i <= n; i++)
	{
		res.push_back(a + (b - a) * i / n);
	}
	return res;
}

vector<double> nodes_step(double a, double b, double h)
{
	vector<double> res;
	int n = static_cast<int>((b - a) / h);
	for (int i = 0; i <= n; i++)
	{
		res.push_back(a);
		a += h;
	}
	

	return res;
}

//double f(double x, double y, double h, double alpha,  double beta, double k)
//{
//	 x += alpha * h;
//	 y += beta * h * k;
//	 return -y / (x + 1) - pow(y, 2);
//}


double f(double x, double y)
{

	 return -y / (x + 1) - pow(y, 2);
}

vector<double> Y(const vector<double>& x)
{
	vector<double> y;
	y.reserve(x.size());
	for (const auto& val:x)
	{
		y.push_back(1.0 / ((val + 1) * log(val + 1)));
	}
	return y;
}


vector<double> runge_kutta(double a, double b, double y_a, double h)
{
	vector<double> y;
	y.push_back(y_a);
	auto x = nodes_step(a, b, h);
	for (int i = 0; i < x.size()-1; i++)
	{
		double k1 = f(x[i], y[i]);
		double k2 = f(x[i] + h / 3, y[i] + h * k1 / 3);
		double k3 = f(x[i] + 2 * h / 3, y[i] + 2 * h * k2 / 3);
		y.push_back(y[i] + h / 4 * (k1 + 3 * k3));
	}

	return y;
}


double cheb_norm(const vector<double>& x, const vector<double>& y)
{
	auto cur = x.size() > y.size() ? x : y;
	auto prev = cur == x ? y : x;

	double max = fabs(prev[0] - cur[0]);
	for (size_t i = 1; i < prev.size(); i++)
	{
		double dif = fabs(prev[i] - cur[2*i]);
		if (max < dif)
			max = dif;
	}
	return max;
}


//         
// [a ... b]
double  elem_int(double eps, double a, double b, double y, int& iter)
{
	long long n = 1;
	double h = (b - a);

	double k1 = f(a, y);
	cout << "k1 " << k1 << endl;
	double k2 = f(a + h / 3, y + h * k1 / 3);
	cout << "k2 " << k2 << endl;
	double k3 = f(a + 2 * h / 3, y + 2 * h * k2 / 3);
	cout << "k3 " << k3 << endl;
	


	double y_cur = y + h / 4 * (k1 + 3 * k3);
	cout << "y_1 " << y_cur - Y({1.2})[0] << endl;
	double y_prev;
	//vector<double> y_cur_mid;
	do
	{

		double y_sub_cur = y;
		y_prev = y_cur;
		h /= 2;
		n *= 2;
		double x_0 = a;
		for (int i = 0; i < n; i++)
		{
			double y_sub_prev = y_sub_cur;
			k1 = f(x_0, y_sub_prev);
			cout << "k1_" << i << " " <<k1 << endl;

			k2 = f(x_0 + h / 3, y_sub_prev + h * k1 / 3);
			cout << "k2_" << i << " " << k2 << endl;

			k3 = f(x_0 + 2 * h / 3, y_sub_prev + 2 * h * k2 / 3);
			cout << "k3_" << i << " " << k3 << endl;

			x_0 += h;
			y_sub_cur = y_sub_prev + h / 4 * (k1 + 3 * k3);
			cout << "y_1_" << i << " " << y_sub_cur << endl;

		}
		y_cur = y_sub_cur;
		cout << "y_1 new " << y_cur - Y({ 1.2 })[0] << endl;
		cout << "dy " << (y_cur - y_prev) / 7;
		if (n == 2)
			exit(1);
	} while (fabs(y_cur - y_prev) > 7 * eps);

	if (log2(n) > iter) {
		iter = static_cast<int>(log2(n));
		cout << "max iter: "<< max_iter << endl;
	}
		
	return y_cur /*+ fabs(y_cur - y_prev)/7*/;
}


vector<double> eps_runge_kutta(double a, double b, double y_a, double eps, double h, int& iter)
{
	vector<double> y;
	y.push_back(y_a);
	double sub_h = h;
	auto x = nodes_step(a, b, h);
	//max_iter = 1;
	//vector<double> x;

	//do
	//{
	//	//auto cur = elem_int(eps, x_prev, x_cur, y[y.size() - 1]);
	//	
	//	//y.resize(y.size() - 1);
	//	//y.insert(y.end(), cur.begin(), cur.end());
	//} while (x_cur <= b);
	for (size_t i = 0; i < x.size() - 1;i++)
	{
		y.push_back(elem_int(eps, x[i], x[i + 1], y[i], iter));
	}
	
	/*cout << "y.size: " << y.size() << " cur.size(): " << cur.size() << endl;
	for (auto i = 0; i < y.size(); i++)
	{
		cur[i] = fabs(cur[i] - y[i]);
	}*/

	//cout << "iter: " << max_iter << endl;
	return y;
}



double init_val(int i) {
	return  ya + rand() * pow(10, -i);
}