#include <iostream>
#include "ha_integral.h"
#include "integral.h"
using namespace std;

vector<double> newton_kotes(double eps, double a, double b) {
	auto y = nk::Y({ a,b });
	return nk::trap(eps, a, b, y[0], y[1], 0);
}


int main(int argc, char** argv) {
	const double a = gl::_a;
	const double b = gl::_b;
	
	
	int n = 13;
	int action = 3; // 1 - iterations, 2 - fact_error, 3 - y calls
	int method = 2; // 1 - gauss, 2 - newton
	if (argc > 1)
		action = atoi(argv[1]);
	if (argc > 2)
		n = atoi(argv[2]);
	if (argc > 3)
		method = atoi(argv[3]);
	
	vector<double> (*solver) (double, double, double);
	

	if (method == 1)
		solver = gl::gauss_lobato;
	else
		solver = newton_kotes;



	

	ofstream file("d.txt");
	



	for (auto i = 1; i <= n; i++) {
		double eps = pow(10, -i);
		auto res = solver(eps, a, b);
		if (action == 1) {
			file << res[1] << ' ' ;
		}
		else if (action == 2)
		{
			file.setf(ios::scientific);
			file << abs(res[0] - gl::exact_val) << ' ';
		}
		else if (action == 3) {
			file << res[2] << ' ';
		}
		cout << "iter: " << pow(2, res[1]) << ' ' << "calls: " << res[2] << endl;
	}

	
	return 0;
}

