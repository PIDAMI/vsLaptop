#pragma warning(disable:4996)
#include "AALCW.h"

/*
 06 ROT Циклический сдвиг
 Задача: написать программу, циклически сдвигающую элементы массива на заданное
 количество позиций влево несколькими способами. Напишем три версии такой
 сдвигающей функции с одинаковым прототипом
*/

//
//void Fill(int* arr, int size) {
//	for (int i = 0; i < size; i++) {
//		arr[i] = i+1;
//	}
//}

//void Print(int* arr, int size) {
//	for (int i = 0; i < size ; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//}

//void Shift1(int* arr, int size) { 
//	int tmp = 0;
//	for (int i = 0; i < size-1; i++) {
//		tmp = arr[i+1];
//		arr[i + 1] = arr[i];
//		arr[i] = tmp;
//	}
//	return;
//}
//
//void Shift_Ver1(int* arr, int size, int delta) { 
//	if (!delta || delta >= size) {
//		printf("Not valid value of shift");
//		return;
//	}
//	for (int i = 0; i < delta; i++) {
//		Shift1(arr, size);
//	}
//	return;
//}
//
//void Reverse(int* arr, int left, int right) {
//	int tmp = 0;			
//	for (int i = 0; i < (right - left) / 2 + 1; i++) { 
//		tmp = arr[left+i];
//		arr[left + i] = arr[right - i];
//		arr[right - i] = tmp;
//	}
//	return;
//}
//
//void Shift_Ver2(int* arr, int size, int delta) {
//	Reverse(arr, 0, size-1);
//	Reverse(arr, 0, size - delta - 1);
//	Reverse(arr, size - delta, size - 1);
//	return;
//}

//
//int main(void) {
//	int arr[9] = { 0 };
//	int delta = 0;
//	// первая версия
//	Fill(arr, 9);
//	printf("Enter the value of the shift: ");
//	scanf("%d", &delta);
//	printf("Initial array: ");
//	Print(arr, 9);
//	printf("First function:");
//	Shift_Ver1(arr, 9, delta);
//	Print(arr, 9);
//	// second version of shift function
//	Fill(arr, 9);
//	printf("Enter the value of the shift: ");
//	scanf("%d", &delta);
//	printf("Initial array: ");
//	Print(arr, 9);
//	printf("Second function:");
//	Shift_Ver2(arr, 9, delta);
//	Print(arr, 9);
//
//	return 0;
//}
