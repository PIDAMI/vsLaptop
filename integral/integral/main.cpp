#pragma warning(disable:4996)
#include <stdlib.h>
#include "integral.h"
using namespace std;
using namespace nk;


int main(int argc, char** argv) {
	

	int n = 5;// 12 - max
	int action = 1;// 1 - iterations, 2 - fact_error, 3 - max/min theoretical error
	if (argc > 1)
		action = static_cast<int>(atoi(argv[1]));
	if (argc > 2)
		n = static_cast<int>(atoi(argv[2]));

	fstream file("d.txt");
	FILE* fp = fopen("d.txt","w");
	if (!fp) {
		cout << "file not found";
		exit(1);
	}


	nk::trap(0.01, A, B, Y_A, Y_B, action);

	return 0;


	vector<double> actual, max, min;
	for (int i = 0; i < n; i++) {
		double eps = pow(10, - i - 1);
		if (action == 1)
			fprintf(fp, "%d ", static_cast<int>(log2(*trap(eps, A, B, Y_A, Y_B, action).begin())));
		else if (action == 2)
			fprintf(fp, "%.5le ", *trap(eps, A, B, Y_A, Y_B, action).begin());
		else {
			vector<double> res = trap(eps, A, B, Y_A, Y_B, action);
			min.push_back(res[0]);
			max.push_back(res[1]);
			actual.push_back(res[2]);
		}
	}
	if (action == 3) {
		for (auto& val:min)
			fprintf(fp, "%.5le ", val);	
		for (auto& val : max)
			fprintf(fp, "%.5le ", val);
		for (auto& val : actual)
			fprintf(fp, "%.5le ", val);
	}



	
	fclose(fp);
	return 0;
}