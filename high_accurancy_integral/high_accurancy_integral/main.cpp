#include "ha_integral.h"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;


int main(int argc, char** argv) {

	//      
	int n = 8;
	int action = 2;// 1 - iterations, 2 - fact_error
	if (argc > 1)
		action = static_cast<int>(atoi(argv[1]));
	if (argc > 2)
		n = static_cast<int>(atoi(argv[2]));

	ofstream file("d.txt");

	gauss_lobato(0.01, _a, _b);
	return 0;



	for (auto i = n - 1; i < n; i++) {
		double eps = pow(10, - i - 1);
		auto res = gauss_lobato(eps, _a, _b);
		if (action == 1)
			file << res[1] << ' ';
		else if (action == 2)
		{
			file.setf(ios::scientific);
			file << res[0] << ' ';
		}
	}

	
	return 0;
}
