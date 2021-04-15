#pragma warning(disable:4996)
#include <stdlib.h>
#include "integral.h"
using namespace std;



int main(int argc, char** argv) {
	
	//double a = 0.5;
	//double b = 2.0;


	//long n = 1;
	//double H = b - a;
	//double I_trap_prev, I_trap_next;
	//I_trap_next = H / 2 * (Y_A + Y_B);
	//double I_rect;
	//vector <double> x;
	//vector <double> y;
	//printf("x0 = %lf, x1 = %lf\n", a, b);
	//printf("y0 = %lf, y1 = %lf\n", Y_A, Y_B);
	//printf("1: %lf\n\n", I_trap_next);
	//do {
	//	I_trap_prev = I_trap_next;
	//	x = nodes(a, b, n, H);
	//	y = Y(x);
	//	I_rect = H * rect_sum(y);
	//	H /= 2;
	//	n *= 2;
	//	I_trap_next = (I_rect + I_trap_prev) / 2;

	//	print(x);
	//	printf("\n");
	//	print(y);
	//	printf("\n%d %lf\t%lf\n\n", n, I_trap_next- exact_val, (I_trap_next-I_trap_prev)/3);
	//} while (n < 4);





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


	trap(0.01, A, B, Y_A, Y_B, action);

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