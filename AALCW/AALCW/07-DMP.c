#pragma warning(disable:4996)

#include "AALCW.h"
/*
 07 DMP Дамп памяти
 Задача: написать функцию, выводящую на экран шестнадцатеричный дамп блока
 памяти. Написанную функцию использовать в тестовой программе для вывода
 дампа двух массивов — целочисленного a[] и вещественного b[], содержащих
 одинаковые значения
*/
//
//#define SIZE 9
//#define START 600
//
//
//
//void FillInt(int* a, int size) { 
//	for (int i = 0; i < size; i++) {
//		a[i] = START + 2 * i;
//	}
//}
//
//
//void FillDouble(double* a, int size) {
//	for (int i = 0; i < size; i++) {
//		a[i] = START + 2.0 * i;
//	}
//}
//
//
//void PrintInt(int* a, int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
//
//void PrintDouble(double* a, int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%lf ", a[i]);
//	}
//	printf("\n");
//}
//
//void MemoryDump(void const* ptr, int size) {
//	char* p = ptr;
//	int counter = 0;
//	for (int i = 0; i < size; i++,counter++,p++) {
//		if (counter % 16 == 0) {
//			printf("\n%p: ", p);
//		}
//		printf("%02x ", *p);
//	}
//}
//
//int main() {
//	int arrInt[SIZE] = { 0 };
//	double arrDouble[SIZE] = { 0 };
//	long arr[SIZE] = { 0 };
//	FillInt(arrInt, SIZE);
//	PrintInt(arrInt, SIZE);
//	FillDouble(arrDouble, SIZE);
//	PrintDouble(arrDouble, SIZE);
//	MemoryDump(arrInt, sizeof(arrInt));
//	printf("\n");
//	printf("\n");
//	MemoryDump(arr, sizeof(arr));
//	return 0;
//}
