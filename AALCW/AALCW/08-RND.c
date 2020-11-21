#pragma warning(disable:4996)
#include "AALCW.h"

/*
08 RND Случайные числа
Работа со случайными числами, линейные преобразования числовых диапазонов.
Задача : написать программу, которая генерирует случайные числа, вычисляет и
рисует гистограмму их распределения.Для упрощения работы преподавателем
может выдаваться шаблонный файл с заготовками кода.
*/
//
//double Random(double a, double b) {
//	double x = (double)rand();
//	x /= (double)(RAND_MAX+1);
//	x *= (b - a);
//	x += a;
//	return x;
//}
//
//void FillRandom(double* arr, int size, double a, double b) {
//	for (int i = 0; i < size; i++) {
//		arr[i] = Random(a, b);
//	}
//	
//	return;
//}
//
//void Print(double const* arr, int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%lf\n", arr[i]);
//	}
//	printf("\n");
//	return;
//}
//
//void BuildHistogram(double const* arr,int size, double a,
//			double b, int* counters, int numCounters) {
//	int j, i;
//	double step;
//	step = (b - a) / (double)numCounters;
//	for (j = 0; j < numCounters; j++) { 
//		counters[j] = 0;
//	}
//	
//	for (i = 0; i < size; i++) {
//		for (j = 0; j < numCounters; j++) {
//			if (arr[i] < a + step * ((double)j + 1) && arr[i]> a + step * (double)j) {
//				counters[j] += 1;
//			}
//		}
//	}
//	return;
//}
//
//void PrintHistogram(int* counters, int numCounter) {
//	for (int i = 0; i < numCounter; i++) {
//		printf("%d ", counters[i]);
//	}
//	printf("\n");
//	return;
//}
//
//int IndexOfMaxNum(int* counters, int size) {
//	int max = counters[0];
//	int indMax = 0;
//	for (int i = 0; i < size; i++) {
//		if (counters[i] > max) {
//			indMax = i;
//			max = counters[i];
//		}
//	}
//	
//	return indMax;
//}
//
//void DrawHistogram(int* counters, int numCounters, int width) {
//	int unit_points = width / counters[IndexOfMaxNum(counters, numCounters)];
//	for (int i = 0; i < numCounters; i++) {
//		printf("%d ", i);
//		int num_dots = counters[i] * unit_points;
//		for (int j = 0; j < num_dots; j++) {
//			printf("o");
//		}
//		for (int j = 0; j < width - num_dots; j++) {
//			printf(".");
//		}
//		printf("\n");
//
//	}
//
//	return;
//}
//int main(void) {
//	const int PRINT_MAX = 20;
//	const double RANDOM_MIN = 0.3;
//	const double RANDOM_MAX = 0.75;
//	const double HIST_MIN = 0.0;
//	const double HIST_MAX = 1.0;
//	const int HIST_LINES = 5;
//	const int HIST_LENGTH = 16;
//	int size = 10;
//	double* numbers = NULL;
//	int* hist = NULL;
//	setlocale(LC_CTYPE, "Russian");
//	// Подготовьтесь к эксперименту
//	printf("\nВведите количество чисел: ");
//	scanf("%i", &size);
//	// Выделите память
//	numbers = malloc(size * sizeof(double));
//	hist = malloc(HIST_LINES * sizeof(int));
//	// Заполните массивы
//	printf("\nРавномерная СВ (первые %i чисел):\n", PRINT_MAX);
//	FillRandom(numbers, size, RANDOM_MIN, RANDOM_MAX);
//	Print(numbers, size < PRINT_MAX ? size : PRINT_MAX);
//	// Постройте гистограмму равномерной случайной величины
//	BuildHistogram(numbers, size, HIST_MIN, HIST_MAX, hist, HIST_LINES);
//	// левая граница у гистограммы меньше, чем у чисел из массива
//	// а верхняя - больше; получается, что в первый и последний
//	// подынтервал не попадают вообще никакие числа, т.к.
//	// длина интервала меньше разницы между границами гистрограммы и массива
//	// [0.0 (0.3 0.75) 1.0]; HIST_LINES = 5 -> 1 интервал равен (1-0)/5 = 0.2
//	// HIST_MIN - RANDOM_MIN = 0.3 - 0.0 = 0.3 > 0.2; d1 = 0.1
//	// HIST_MAX - RANDOM_MAX = 1.0 - 0.75 = 0.25 > 0.2; d2 = 0.05
//	// к тому же, второй и предпоследний интервал входят в область
//	// задания сл.чисел неполностью: второй интервал в 2 раза меньше
//	// обычных интервалов, предпоследний - в 4/3 раза, поэтому
//	// в этих интервалах чисел меньше, чем в остальных(кроме граничных)
//	PrintHistogram(hist, HIST_LINES);
//	DrawHistogram(hist, HIST_LINES, HIST_LENGTH);
//	// Освободите память
//	free(hist);
//	free(numbers);
//	return 0;
//	
//}