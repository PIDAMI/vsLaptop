#include "Header.h"
#define SIZE 10
#define TESTS 9
// back to c for callocs to work properly
// simple iteration method for 3rd lab
// infinite norm used everywhere

typedef struct {
	double matrix[SIZE][SIZE];
} mtr;


double MatrixInfNorm(mtr m) {
	double max=0;
	double tmp = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			tmp += fabs(m.matrix[i][j]);
		}
		if (tmp > max) {
			max = tmp;
		}
		tmp = 0;
	}
	
	return max;
}

void NthVectorFromMatrix(double* vector, mtr mat, int n) {
	// fills vector w/ elements from nth column of mat
	for (int i = 0; i < SIZE; i++) {
		vector[i] = mat.matrix[i][n];
	}
	return;
}
// функци€ записывает в массив элементы из энного столбца матрицы
// принимает массив дл€ хранени€ элементов. матрицу и номер столбца
// ничего не возвращает
double VectorNormInf(double* vector) {
	double max = vector[0];
	for (int i = 0; i < SIZE; i++) {
		if (fabs(vector[i]) > fabs(max)) {
			max = vector[i];
		}
	}
	return fabs(max);
}
// вычисл€ет бесконечную норму вектора
// принимает массив с элементами из вектора
//возвращает бесконечную норму вектора
mtr BuildHouseholderMatrixNRow(double* a, int n) {
	// nth Housholder matrix in 10d
	double sign = 0;
	if (a[n] > 0) {
		sign = -1;
	}
	else {
		sign = 1;
	}
	double s1 = sign * VectorNorm2(a, n);
	double n1 = 1 / sqrt(2 * s1 * (s1 - a[n]));
	double* a1 = (double*)calloc(SIZE, sizeof(double));
	for (int i = n; i < SIZE; i++) {
		a1[i] = n1 * a[i];
	}
	a1[n] -= n1 * s1;
	mtr m = { 0 }; // SIZE taken as an example
	for (int i = 0; i < SIZE; i++) {
		for (int j = i; j < SIZE; j++) {
			if (i == j) {
				m.matrix[j][i] = 1 - 2 * a1[i] * a1[j];
			}
			else {
				m.matrix[i][j] = m.matrix[j][i] = -2 * a1[i] * a1[j];

			}
		}
	}
	free(a1);
	return m;
}
// строит матрицу хаусхолдера, обнул€ющую энный столбец матрицы
// принимает массив из элементов столбца матрицы и номер столбца
// возвращает матрицу с обнуленным столбцом
double VectorNorm2(double* vector, int k) {	// inf norm for 10d vector
	double sum = 0;							// starting from kth element
	for (int i = k; i < SIZE; i++) {
		sum += pow(vector[i], 2);
	}
	return sqrt(sum);
}

mtr MatrixProduct(const mtr m1, const mtr  m2) { // for 10x10 matrices
	mtr m = { 0 };
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				m.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
			}
		}
	}

	return m;
}
// вычисл€ет произведение матриц
// принимает две матрицы
// возвращает матрицу, €вл€ющуюс€ произведением введенных
void RightSideProduct( mtr m, double* b, double* container) {
	double* b1 = (double*)calloc(SIZE, sizeof(double));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			b1[i] += b[j] * m.matrix[i][j];
		}
	}
	for (int j = 0; j < SIZE; j++) {
		container[j] = b1[j];
	}
	free(b1);
	return;  
}
// вычисл€ет произведение матрицы на вектор
// принимает матрицу и массив из элементов вектор
// возвращает вектор, €вл€ющийс€ произведением матрицы и вектора
void PrintMatrix(const mtr* m) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%6.1lf ", m->matrix[i][j]);
		}
		printf("\n");
	}
	return;
}

double SolveSystem(const mtr m, const double * b, const double  * X) {
	// X - analitycal solution; returns relative error
	double* x = (double*)calloc(SIZE, sizeof(double));
	double sum = 0;
	for (int i = 9; i > -1; i--) {
		for (int j = 0; j < SIZE; j++) {
			sum += x[j] * m.matrix[i][j];
		}
		x[i] = (b[i] - sum) / m.matrix[i][i];
		sum = 0;
	}
	for (int i = 0; i < SIZE; i++) {
		printf("x%d = %.8lf\n", i, x[i]);
	}
	double* tmp = (double*)calloc(SIZE, sizeof(double));
	for (int i = 0; i < SIZE; i++) {
		
		tmp[i]= fabs(X[i] - x[i]);
	// tmp = X - x;
	}
	double max = VectorNormInf(tmp);
	printf("ABSOLUTE ERROR IN SOLUTION = %le\n", max);
	free(x);
	return max;
}
// выполн€ет обратный ход метода √аусса
// принимает верхнюю треугольную матрицу, вектор правой части и вектор точного решени€ системы
// возвращает относительную погрешность в решении


//double q,const double* x0

int Jacobi(const mtr m, const double* b, double eps, double *xExact) {
	int i, j, iter = 0;
	double* x=calloc(SIZE,sizeof(double));
	double* prev = calloc(SIZE, sizeof(double));;
	double* delta = calloc(SIZE, sizeof(double));;
	mtr M = m;
	


	double max= 0;
	int i_max=0, j_max=0;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {

			if (max < m.matrix[i][j]) {
				max = m.matrix[i][j];
				i_max = i;
				j_max = j;
			}
		}
	}


	
	// q= 1.3168
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (i == j) 
				M.matrix[i][j] = 1 - M.matrix[i][j] / max;
			else 
				M.matrix[i][j] =  - M.matrix[i][j] / max;
		}
	}
	
	double qNew = MatrixInfNorm(M);
	printf("NEW Q IS %lf\n",qNew);

	do {
		iter++;
		

		RightSideProduct(M, prev, x);
		for (i = 0; i < SIZE; i++) {
			x[i] = x[i] + (b[i] / max);
		}
		
		/*printf("ITERATION %d\n", iter);
		for (i = 0; i < SIZE; i++) 
			printf("x%d = %lf\n", i + 1, x[i]);*/

		/*for (i = 0; i < SIZE; i++) {
			prev[i] = b[i];
			for (j = 0; j < SIZE; j++) {
				 if (i != j) prev[i] -= m.matrix[i][j] * x[j];
			}
			prev[i] /= m.matrix[i][j];
		}*/

		for (int h = 0; h < SIZE; h++) {
			delta[h] = x[h] - prev[h];
			prev[h] = x[h];
		}
	} while (VectorNormInf(delta)  > eps * fabs((1 - qNew)/qNew));
	for (j = 0; j < SIZE; j++)
		printf("x=%lf, xExacte=%lf\n",x[j],xExact[j]);
	
	RightSideProduct(m, x, x);

	for (j = 0; j < SIZE; j++)
		delta[j] = x[j] - b[j];
	
	double dx = VectorNormInf(delta);
	
	free(delta);
	free(x);
	free(prev);
	return iter;
}

int main(void)
{
	int i,j;
	int iters[TESTS] = { 0 };
	double xNum[SIZE] = { 0 };
	double b[SIZE] = { 0 };
	double x[SIZE] = {0};//analytical solution
	mtr m = { 0 };
	mtr mShift = { 0 };
	FILE* fp = fopen("dataz.txt", "r");
	if (fp == NULL) {
		printf("no file");
		return 0;
	}
	
	
	double dx[TESTS];
	for (int h = 0; h < TESTS; h++) {
		for (i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				fscanf(fp, "%lf,", &m.matrix[i][j]);
			}
		}
		for (i = 0; i < SIZE; i++) { // analytical solution
			fscanf(fp, "%lf,", b + i);
		}
		for (i = 0; i < SIZE; i++) { // right side
			fscanf(fp, "%lf,", x + i);
		}
		//PrintMatrix(&m);
		
		iters[h] = Jacobi(m, b, 0.01,x);
		//for (i = 0; i <TESTS; i++) {
		//	/*for (j = 0; j < SIZE; j++) {
		//		x0[j] = b[j] + 34*(double)i;
		//	}
		//	x0FirstElem[i] = x0[1];*/
		//	iters[i] = Jacobi(m, b, pow(10,-i)/10,q,x0);
		//}
	}
	fclose(fp);


//	for (i = 0; i < TESTS; i++)  printf("eps = 10^%d,iterations = %d \n",i+1,iters[i]);


	FILE* ffp = fopen("d.txt", "w");
	if (ffp == NULL) {
		perror("file not FOUnd; ");
		return 0;
	}
	// det = 5, dx=0.001130; 
	for (i = 0; i < TESTS; i++)  fprintf(ffp, "%d ", iters[i]);
	fclose(ffp);


	//19306 251 202 177 151 106 58 19 
	

	return 0;
}





