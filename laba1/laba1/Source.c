#include "Header.h"

// ��������� ���������������� ������� ������ � ������ ��������
// x_0,x_n - ������� ���������, x,y,yDer - �������� �������� � �����(n+1 ����)
// n - ���-�� �����
// x_eval - �����, � ������� ����������� �������, density - �� ���-��
// ���������� density �������� �������� � ���������(�������� ���������� �����������)
double* HermInterChebNet(double x_0, double x_n, int n, double* x, double* y, double* yDer, int density, double* x_eval) {
	double total = 0;
	double quad_prod = 1;
	double lagr_sum = 0;
	double single_term = 0;
	double* result = (double*)calloc(density + 1, sizeof(double));
	if (result == NULL) {
		printf("not enough mmry\n");
		return NULL;
	}

	if (x_0 >= x_n) {
		printf("x_0>=x_n\n");
		return NULL;
	}
	if (n <= 0) {
		printf("n<=0\n");
		return NULL;
	}
	for (int q = 0; q <= density; q++) {
		for (int i = 0; i <= n; i++) {
			single_term = (x_eval[q] - x[i]) * yDer[i];
			for (int j = 0; j <= n; j++) {
				if (i != j) {
					lagr_sum += (x_eval[q] - x[i]) / (x[i] - x[j]);
				}
			}
			for (int k = 0; k <= n; k++) {
				if (i != k) {
					quad_prod *= pow((x_eval[q] - x[k]) / (x[i] - x[k]), 2);
				}
			}
			total += (single_term + (1 - 2 * lagr_sum) * y[i]) * quad_prod;
			single_term = 0;
			lagr_sum = 0;
			quad_prod = 1;
		}
		result[q] = total;
		total = 0;
	}

	/*double* y_eval = Y(density, x_eval);
	for (int i = 0; i <= density; i++) {
		result[i] -= y_eval[i];
	}*/


	return result;
}

//3.12
double* Nodes(int n, double a, double b) {
	double* x = (double*)calloc((n + 1), sizeof(double));
	for (int i = 0; i <= n; i++) {
		x[i] = (a + b) / 2 + 
			(b - a) / 2 * pow(cos(PI * (2 * i + 1) / (2 * n + 2)), 1) ;
		
	}
	return x;
}

double* NodesMod(int n, double a, double b) {
	double* x = (double*)calloc((n + 1), sizeof(double));
	for (int i = 0; i <= n; i++) {
		x[i] = (a + b) / 2 +
			(b - a) / 2 * pow(cos(PI * (2 * i + 1) / (2 * n + 2)), 1)
			- (b - a) /  12 * i * i/ n / n / n /n;
			;

	}
	return x;
}
//- (b - a) / 15 * i * i / n / n / n /n;

double* Y(int n, double* x) {
	double* y = (double*)calloc((n + 1), sizeof(double));
	for (int i = 0; i <= n; i++) {
		y[i] = tan(x[i] / 2 + 0.2) - pow(x[i], 2);
	}

	return y;
}

double* YDer(int n, double* x) {
	double* y = (double*)calloc((n + 1), sizeof(double));
	for (int i = 0; i <= n; i++) {
		y[i] = 0.5 / pow(cos(x[i] / 2 + 0.2), 2) - 2 * x[i];
	}

	return y;
}

double* linspaces(int n, double x_0, double x_n) {
	double* y = (double*)calloc(n + 1, sizeof(double));
	for (int i = 0; i <= n; i++) {
		y[i] = x_0 + (x_n - x_0) * (double)i / (double)n;
	}

	return y;
}


void UnMod(double*x,double*y,double*yDer,int n, int density, double*y_eval,double*x_eval,FILE*ffp ) {
	int i;
	for (i = 0; i <= n; i++)
		fprintf(ffp, "%lf ", x[i]);
	double* y_eval_node = HermInterChebNet(X0, XN, n, x, y, yDer, n, x);
	for (i = 0; i <= n; i++)
		fprintf(ffp, "%lf ", y[i] - y_eval_node[i]
		);
	for (i = 0; i <= density; i++)
		fprintf(ffp, "%lf ", x_eval[i]);
	fprintf(ffp, "\n");
	double* y_exact = Y(density, x_eval);
	for (i = 0; i <= density; i++)
		fprintf(ffp, "%lf ", y_eval[i] - y_exact[i]
		);
}


void Mod(double* xMod, double* yMod, double* yDerMod, int n, int density, double* y_eval_mod, double* x_eval2, FILE* ffp) {
	int i;
	for (i = 0; i <= n; i++)
		fprintf(ffp, "%lf ", xMod[i]);
	double* y_eval_nodeMod = HermInterChebNet(X0, XN, n, xMod, yMod, yDerMod, n, xMod);
	for (i = 0; i <= n; i++)
		fprintf(ffp, "%lf ", yMod[i]//- y_eval_nodeMod[i]
		); 
	for (i = 0; i <= density; i++)
		fprintf(ffp, "%lf ", x_eval2[i]);
	fprintf(ffp, "\n");
	double* y_exact2 = Y(density, x_eval2);
	for (i = 0; i <= density; i++)
		fprintf(ffp, "%.15le ", y_eval_mod[i]//- y_exact2[i]
		);
}


void MaxErrUnMod(double* x, double* y, double* yDer, int n, int density, double* y_eval, double* x_eval, FILE* ffp) {
	int i;
	/*for (i = 0; i <= n; i++)
		fprintf(ffp, "%lf ", x[i]);
	double* y_eval_node = HermInterChebNet(X0, XN, n, x, y, yDer, n, x);
	for (i = 0; i <= n; i++)
		fprintf(ffp, "%lf ", y[i] - y_eval_node[i]
		);
	for (i = 0; i <= density; i++)
		fprintf(ffp, "%lf ", x_eval[i]);
	fprintf(ffp, "\n");
	*/
	double* y_exact = Y(density, x_eval);
	double mx = 0;
	for (i = 0; i <= density; i++) {
		if (fabs(y_eval[i] - y_exact[i]) > mx)
			mx = fabs(y_eval[i] - y_exact[i]);
	}
	fprintf(ffp, "%.15le ", mx);

	
}

void MaxErrMod(double* xMod, double* yMod, double* yDerMod, int n, int density, double* y_eval_mod, double* x_eval2, FILE* ffp) {
	int i;
	//for (i = 0; i <= n; i++)
	//	fprintf(ffp, "%lf ", xMod[i]);
	//double* y_eval_nodeMod = HermInterChebNet(X0, XN, n, xMod, yMod, yDerMod, n, xMod);
	//for (i = 0; i <= n; i++)
	//	fprintf(ffp, "%lf ", yMod[i]//- y_eval_nodeMod[i]
	//	);
	//for (i = 0; i <= density; i++)
	//	fprintf(ffp, "%lf ", x_eval2[i]);
	//fprintf(ffp, "\n");
	double* y_exact2 = Y(density, x_eval2);
	double mx = 0;
	for (i = 0; i <= density; i++) {
		if (fabs(y_exact2[i] - y_eval_mod[i]) > mx)
			mx = fabs(y_exact2[i] - y_eval_mod[i]);
	}
	fprintf(ffp, "%.15le ", mx);
}

int main(int argc, char** argv)
{
	
	int i;
	int n = 3;
	if (argc > 1)
		n = atoi(argv[1]);
	double* x = Nodes(n, X0, XN);
	double* xMod = NodesMod(n, X0, XN);
	double* y = Y(n, x);
	double* yMod = Y(n, xMod);
	double* yDer = YDer(n, x);
	double* yDerMod = YDer(n, xMod);
	

	FILE* ffp = fopen("d.txt", "w");
	if (ffp == NULL) {
		perror("file not FOUnd; ");
		return -2;
	}
	
	
		int density = (XN - X0) / STEP_EVAL; // step_eval % 10 = 0


		double* x_eval = linspaces(density, X0, XN);
		double* x_eval2 = linspaces(density, X0, XN);
		double* y_eval = HermInterChebNet(X0, XN, n, x, y, yDer, density, x_eval);
		double* y_eval_mod = HermInterChebNet(X0, XN, n, xMod, yMod, yDerMod, density, x_eval2);
		if (y_eval == NULL) {
			printf("smth went wrong");
			return -1;
		}



		/*double* xMid = (double*)calloc(n, sizeof(double));
		for (int i = 0; i < n; i++) {
			xMid[i] = (xMod[i] + xMod[i + 1]) / 2;
		}
		double* yMid = HermInterChebNet(X0, XN, n, xMod, yMod, yDerMod, n - 1, xMid);
		double* yMid_exact = Y(n - 1, xMid);
		for (int i = 0; i < n; i++) {
			printf("x%d=%lf\t dy%d=%lf\n", i, xMid[i], i, yMid[i]-yMid_exact[i]);
		}*/

		//UnMod(x, y, yDer, n, density, y_eval, x_eval, ffp);
		//Mod(xMod, yMod, yDerMod, n, density, y_eval_mod, x_eval2, ffp);
		MaxErrMod(xMod, yMod, yDerMod, n, density, y_eval_mod, x_eval2, ffp);
		MaxErrUnMod(x, y, yDer, n, density, y_eval, x_eval, ffp);

	
	fclose(ffp);
	free(x_eval);
	free(y_eval);
	free(x);
	free(y);
	free(yDer);
	



	


	return 0;
}





