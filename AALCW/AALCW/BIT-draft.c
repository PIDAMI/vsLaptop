
#pragma warning(disable:4996)
#include "AALCW.h"
//typedef unsigned short integer_t;
//typedef unsigned int integer_t;
typedef unsigned char integer_t;
//typedef unsigned long integer_t;
//typedef unsigned long long integer_t;
typedef unsigned long long  MaxInt;

/*
Задание BIT–5
Обмен битов
В рамках общего условия задачи написать функцию,
которая по заданному числу типа integer_t возвращает другое число,
в котором переставлены местами соседние биты, 
первый со вторым, третий с четвертым и т.д.
*/
//
//MaxInt Pow2(MaxInt i) {
//	MaxInt res = 1;
//	while (i--!=0) {
//		res *= 2;
//	}
//	
//	return res;
//}
//
//integer_t Reversed(integer_t x1, integer_t size)
//{
//	integer_t i;
//	MaxInt tmp;
//	MaxInt* bin;
//	bin = calloc(size, sizeof(MaxInt));
//	if (!bin) {
//		printf("not enough memory;\n");
//		return 0;
//	}
//	for (i = 0; x1 > 0; i++)
//	{
//		if (x1 % 2 == 1) {
//			bin[i] = 1;
//		}
//		x1 /= 2;
//	}
//
//	i = size;
//	do {
//		i -= 2;
//		tmp = bin[i + 1];
//		bin[i + 1] = bin[i];
//		bin[i] = tmp;
//		
//	} while (i != 0);
//
//
//	tmp = 0;
//	for (; i < size; i++) {
//		tmp += bin[i] * Pow2(i);
//	}
//	return (integer_t)tmp;
//
//}
//
//integer_t SizeOfType() {
//	int i = 0;
//	integer_t l = 1;
//	while (l != 0) {
//		l = l << 1;
//		i++;
//	}
//	return i;
//}
//
//void PrintBinForm(integer_t x1, integer_t size) {
//	integer_t i;
//	integer_t* bin;
//	bin = calloc(size, sizeof(integer_t));
//	if (!bin) {
//		printf("not enough memory;\n");
//		return;
//	}
//	for (i = 0; x1 > 0; i++)
//	{
//		if (x1 % 2 == 1) {
//			bin[i] = 1;
//		}
//		x1 /= 2;
//	}
//	i = size;
//	while (i != 0) {
//		if (i-- % 8 == 0) {
//			printf(" ");
//		}
//		printf("%llu", (MaxInt)bin[i]);
//	}
//	printf("\n");
//}

//int main(void) {
//
//	MaxInt max;
//	integer_t input, tmp, size, len1, len2, reverse;
//	size = SizeOfType();
//	integer_t width = size / 4 + 2;
//	integer_t byteMax = 0xff, byteMin = 0;
//	setlocale(LC_CTYPE, "Russian");
//	printf("Задание BIT–3: Реверс четверок (8 бит)\n");
//	do {
//		len1 = len2 = 0;
//		printf("Введите число: ");
//		scanf_s("%llu", &max);
//		input = (integer_t)max;
//		byteMin = byteMax << (size - 8);
//		tmp = input;
//		while (tmp != 0) {
//			tmp /= 10;
//			len1++;
//		}
//		reverse = Reversed(input, size);
//		tmp = reverse;
//		while (tmp != 0) {
//			tmp /= 10;
//			len2++;
//		}
//
//		// выравнивание по правому краю для исходного числа
//		if (len2 > len1) {
//			for (integer_t i = 0; i < len2 - len1; i++)
//				printf(" ");
//		}
//
//		printf("%llu = ", (MaxInt)input);
//		printf("%#0*llx = ", width, (MaxInt)input);
//		PrintBinForm(input, size);
//		
//		// выравнивание по правому краю для перевернутого числа
//		if (len1 > len2) {
//			for (integer_t i = 0; i < len1 - len2; i++)
//				printf(" ");
//		}
//		printf("%llu = ", (MaxInt)reverse);
//		printf("%#0*llx = ", width, (MaxInt)reverse);
//		PrintBinForm(reverse, size);
//	} while (input != 0);
//
//	return 0;
//}

