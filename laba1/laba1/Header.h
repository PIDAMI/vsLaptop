#pragma once
#ifndef __HEADER__
#define __HEADER__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define FILE_NOT_FOUND 1;

double VectorNorm2(double* vector, int k);
double abs1(double a);
#endif // !__HEADER__
/*
#include "Header.h"
// back to c for callocs to work properly
// simple iteration method for 3rd lab
// infinite norm used everywhere
typedef struct {
		double matrix[10][10];
		double vector[10];
} augmented_matrix;

typedef struct {
	double matrix[10][10];
} mtr;

double abs1(double a) {
	if (a > 0) {
		return a;
	}
	else {
		return -a;
	}
}

void NthVectorFromMatrix(double* vector, mtr mat, int n) {
	// fills vector w/ elements from nth column of mat
	for (int i = 0; i < 10; i++) {
		vector[i] = mat.matrix[i][n];
	}
	return;
}

double VectorNormInf(double* vector) {
	double max = vector[0];
	for (int i = 0; i < 10; i++) {
		if (abs1(vector[i]) > abs1(max)) {
			max = vector[i];
		}
	}
	return abs1(max);
}
double* LinearCombVectors(double* v1, double* v2, double a1, double a2) {
	// allocates memory and returns linear combination of v1 and v2
	double* sum = (double*)calloc(10, sizeof(double));
	for (int i=0; i < 10; i++) {
		sum[i] = a1 * v1[i] + a2 * v2[i];
	}

	return sum;
}

mtr BuildHouseholderMatrixNRow(double* a, int n) {
	// nth Housholder matrix in 10d
	double sign = 0;
	if (a[n] > 0) {
		sign = -1;
	}
	else {
		sign = 1;
	}
	double s1 = sign * VectorNorm2(a,n);
	printf("%lf\n",s1);
	double n1 = 1 /  sqrt(2*s1 * (s1 - a[n]));
	double* a1 = (double*)calloc(10, sizeof(double));
	for (int i = n; i < 10; i++) {
		a1[i] = n1 * a[i];
	}
	a1[n] -= n1 * s1;
	mtr m = {0}; // 3 taken as an example
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			if (i == j) {
				 m.matrix[j][i] = 1 - 2 * a1[i] * a1[j];
			}
			else {
				m.matrix[i][j] = m.matrix[j][i] = - 2 * a1[i] * a1[j];

			}
		}
	}
	free(a1);
	return m;
}

double VectorNorm2(double* vector, int k) {	// inf norm for 10d vector
	double sum = 0;							// starting from kth element
	for (int i = k; i < 10; i++) {
		sum += pow(vector[i], 2);
	}
	return sqrt(sum);
}

void UnitariseVector(double* vector) {
	double norm = VectorNorm2(vector,0);
	for (int i = 0; i < 10; i++) {
		vector[i] = vector[i] / norm;
	}
	return;
}

mtr MatrixProduct(mtr m1, mtr m2) { // for 10x10 matrices
	mtr m = { 0 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				m.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
			}
		}
	}

	return m;
}

void RightSideProduct(mtr m, double* b) {
	double* b1 = (double*)calloc(10, sizeof(double));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			b1[i] += b[j] * m.matrix[i][j];
		}
	}
	for (int i = 0; i < 10; i++) {
		b[i] = b1[i];
	}
	free(b1);
	return;
}

void PrintMatrix(mtr m) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%8.1lf",m.matrix[i][j]);
		}
		printf("\n");
	}
	return;
}

double SolveSystem(mtr m, double* b,double* X) {
	// X - analitycal solution; returns relative error
	double* x = (double*)calloc(10, sizeof(double));
	double sum = 0;
	for (int i = 9; i > -1; i--) {
		for (int j = 0; j < 10; j++) {
			sum += x[j] * m.matrix[i][j];
		}
		x[i] = (b[i] - sum) / m.matrix[i][i];
		sum = 0;
	}
	for (int i = 0; i < 10; i++) {
		printf("x%d = %.8lf\n", i, x[i]);
	}
	double* tmp = (double*)calloc(10, sizeof(double));
	for (int i = 0; i < 10; i++) {
		tmp[i] = X[i] - x[i]; // tmp = X - x;
	}
	for (int i = 0; i < 10; i++) {
		printf("xDelta%d = %le\n", i, tmp[i]);
	}
	double delta = VectorNormInf(tmp);
	printf("ABSOLUTE ERROR IN SOLUTION = %le\n", delta);
	delta = delta / VectorNormInf(x);
	printf("relative ERROR IN SOLUTION = %.6lf\n", delta);
	free(x);
	free(tmp);
	return delta;
}

	int main(void)
	{
		double b1[10] = { 0 };
		double* X = (double*)calloc(10, sizeof(double));//analytical solution
		double* v1 = (double*)calloc(10, sizeof(double));//tmp variable
		double b[10] = { 0 };
		mtr hm = { 0 };
		mtr m = { 0 };
		FILE* fp = fopen("dataz.txt", "r");
		if (fp == NULL) {
			printf("no file");
			return 0;
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				fscanf(fp, "%lf", &m.matrix[i][j]);
			}
		}
		for (int i = 0; i < 10; i++) { // right hand side
			fscanf(fp, "%lf", b + i);
		}
		for (int i = 0; i < 10; i++) { // analytical solution
			fscanf(fp, "%lf", X + i);
		}
		printf("INITIAL MATRIX\n");
		PrintMatrix(m);



		double bb[28] = { 0 };
		double xx[28] = { 0 };
		double deltab1[10] = { 0 };
		for (int q = 0; q < 28; q++) {

			for (int i = 0; i < 10; i++) { // right hand side
				fscanf(fp, "%lf", b1 + i);
			}
			for (int i = 0; i < 10; i++) {
				//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
				deltab1[i] = b1[i] - b[i]; // b1 = b - b1
			}
			double bdif1 = VectorNormInf(deltab1) / VectorNormInf(b);
			bb[q] = bdif1;
			//mtr m1, m2, m3, m4, m5, m6, m7, m8;
			//m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m;
			mtr m1 = m;
			for (int i = 0; i < 9; i++) {
				NthVectorFromMatrix(v1, m1, i);
				hm = BuildHouseholderMatrixNRow(v1, i);

				m1 = MatrixProduct(hm, m1);
				printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
				PrintMatrix(m1);
				RightSideProduct(hm, b1);				//CHANGE THIS
			}
			double xdif1 = SolveSystem(m1, b1, X); // relative error in x
			xx[q] = xdif1;
		}

		int z = 0;
		double tmp = xx[0];
		for (int i = 0; i < 28; i++) {
			tmp = xx[i];
			z = 0;
			for (int j = i; j < 28; j++) {
				if (xx[j] < tmp) {
					tmp = xx[j];
					z = j;
				}
			}
			xx[z] = xx[i];
			xx[i] = tmp;
			tmp = bb[z];
			bb[z] = bb[i];
			bb[i] = tmp;

		}

		fclose(fp);

		printf("relative right side = %.6lf\n", bb[0]);
		FILE* ffp = fopen("d.txt", "w");
		if (ffp == NULL) {
			perror("file not FOUnd; ");
			return 0;
		}
		for (int i =0; i< 28; i++)  fprintf(ffp, "%.4lf ", xx[i]);
		fprintf(ffp,"\n b's \n");
		for (int i = 0; i < 28; i++)  fprintf(ffp, "%.4lf ", bb[i]);
		//fwrite(xx, sizeof(double), 8, ffp);
		//fwrite(bb, sizeof(double), 8, ffp);


		//double deltab2[10] = { 0 };
		//double deltab3[10] = { 0 };
		//double deltab4[10] = { 0 };
		//double deltab5[10] = { 0 };
		//double deltab6[10] = { 0 };
		//double deltab7[10] = { 0 };
		//double deltab8[10] = { 0 };


		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab2[i] = b2[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab3[i] = b3[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab4[i] = b4[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab5[i] = b5[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab6[i] = b6[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab7[i] = b7[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab8[i] = b8[i] - b[i]; // b1 = b - b1
		//}




		//printf("INITIAL MATRIX\n");
		//PrintMatrix(m);
		//mtr m1, m2, m3, m4, m5, m6, m7, m8;
		//m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m;
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m1, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);
		//
		//	m1 = MatrixProduct(hm, m1);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i+1);
		//	PrintMatrix(m1);
		//	RightSideProduct(hm, b1);				//CHANGE THIS
		//	}
		//
	
		//
		//}
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m6, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);

		//	m6 = MatrixProduct(hm, m6);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
		//	PrintMatrix(m);
		//	RightSideProduct(hm, b6);				//CHANGE THIS

		//}
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m7, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);

		//	m7 = MatrixProduct(hm, m7);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
		//	PrintMatrix(m);
		//	RightSideProduct(hm, b7);				//CHANGE THIS
		//
		//}
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m8, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);

		//	m8 = MatrixProduct(hm, m8);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
		//	PrintMatrix(m);
		//	RightSideProduct(hm, b8);				//CHANGE THIS

		//}

		//
		
		//bb[7] = bdif8;
		//double tmp = xx[0];
		//for (int i = 0; i < 8; i++) {
		//	for (int j = i; j < 8; j++) {
		//		if (xx[j] < tmp) {
		//			tmp = xx[j];
		//		}
		//	}
		//	xx[i] = tmp;
		//}
		//tmp = bb[0];
		//for (int i = 0; i < 8; i++) {
		//	for (int j = i; j < 8; j++) {
		//		if (bb[j] < tmp) {
		//			tmp = bb[j];
		//		}
		//	}
		//	bb[i] = tmp;
		//}
		//fwrite(bb, sizeof(double), 8, fp);





	/*	fprintf(fp, "%.6lf\n", xdif1);
		fprintf(fp, "%.6lf\n", bdif1);
		fprintf(fp, "%.6lf\n", xdif2);
		fprintf(fp, "%.6lf\n", bdif2);
		fprintf(fp, "%.6lf\n", xdif3);
		fprintf(fp, "%.6lf\n", bdif3);
		fprintf(fp, "%.6lf\n", xdif4);
		fprintf(fp, "%.6lf\n", bdif4);
		fprintf(fp, "%.6lf\n", xdif5);
		fprintf(fp, "%.6lf\n", bdif5);
		fprintf(fp, "%.6lf\n", xdif6);
		fprintf(fp, "%.6lf\n", bdif6);
		fprintf(fp, "%.6lf\n", xdif7);
		fprintf(fp, "%.6lf\n", bdif7);
		fprintf(fp, "%.6lf\n", xdif8);
		fprintf(fp, "%.6lf\n", bdif8);
free(v1);
free(X);
fclose(ffp);
// cond:110.2
// B: 0.034461 0.061604 0.074746 0.097194 0.105683 0.11052 0.11257 0.144028 0.161936 0.177552 
// X: 0.004113 0.030688 0.088248 0.027153 0.136235 0.03199 0.06053 0.155606  0.264554 0.145667
//cond:2200.1423
//B 0.012942 0.030365 0.040274  0.050047 0.052881 0.065385 0.078282 0.089558  0.122537 0.143625 0.199816 
//X 0.049852 0.052336 0.00085  0.110045 0.081354  0.034151 0.078127 0.391321  0.190288 0.148614 0.217223

// cond:430020.321
// B 0.009859 0.028721 0.035505 0.053864 0.0987893 0.163110
// X 0.060896 0.214451 0.187440 0.054033 0.096465 0.145085


//double a[3] = { 4.0,10.0,7.0 };
//mtr mm;
//mm.matrix[0][0] = 4;
//mm.matrix[0][1] = 3;
//mm.matrix[0][2] = 12;		// 4 3 12
//mm.matrix[1][0] = 10;		// 10 5 6
//mm.matrix[1][1] = 5;		// 7 8 9
//mm.matrix[1][2] = 6;
//mm.matrix[2][0] = 7;
//mm.matrix[2][1] = 8;
//mm.matrix[2][2] = 9;

//mtr hm1 = BuildHouseholderMatrix1row(a);
//// householder matrix
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		printf("A%d%d = %lf\n", i, j, hm1.matrix[i][j]);
//	}
//}
//printf("\n");
//printf("\n");
//printf("\n");

//// initial matrix
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		printf("A%d%d = %lf\n", i, j, mm.matrix[i][j]);
//	}
//}
//printf("\nPRODUCT OF INITIAL AND FIRST HOUSEHOLD MATRIX\n");
//
//// product
//mtr MMM = MatrixProduct(hm1, mm); // now works correct
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		printf("A%d%d = %lf\n", i, j, MMM.matrix[i][j]);
//	}
//}
//// -12 -9 -13
//// 0 -2 -9
//// 0 2 1
//
//double a2[3] = { MMM.matrix[0][1],MMM.matrix[1][1], MMM.matrix[2][1] };

//mtr hm2 = BuildHouseholderMatrix2row(a2);
//printf("\n second household matrix\n");
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		printf("A%d%d = %lf\n", i, j, hm2.matrix[i][j]);
//	}
//}
//


//printf("\nPRODUCT OF MATRIX W/ EMPTY FIRST COLUMN AND SECOND HOUSEHOLDER\n");
//mtr MMM2 = MatrixProduct(hm2, MMM);
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		printf("A%d%d = %lf\n", i, j, MMM2.matrix[i][j]);
//	}
//}






return 0;
	}

*/






/*
#include "Header.h"
// back to c for callocs to work properly
// simple iteration method for 3rd lab
// infinite norm used everywhere
typedef struct {
		double matrix[10][10];
		double vector[10];
} augmented_matrix;

typedef struct {
	double matrix[10][10];
} mtr;

double abs1(double a) {
	if (a > 0) {
		return a;
	}
	else {
		return -a;
	}
}

void NthVectorFromMatrix(double* vector, mtr mat, int n) {
	// fills vector w/ elements from nth column of mat
	for (int i = 0; i < 10; i++) {
		vector[i] = mat.matrix[i][n];
	}
	return;
}

double VectorNormInf(double* vector) {
	double max = vector[0];
	for (int i = 0; i < 10; i++) {
		if (abs1(vector[i]) > abs1(max)) {
			max = vector[i];
		}
	}
	return abs1(max);
}
double* LinearCombVectors(double* v1, double* v2, double a1, double a2) {
	// allocates memory and returns linear combination of v1 and v2
	double* sum = (double*)calloc(10, sizeof(double));
	for (int i=0; i < 10; i++) {
		sum[i] = a1 * v1[i] + a2 * v2[i];
	}

	return sum;
}

mtr BuildHouseholderMatrixNRow(double* a, int n) {
	// nth Housholder matrix in 10d
	double sign = 0;
	if (a[n] > 0) {
		sign = -1;
	}
	else {
		sign = 1;
	}
	double s1 = sign * VectorNorm2(a,n);
	printf("%lf\n",s1);
	double n1 = 1 /  sqrt(2*s1 * (s1 - a[n]));
	double* a1 = (double*)calloc(10, sizeof(double));
	for (int i = n; i < 10; i++) {
		a1[i] = n1 * a[i];
	}
	a1[n] -= n1 * s1;
	mtr m = {0}; // 3 taken as an example
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			if (i == j) {
				 m.matrix[j][i] = 1 - 2 * a1[i] * a1[j];
			}
			else {
				m.matrix[i][j] = m.matrix[j][i] = - 2 * a1[i] * a1[j];

			}
		}
	}
	free(a1);
	return m;
}

double VectorNorm2(double* vector, int k) {	// inf norm for 10d vector
	double sum = 0;							// starting from kth element
	for (int i = k; i < 10; i++) {
		sum += pow(vector[i], 2);
	}
	return sqrt(sum);
}

void UnitariseVector(double* vector) {
	double norm = VectorNorm2(vector,0);
	for (int i = 0; i < 10; i++) {
		vector[i] = vector[i] / norm;
	}
	return;
}

mtr MatrixProduct(mtr m1, mtr m2) { // for 10x10 matrices
	mtr m = { 0 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				m.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
			}
		}
	}

	return m;
}

void RightSideProduct(mtr m, double* b) {
	double* b1 = (double*)calloc(10, sizeof(double));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			b1[i] += b[j] * m.matrix[i][j];
		}
	}
	for (int i = 0; i < 10; i++) {
		b[i] = b1[i];
	}
	free(b1);
	return;
}

void PrintMatrix(mtr m) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%8.1lf",m.matrix[i][j]);
		}
		printf("\n");
	}
	return;
}

double SolveSystem(mtr m, double* b,double* X) {
	// X - analitycal solution; returns relative error
	double* x = (double*)calloc(10, sizeof(double));
	double sum = 0;
	for (int i = 9; i > -1; i--) {
		for (int j = 0; j < 10; j++) {
			sum += x[j] * m.matrix[i][j];
		}
		x[i] = (b[i] - sum) / m.matrix[i][i];
		sum = 0;
	}
	for (int i = 0; i < 10; i++) {
		printf("x%d = %.8lf\n", i, x[i]);
	}
	double* tmp = (double*)calloc(10, sizeof(double));
	for (int i = 0; i < 10; i++) {
		tmp[i] = X[i] - x[i]; // tmp = X - x;
	}
	for (int i = 0; i < 10; i++) {
		printf("xDelta%d = %le\n", i, tmp[i]);
	}
	double delta = VectorNormInf(tmp);
	printf("ABSOLUTE ERROR IN SOLUTION = %le\n", delta);
	free(x);
	free(tmp);
	return delta;
}

	int main(void)
	{
		double b1[10] = { 0 };
		double* X = (double*)calloc(10, sizeof(double));//analytical solution
		double* v1 = (double*)calloc(10, sizeof(double));//tmp variable
		mtr hm = { 0 };
		mtr m1 = { 0 };
		FILE* fp = fopen("dataz.txt", "r");
		if (fp == NULL) {
			printf("no file");
			return 0;
		}


		double xx[10] = { 0 };
		for (int q = 0; q < 10; q++) {

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					fscanf(fp, "%lf", &m1.matrix[i][j]);
				}
			}
			for (int i = 0; i < 10; i++) { // right side
				fscanf(fp, "%lf", b1 + i);
			}
			for (int i = 0; i < 10; i++) { // analytical solution
				fscanf(fp, "%lf", X + i);
			}

			for (int i = 0; i < 9; i++) {
				NthVectorFromMatrix(v1, m1, i);
				hm = BuildHouseholderMatrixNRow(v1, i);

				m1 = MatrixProduct(hm, m1);
				printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
				PrintMatrix(m1);
				RightSideProduct(hm, b1);				//CHANGE THIS
			}
			double xdif1 = SolveSystem(m1, b1, X); // relative error in x
			xx[q] = xdif1;
		}


		fclose(fp);

		FILE* ffp = fopen("d.txt", "w");
		if (ffp == NULL) {
			perror("file not FOUnd; ");
			return 0;
		}
		for (int i =0; i < 10; i++)  fprintf(ffp, "%.4lf ", xx[i]);
		//fwrite(xx, sizeof(double), 8, ffp);
		//fwrite(bb, sizeof(double), 8, ffp);


		//double deltab2[10] = { 0 };
		//double deltab3[10] = { 0 };
		//double deltab4[10] = { 0 };
		//double deltab5[10] = { 0 };
		//double deltab6[10] = { 0 };
		//double deltab7[10] = { 0 };
		//double deltab8[10] = { 0 };


		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab2[i] = b2[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab3[i] = b3[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab4[i] = b4[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab5[i] = b5[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab6[i] = b6[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab7[i] = b7[i] - b[i]; // b1 = b - b1
		//}
		//for (int i = 0; i < 10; i++) {
		//	//	CHANGE THIS CHANGWFWLDFJS;DFSDLFJ;
		//	deltab8[i] = b8[i] - b[i]; // b1 = b - b1
		//}



		//double bdif2 = VectorNormInf(deltab2) / VectorNormInf(b);

		//double bdif3 = VectorNormInf(deltab3) / VectorNormInf(b);

		//double bdif4 = VectorNormInf(deltab4) / VectorNormInf(b);

		//double bdif5 = VectorNormInf(deltab5) / VectorNormInf(b);

		//double bdif6 = VectorNormInf(deltab6) / VectorNormInf(b);

		//double bdif7 = VectorNormInf(deltab7) / VectorNormInf(b);

		//double bdif8 = VectorNormInf(deltab8) / VectorNormInf(b);



		//printf("INITIAL MATRIX\n");
		//PrintMatrix(m);
		//mtr m1, m2, m3, m4, m5, m6, m7, m8;
		//m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m;
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m1, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);
		//
		//	m1 = MatrixProduct(hm, m1);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i+1);
		//	PrintMatrix(m1);
		//	RightSideProduct(hm, b1);				//CHANGE THIS
		//	}
		//
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m2, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);

		//	m2 = MatrixProduct(hm, m2);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
		//	PrintMatrix(m2);
		//	RightSideProduct(hm, b2);				//CHANGE THIS
		//}
		//
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m3, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);

		//	m3 = MatrixProduct(hm, m3);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
		//	PrintMatrix(m3);
		//	RightSideProduct(hm, b3);				//CHANGE THIS
		//}
		//
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m4, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);

		//	m4 = MatrixProduct(hm, m4);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
		//	PrintMatrix(m4);
		//	RightSideProduct(hm, b4);				//CHANGE THIS
		//}
		//
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m5, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);

		//	m5 = MatrixProduct(hm, m5);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
		//	PrintMatrix(m);
		//	RightSideProduct(hm, b5);				//CHANGE THIS
		//
		//}
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m6, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);

		//	m6 = MatrixProduct(hm, m6);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
		//	PrintMatrix(m);
		//	RightSideProduct(hm, b6);				//CHANGE THIS

		//}
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m7, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);

		//	m7 = MatrixProduct(hm, m7);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
		//	PrintMatrix(m);
		//	RightSideProduct(hm, b7);				//CHANGE THIS
		//
		//}
		//for (int i = 0; i < 9; i++) {
		//	NthVectorFromMatrix(v1, m8, i);
		//	hm = BuildHouseholderMatrixNRow(v1, i);

		//	m8 = MatrixProduct(hm, m8);
		//	printf("MATRIX W/ EMPTY %d COLUMNS\n", i + 1);
		//	PrintMatrix(m);
		//	RightSideProduct(hm, b8);				//CHANGE THIS

		//}

		//
		//double xdif2 = SolveSystem(m2, b2, X); // relative error in x
		//double xdif3 = SolveSystem(m3, b3, X); // relative error in x
		//double xdif4 = SolveSystem(m4, b4, X); // relative error in x
		//double xdif5 = SolveSystem(m5, b5, X); // relative error in x
		//double xdif6 = SolveSystem(m6, b6, X); // relative error in x
		//double xdif7 = SolveSystem(m7, b7, X); // relative error in x
		//double xdif8 = SolveSystem(m8, b8, X); // relative error in x

		//printf("1RELATIVE DIF IN RIGHT SIDE = %.6lf\n", bdif1);
		//printf("1RELATIVE DIF IN SOLUTION = %.6lf\n", xdif1);
		//printf("2RELATIVE DIF IN RIGHT SIDE = %.6lf\n", bdif2);
		//printf("2RELATIVE DIF IN SOLUTION = %.6lf\n", xdif2);
		//printf("3RELATIVE DIF IN RIGHT SIDE = %.6lf\n", bdif3);
		//printf("3RELATIVE DIF IN SOLUTION = %.6lf\n", xdif3);
		//printf("4RELATIVE DIF IN RIGHT SIDE = %.6lf\n", bdif4);
		//printf("4RELATIVE DIF IN SOLUTION = %.6lf\n", xdif4);
		//printf("5RELATIVE DIF IN RIGHT SIDE = %.6lf\n", bdif5);
		//printf("5RELATIVE DIF IN SOLUTION = %.6lf\n", xdif5);
		//printf("6RELATIVE DIF IN RIGHT SIDE = %.6lf\n", bdif6);
		//printf("6RELATIVE DIF IN SOLUTION = %.6lf\n", xdif6);
		//printf("7RELATIVE DIF IN RIGHT SIDE = %.6lf\n", bdif7);
		//printf("7RELATIVE DIF IN SOLUTION = %.6lf\n", xdif7);
		//printf("8RELATIVE DIF IN RIGHT SIDE = %.6lf\n", bdif8);
		//printf("8RELATIVE DIF IN SOLUTION = %.6lf\n", xdif8);
		//double xx[8] = { 0 };
		//xx[0] = xdif1;
		//xx[1] = xdif2;
		//xx[2] = xdif3;
		//xx[3] = xdif4;
		//xx[4] = xdif5;
		//xx[5] = xdif6;
		//xx[6] = xdif7;
		//xx[7] = xdif8;
		//double bb[8] = { 0 };
		//bb[0] = bdif1;
		//bb[1] = bdif2;
		//bb[2] = bdif3;
		//bb[3] = bdif4;
		//bb[4] = bdif5;
		//bb[5] = bdif6;
		//bb[6] = bdif7;
		//bb[7] = bdif8;
		//double tmp = xx[0];
		//for (int i = 0; i < 8; i++) {
		//	for (int j = i; j < 8; j++) {
		//		if (xx[j] < tmp) {
		//			tmp = xx[j];
		//		}
		//	}
		//	xx[i] = tmp;
		//}
		//tmp = bb[0];
		//for (int i = 0; i < 8; i++) {
		//	for (int j = i; j < 8; j++) {
		//		if (bb[j] < tmp) {
		//			tmp = bb[j];
		//		}
		//	}
		//	bb[i] = tmp;
		//}
		//fwrite(bb, sizeof(double), 8, fp);





free(v1);
free(X);
fclose(ffp);
// cond:110.2
// B: 0.034461 0.061604 0.074746 0.097194 0.105683 0.11052 0.11257 0.144028 0.161936 0.177552 
// X: 0.004113 0.030688 0.088248 0.027153 0.136235 0.03199 0.06053 0.155606  0.264554 0.145667
//cond:2200.1423
//B 0.012942 0.030365 0.040274  0.050047 0.052881 0.065385 0.078282 0.089558  0.122537 0.143625 0.199816 
//X 0.049852 0.052336 0.00085  0.110045 0.081354  0.034151 0.078127 0.391321  0.190288 0.148614 0.217223

// cond:430020.321
// B 0.009859 0.028721 0.035505 0.053864 0.0987893 0.163110
// X 0.060896 0.214451 0.187440 0.054033 0.096465 0.145085


//double a[3] = { 4.0,10.0,7.0 };
//mtr mm;
//mm.matrix[0][0] = 4;
//mm.matrix[0][1] = 3;
//mm.matrix[0][2] = 12;		// 4 3 12
//mm.matrix[1][0] = 10;		// 10 5 6
//mm.matrix[1][1] = 5;		// 7 8 9
//mm.matrix[1][2] = 6;
//mm.matrix[2][0] = 7;
//mm.matrix[2][1] = 8;
//mm.matrix[2][2] = 9;

//mtr hm1 = BuildHouseholderMatrix1row(a);
//// householder matrix
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		printf("A%d%d = %lf\n", i, j, hm1.matrix[i][j]);
//	}
//}
//printf("\n");
//printf("\n");
//printf("\n");

//// initial matrix
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		printf("A%d%d = %lf\n", i, j, mm.matrix[i][j]);
//	}
//}
//printf("\nPRODUCT OF INITIAL AND FIRST HOUSEHOLD MATRIX\n");
//
//// product
//mtr MMM = MatrixProduct(hm1, mm); // now works correct
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		printf("A%d%d = %lf\n", i, j, MMM.matrix[i][j]);
//	}
//}
//// -12 -9 -13
//// 0 -2 -9
//// 0 2 1
//
//double a2[3] = { MMM.matrix[0][1],MMM.matrix[1][1], MMM.matrix[2][1] };

//mtr hm2 = BuildHouseholderMatrix2row(a2);
//printf("\n second household matrix\n");
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		printf("A%d%d = %lf\n", i, j, hm2.matrix[i][j]);
//	}
//}
//


//printf("\nPRODUCT OF MATRIX W/ EMPTY FIRST COLUMN AND SECOND HOUSEHOLDER\n");
//mtr MMM2 = MatrixProduct(hm2, MMM);
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 3; j++) {
//		printf("A%d%d = %lf\n", i, j, MMM2.matrix[i][j]);
//	}
//}






return 0;
	}

*/
