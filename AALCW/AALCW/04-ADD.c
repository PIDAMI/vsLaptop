#pragma warning(disable:4996)
#include "AALCW.h"
//#define LENGTH 4
/* 04 ADD сложение в столбик
  Задача: написать программу, складывающую в столбик два числа, с контролем
  правильности результата
*/
//
//int Pow(int a, int n) {
//	int sum = 1;
//	while (n) {
//		sum *= a;
//		n--;
//	}
//	return sum;
//}
//
//
//int Fill(int number, int* digits, int length) { 
//	// 123 -> [3, 2, 1, 0 ... 0]
//	int digitsCounter = 1;
//	if (length > LENGTH) {
//		return -1;
//	}
//	for (int i = 0; i < length;i++) {
//		digits[i] = number % 10;
//		number /= 10;
//		if (number) {
//			digitsCounter++;
//		}
//	}
//	return digitsCounter;
//}
//
//void Print(int const* digits, int digitsNumber, int max_length) {
//	for (int i = max_length-1; i >= 0; i--) {
//		if (i > digitsNumber-1) {
//			printf("  ");
//		}
//		else {
//			printf("%d ", digits[i]);
//		}
//	}
//	printf("\n");
//	return;
//}
//
//int Add(int const* x, int const* y, int* xy, int digitsX, int digitsY) { 
//	int rest, sum, number_of_digits;
//	sum = rest = number_of_digits = 0;
//	for (int i = 0; i < max(digitsX, digitsY); i++) { 
//		sum = x[i] + y[i] + rest;		
//		if (sum > 9) {
//			sum %= 10;
//			xy[i] = sum;
//			rest = 1;
//		}
//		else {
//			xy[i] = sum;
//			rest = 0;
//		}
//		number_of_digits++;
//	}
//	if (rest) {
//		xy[number_of_digits++] = 1;
//	}
//	return number_of_digits;
//}
//
//int Collect(int const* digits, int length) {
//	int sum = 0;
//	for (int i = 0; i < length; i++) {
//		sum += digits[i] * Pow(10, i);
//	}
//	return sum;
//}
//
//int main() {
//	int a, b, c;
//	int A[LENGTH];
//	int B[LENGTH];
//	// длина Л+1, если сумма имеет больший порядок
//	// больший порядок, чем слагаемые
//	int C[LENGTH + 1]; 
//	scanf("%d %d", &a, &b);
//	int digits_a = Fill(a, A, LENGTH);
//	int digits_b = Fill(b, B, LENGTH);
//	int digits_c = Add(A, B, C, digits_a, digits_b);
//	c = Collect(C, digits_c);
//	int max_length = max(max(digits_a, digits_b), digits_c);
//	Print(A, digits_a, max_length);
//	Print(B, digits_b, max_length);
//	for (int i = 0; i < max_length; i++) {
//		printf("- ");			//горизонтальная черта
//	}
//	printf("\n");
//	Print(C, digits_c, max_length);
//	if (c == a + b) {
//		printf("success!");
//	}
//	else {
//		printf("something went wrong");
//	}
//	
//	return 0;
//}
