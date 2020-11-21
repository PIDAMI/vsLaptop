#pragma warning(disable:4996)
#include "AALCW.h"
//#define MIN 0
//#define MAX 100
//#define SIZE 9
//#define STROKE_LENGTH 16

/*
09 FIL Дамп файла
Задача : написать программу, сохраняющую массив вещественных чисел в два файла :
текстовый и бинарный.Затем прочитать их и вывести на экран шестнадцатеричный
дамп, сравнить.
*/

//
//float Random(float a, float b) {
//	float x = (float)rand();
//	x /= (float)(RAND_MAX+1);
//	x *= (b - a);
//	x += a;
//	return floorf(x);
//}
//
//void FillFloats(float* arr, int length, float a, float b) {
//	for (int i = 0; i < length; i++) {
//		arr[i] = Random(a, b);
//	}
//	
//	return;
//}
//
//void PrintFloats(float const* arr, int length) {
//	printf("{");
//	for (int i = 0; i < length-1; i++) {
//		printf("%lf, ", arr[i]);
//	}
//	printf("%lf}\n", arr[length-1]);
//	return;
//}
//
//void WriteText(char const* filename, float* arr, int length) {
//	FILE* fp;
//	if ((fp = fopen(filename, "w")) == NULL) {
//		perror("Error occured while opening file: ");
//		return;
//	}
//	for (int i = 0; i < length; i++) {
//		fprintf(fp, "%.1f ", arr[i]);
//	}
//	fclose(fp);
//	return;
//}
//
//void WriteBinary(char const* filename, float* arr, int length) {
//	size_t size;
//	FILE* fp;
//	if ((fp = fopen(filename, "wb")) == NULL) {
//		perror("Error occured while opening file: ");
//		return;
//	}
//	size = fwrite(arr, sizeof(float), length, fp);
//	if (size != length) {
//		perror("error writing ");
//		return;
//	}
//	fclose(fp);
//	return;
//}
//
//float* ReadText(char const* filename, int* length) {
//	float* arr = NULL;
//	int i = 0;
//	FILE* fp;
//	if ((fp = fopen(filename, "r") ) == NULL) {
//		perror("Error occured while opening file: ");
//		return NULL;
//	}
//	while (!feof(fp)) {
//		float* tmp = realloc(arr, (i+1) * sizeof(float));
//		if (tmp == NULL) {
//			perror("Not enough memory;");
//			return NULL;
//		}
//		else{
//			arr = tmp;
//		}
//		fscanf(fp, "%f", arr + i );
//		i++;
//	}
//	*length = i - 1;
//	fclose(fp);
//	return arr;
//}
//
//float* ReadBinary(char const* filename, int* length) {
//	long size;
//	float* arr;
//	FILE* fp ;
//	if ((fp=fopen(filename,"rb")) == NULL) {
//		perror("Error occured while opening file: ");
//		return NULL;
//	}
//	fseek(fp, 0, SEEK_END); // перемотать в конец файла
//	size = ftell(fp); // узнать смещение от начала файла
//	fseek(fp, 0, SEEK_SET); // перемотать обратно в начало
//	arr = malloc(size);
//	if (arr == NULL) {
//		perror("Not enought memory: ");
//		fclose(fp);
//		return NULL;
//	}
//    *length = size/sizeof(float);
//	fread(arr, sizeof(float), *length, fp);
//	/*if (result != *length) {
//		perror("error while reading");
//		fclose(fp);
//		return NULL;
//	}
//	*/
//	fclose(fp);
//	return arr;
//}
//void FileDump(char const* filename)
//{
//	int i = 0, c = 0, shift = 0;
//	FILE* fp;
//	if ((fp =fopen(filename,"rb")) == NULL)
//		return;
//	while (1)
//	{
//		c = fgetc(fp);
//		printf("%08x:  ", shift);
//		printf("%02x ", c);
//		for (i = 1; i < STROKE_LENGTH; i++) {
//			c = fgetc(fp);
//			if (c == EOF) {
//				printf("\n");
//				return;
//			}
//			printf("%02x ", c);
//		}
//		shift += i;
//		printf("\n");
//	}
//}

//
//int main() {
//	int lenBin ;
//	int lenTxt ;
//	float* arr;
//	float* arrBin;
//	float* arrTxt;
//
//	arr = calloc(SIZE,sizeof(float));
//	FillFloats(arr, SIZE, MIN, MAX);
//	printf("initial array:\n");
//	PrintFloats(arr, SIZE);
//	WriteText("text.txt", arr, SIZE);
//	WriteBinary("binary.bin", arr, SIZE);
//	free(arr);
//
//
//	arrBin = ReadBinary("binary.bin", &lenBin);
//	printf("read from binary file:\n");
//	PrintFloats(arrBin, lenBin);
//	free(arrBin);
//
//
//	arrTxt = ReadText("text.txt", &lenTxt);
//	printf("read from text file:\n");
//	PrintFloats(arrTxt, lenTxt);
//	free(arrTxt);
//
//	printf("text file dump:\n");
//	FileDump("text.txt");
//	printf("binary file dump:\n");
//	FileDump("binary.bin");
//	return 0;
// }
