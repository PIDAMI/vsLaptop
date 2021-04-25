//#include "Header.h"
//
//
//int main(int argc, char** argv)
//{
//
//	int i = 0;
//	int n = 3;
//	if (argc > 1)
//		n = atoi(argv[1]);
//	double* x = Nodes(n, X0, XN);
//	double* xMod = NodesMod(n, X0, XN);
//	double* y = Y(n, x);
//	double* yMod = Y(n, xMod);
//	double* yDer = YDer(n, x);
//	double* yDerMod = YDer(n, xMod);
//
//
//	FILE* ffp = fopen("d.txt", "w");
//	if (ffp == NULL) {
//		perror("file not FOUnd; ");
//		return -2;
//	}
//
//
//	int density = (XN - X0) / STEP_EVAL; // step_eval % 10 = 0
//
//
//	/*double* x_eval = linspaces(density, X0, XN);
//	double* x_eval2 = linspaces(density, X0, XN);
//	*/
//	double* x_eval = mid_node(x, n - 1);
//	double* x_eval2 = mid_node(xMod, n - 1);
//	double* y_eval = HermInterChebNet(X0, XN, n, x, y, yDer, n - 1, x_eval);
//	double* y_eval_mod = HermInterChebNet(X0, XN, n, xMod, yMod, yDerMod, n - 1, x_eval2);
//	if (y_eval == NULL) {
//		printf("smth went wrong");
//		return -1;
//	}
//
//
//
//	/*double* xMid = (double*)calloc(n, sizeof(double));
//	for (int i = 0; i < n; i++) {
//		xMid[i] = (xMod[i] + xMod[i + 1]) / 2;
//	}
//	double* yMid = HermInterChebNet(X0, XN, n, xMod, yMod, yDerMod, n - 1, xMid);
//	double* yMid_exact = Y(n - 1, xMid);
//	for (int i = 0; i < n; i++) {
//		printf("x%d=%lf\t dy%d=%lf\n", i, xMid[i], i, yMid[i]-yMid_exact[i]);
//	}*/
//
//
//	UnMod(x, y, yDer, n, n - 1, y_eval, x_eval, ffp);
//	Mod(xMod, yMod, yDerMod, n, n - 1, y_eval_mod, x_eval2, ffp);
//	//MaxErrMod(xMod, yMod, yDerMod, n, density, y_eval_mod, x_eval2, ffp);
//	//MaxErrUnMod(x, y, yDer, n, density, y_eval, x_eval, ffp);
//
//
//	fclose(ffp);
//	free(x_eval);
//	free(y_eval);
//	free(x);
//	free(y);
//	free(yDer);
//
//
//
//
//
//
//
//	return 0;
//}
//
//
//
//
//
