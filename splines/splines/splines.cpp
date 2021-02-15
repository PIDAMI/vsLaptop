#include "splines.h"

using namespace std;
//
//vector<double> thomas(vector <double> diag, vector<double> up, vector<double> down, vector<double> rhs) {
//	vector <double> res;
//	vector <double> k;
//	vector <double> b;
//	k[0]=(-up[0] / diag[0]);
//	b[0]=(rhs[0] / diag[0]);
//	size_t n = diag.size();
//	for (int i = 1; i < n-1; i++) {
//		k[i] = -up[i] / (down[i] * k[i - 1] + diag[i]);
//		b[i] = (rhs[i] - down[i] * b[i - 1]) / (down[i] * k[i - 1] + diag[i]);
//	}
//	k[n - 1] = 0;
//	b[n-1] = (rhs[n-1] - down[n - 1] * b[n - 2]) / (down[n - 1] * k[n - 2] + diag[n - 1]);
//	res[n-1] = b[n - 1];
//	for (int i = n - 2; i >= 0; i++) {
//		res[i] = k[i] * res[i + 1] + b[i];
//	}
//
//	return res;
//}