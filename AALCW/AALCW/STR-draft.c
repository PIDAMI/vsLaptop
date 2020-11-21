#pragma warning(disable:4996)
#include "AALCW.h"
//#define MAX_LENGTH 100
//#define COMMA 0
//#define N_COMMA 1
//#define CHAR 0
//#define N_CHAR 1
//#define NUM 2
//#define N_NUM 1
//#define SMALL 0
//#define CAPITAL 1
/*
Задание STR–5 
Смена регистра
В рамках общего условия задачи написать
функцию, которая в заданном буфере все заглавные буквы заменяет на строчные,
а строчные — на заглавные.

 пустая строка такая же, как и в 
 dst, т.е. 2 переноса строки


в задании "МОЖНО считать, что строки ограничены
 и использовать статически массив", но необходимости
 нет, так что используются функции из предыдущего
 задания чтением в динамический массив
 */
//
// int StrLength(const char* str)
//{
//	int length = 0;
//	if (str == NULL) {
//		return 0;
//	}
//	while (*str++)
//		length++;
//	return length;
//}
//
//
//char* ReadLine() {
//	char c;
//	int i;
//	char* buffer;
//	char* tmp;
//	i = 0;
//	buffer = (char*)calloc(1,sizeof(char)); //для пустой строки, если дальше ничего не будет
//	if (buffer == NULL) {
//		perror("Not enough memory: ");
//		return NULL;
//	}
//
//	while ((c = getchar()) != '\n') {
//		
//		tmp = (char*)realloc(buffer, (i + 1)* sizeof(char));
//		if (tmp == NULL) {
//			perror("Not enough memory: ");
//			return NULL;
//		}
//		buffer = tmp;
//		buffer[i++] = c;
//	}
//
//	buffer[i] = '\0';
//	
//	return buffer;
//}
//char* Concatination(char* str, char* plus, const int flag) {
//	int len1, len2;
//	char* tmp;
//	if (str == NULL || plus == NULL) {
//		printf("no string found\n");
//		return NULL;
//	}
//	len1 = StrLength(str);
//	len2 = StrLength(plus);
//	if (flag == COMMA) {
//		tmp = (char*)realloc(str, (len1 + len2 + 2) * sizeof(char));
//		if (!tmp) {
//			printf("Not enough memory: ");
//			return NULL;
//		}
//		str = tmp;
//		str[len1] = ',';
//		for (int i = len1; i < len1 + len2+1; i++) {
//			// qw\0 + q\0 = qw,q\0
//			str[i+1] = plus[i - len1];
//		}
//	}
//	else if (flag== N_COMMA){
//		tmp = (char*)realloc(str, (len1 + len2 + 1) * sizeof(char));
//		if (!tmp) {
//			printf("Not enough memory: ");
//			return NULL;
//		}
//		str = tmp;
//		for (int i = len1; i < len1 + len2+1; i++) {
//			str[i] = plus[i - len1];
//		}
//	}
//
//
//	return str;
//}
//
//char* ReadParagraph() { 
//	char* buffer = NULL;
//	char* paragraph = ReadLineSTR();
//	if (paragraph == NULL) {
//		printf("Not enough memory: ");
//		return NULL;
//	}
//	if (paragraph[0] == '\0') {
//		// пустая строка
//		return NULL;
//	}
//	do {
//		buffer = ReadLine();
//		if (buffer[0] == '\0') {
//			break;
//		}
//		paragraph = Concatination(paragraph, buffer,N_COMMA);
//	} while (1);
//	return paragraph;
//}
//
//int IsAlChar(char c) {
//	return ( c>64 && c < 91 || c > 96 && c < 123) ? CHAR: N_CHAR;
//}
//
//int IsAlNum(char c) {
//	return (c > 47 && c < 58) ? NUM : N_NUM;
//}
//
//int IsAlCapital(char c) {
//	return (c > 96 && c < 123) ? SMALL : CAPITAL;
//}
//
//void SwapCase(char str[]) {
//	// проверок для массива в этой функции нет, т.к. они есть при чтении 
//	char c;
//	int isCap;
//	for (int i = 0; i < StrLength(str); i++) {
//		c = str[i];
//		isCap = IsAlCapital(c);
//		if (c > 57) {
//			if (isCap == CAPITAL) {
//				str[i] = c + 32;
//			}
//			else if (isCap == SMALL) {
//				str[i] = c - 32;
//			}
//		}
//	}
//	return;
//}
//
//int main() {
//	char* str;
//	setlocale(LC_CTYPE, "Russian");
//	printf("Задание STR-5: Смена регистра\n");
//	while (1) {
//		printf("Введите строку: ");
//		str = ReadParagraph();
//		if (str == NULL) {
//			return 0;
//		}
//		SwapCase(str);
//		printf("Результат     : %s\n", str);
//	}
//	return 0;
//}