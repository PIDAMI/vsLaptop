#pragma warning(disable:4996)
#include "AALCW.h"
/*
  05 SER Сумма ряда
  Задача: написать программу, выводящую таблицу из M значений некоторой
  функции f(x) на промежутке от a до b. Функция задана как сумма бесконечного
  ряда
*/
//double AbsDoubleDif(double a, double b) { 
//	if (a > b) {					   
//		return a - b;
//	}
//	else {
//		return b - a;
//	}
//}
//
//double SinSquaredNth(double x, int n) {
//	double sum = 0;
//	double xi = x * x;
//	sum = xi;
//	printf("u = %lf sum = %lf\n", xi, sum);
//	for (double i = 1; i < n ; i++) {
//		double q = - 4 * x * x / (2*i + 1) / (2*i + 2);
//		xi *= q;
//		sum += xi;
//		printf("u = %lf sum = %lf\n", xi, sum);
//	}
//	return sum;
//}
//double SinSquaredMachEps(double x) {
//	double sum = 0;
//	double count = 1;
//	double xi = x * x;
//	sum = xi;
//	do {
//		double q = -4 * x * x / (2 * count + 1) / (2 * count + 2);
//		count++;
//		xi *= q;
//		sum += xi;
//		//printf("u = %lf sum = %lf\n", xi, sum); 
//	} while (sum != sum + xi);
//	return sum;
//}
//
//void PrintTable(double a, double b, int m) {
//	int i;
//	double step;
//	double f, g, delta;
//	printf("PrintTable function:\n");
//	for (i = 0; i < 5; i++) {
//		printf("+ - - - - - ");
//	}
//	printf("- +\n");
//	printf("|     i     |     x     |    f(x)   |    g(x)   |  f(x)-g(x)  |\n");
//	for (i = 0; i < 5; i++) {
//		printf("+ - - - - - ");
//	}
//	printf("- +\n");
//	step = (b - a) / ((double)m -1);
//	for (i = 0; i < m; i ++) {
//		f = SinSquaredMachEps(a + step * (double)i);
//		g = sin(a + step * (double)i) * sin(a + step * (double)i);
//		delta = AbsDoubleDif(f, g);
//		printf("|%6d     |%8.2lf   |%8.2lf   |"
//			"%8.2lf   |%10.2le   |\n", i, a + step * (double)i, f, g, delta);
//	}
//	for (int i = 0; i < 5; i++) {
//		printf("+ - - - - - ");
//	}
//	printf("- +\n");
//
//}

//int main() {
//	double x, f, g, delta;
//	double a, b;
//	int m;
//	x = 0.5;
//	// первое приближение
//	f = x * x;
//	g = sin(x) * sin(x);
//	delta = AbsDoubleDif(f,g);
//	printf("First approximation\n");
//	printf("x = %lf f = %lf g = %lf delta = %lf\n", x, f, g, delta);
//	// энное приближение
//	printf("Third approximation\n");
//	f = SinSquaredNth(x, 3);
//	delta = AbsDoubleDif(f, g);
//	printf("x = %lf f = %lf g = %lf delta = %le\n", x, f, g, delta);
//	// вычисление с погрешностью, равной машинному эпсилону
//	f = SinSquaredMachEps(x);
//	delta = AbsDoubleDif(f, g);
//	printf("Approximation w/ machine epsilon error\n");
//	printf("x = %lf f = %lf g = %lf delta = %le\n", x, f, g, delta);
//	// таблица
//	//Добавьте чтение с клавиатуры a, b и m,
//	//проверяя диапазон | x | <= 1, m > 1
//	printf("Enter the range: ");
//	do {
//		scanf("%lf %lf", &a, &b);
//	} while (AbsDoubleDif(b,0) >1 && AbsDoubleDif(a, 0) > 1);
//	printf("Enter the number of points for computing: ");
//	do {
//		scanf("%d", &m);
//	} while (m < 1);
//
//	PrintTable(a, b, m);
//
//	return 0;
//}