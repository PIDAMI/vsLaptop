//#include <iostream>
//#include "RK.h"
//#include <math.h>
//#include <iomanip>
//using namespace std;
// 
//
//double f(double x, double y);
//
// 
//
//typedef double (*PF)(double, double);
//
// 
//
//vector<double> RK4(PF f, double x0, double y0, double x, const int n);
//
// 
//
//vector<double> RK4_eps(PF f, double x0, double y0, double x, double eps);
//
// 
//
//int main() {
//
//	 
//
//		double x0, x, eps, y0; PF pf; int n;
//
//	 
//
//		//cout << "\n x0 = "; cin >> x0; cout << "\n y0 = "; cin >> y0;
//		x0 = a;
//		y0 = ya;
//
//	 
//
//		cout << "\n n = "; cin >> n; cout << "\n x = "; cin >> x;
//
//	 
//
//		pf = f;
//		auto y1 = RK4(pf, x0, y0, x, n);
//
//	
//		auto exact = Y({5});
//
//		cout << "\n n = " << n << " y(" << x << ") = " << std::scientific << y1[y1.size()-1]-exact[exact.size()-1];
//
//	 
//
//		cout << "\n eps = "; cin >> eps;
//
//	 
//
//		auto y2 = RK4_eps(pf, x0, y0, x, eps);
//
//	 
//
//		cout << "\n eps = " << eps << " y(" << x << ") = " <<std::scientific<<y2[y2.size()-1] - exact[exact.size() - 1];
//
//	 
//
//		return 0;
//
//	 
//
//}
//
// 
//
//double f(double x, double y) {
//
//	 
//
//		double r; r = -y/(x+1)-pow(y,2);
//
//	 
//
//		return r;
//
//	 
//
//}
//
// 
//
//vector<double> RK4(PF f, double x0, double y0, double x, const int n) {
//
//	 
//
//		double h, k1, k2, k3, k4, y1, y2; int i;
//
//	 
//		vector<double> res;
//		h = (x - x0) / n; y1 = y0;
//
//		res.push_back(y1);
//
//		for (i = 1; i <= n; i++) {
//			k1 = f(x0, y1); 
//			k2 = f(x0 + h / 2, y1 + h * k1 / 2);
//			k3 = f(x0 + h / 2, y1 + h * k2 / 2); 
//			k4 = f(x0 + h, y1 + h * k3);
//
//			y2 = y1 + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
//			x0 = x0 + h; 
//			y1 = y2;
//			res.push_back(y1);
//		}
//
//	return res;
//
//	 
//
//}
//
// 
//
//vector<double> RK4_eps(PF f, double x0, double y0, double x, double eps) {
//
//
//
//	typedef double (*PY)(double, double);
//
//
//
//	double erry, yh, y2h; int n; PY py;
//
//	vector<double> res_h;
//	vector<double> res_2h;
//
//
//	n = 2;
//	py = f;
//	res_2h = RK4(py, x0, y0, x, n);
//
//
//
//	do {
//		n = 2 * n; 
//		res_h = RK4(py, x0, y0, x, n); 
//		erry = (yh - y2h) / 7;
//		erry = cheb_norm(res_h, res_2h);
//
//
//		res_2h = res_h;
//	} while (fabs(erry) > eps);    
//	
//
//
//
//
//	return res_h;
//}
//
//
//
