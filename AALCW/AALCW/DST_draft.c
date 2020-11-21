#pragma warning(disable:4996)
#include "AALCW.h"
//#define SORTED 0
//#define N_SORTED 1
//#define COMMA 0
//#define N_COMMA 1
//#define CONTAINED 0
//#define N_CONTAINED 1
//#define EMPTY_STR -1
/*
 ������� DST-5
 ������������ ������
 (����� ���������� ��������).� ������ ������ ������� ������ �������� �������,
 ������� �� �������� ������ ������� � ������������ ������ ������,
 ���������� ������ ��� ���������� ���� �������� ������ ������ ������ �������, 
 ���������� ��������� ������� ����� ���������� � ������. ��� ����������� ��� ����
 ������� ������������.



"�������� ����� �� ����� �� ��� ���, 
 ���� ������������ �� ������ ������ ������"
 ��� ����������� ������ ������ � ������� ReadParagraph()
 ������������ '\0', �.� ������ ������������ ����� ��������
 ���� ���������������� ��������� ������, �� ReadLine()
 ������ �� �������� ������, ReadParagraph() ������ ������
 �� ReadLine()
 */
//
//int StrLength(const char* str)
//{
//	int length = 0;
//	if (str == NULL) {
//		return 0;
//	}
//	while (*str++)
//		length++;
//	return length;
//}
//char* ReadLine() {
//	char c ;
//	int i ;
//	char* buffer;
//	i = 0;
//	buffer = (char*)calloc(1,sizeof(char)); //��� ������ ������, ���� ������ ������ �� �����
//	if (!buffer) {
//		perror("Not enough memory: ");
//		return NULL;
//	}
//	while ((c = getchar()) != '\n') {
//		if (!(c > 47 && c < 58 || c>64 && c < 91 || c > 96 && c < 123)) {
//			continue;
//		}
//		char* tmp = (char*)realloc(buffer, (i + 1)* sizeof(char));
//		if (tmp == NULL) {
//			perror("Not enough memory: ");
//			return NULL;
//		}
//		buffer = tmp;
//		buffer[i++] = c;
//	}
//		buffer[i] = '\0';
//	
//	return buffer;
//}
//
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
//	char* buffer;
//	char* paragraph = ReadLine();
//	if (paragraph == NULL) {
//		printf("Not enough memory: ");
//		return NULL;
//	}
//	if (paragraph[0] == '\0') {
//		// ������ ������
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
//char* Reverse(const char* str, int n, int m) { // ���������� ������������ str �� n �� m ������� ������������
//	if (str == NULL || str[0] == '\0' || n > StrLength(str) || m > StrLength(str)) {
//		printf("nothing to reverse");
//		return  NULL;
//	}
//
//	if (n > m) {	// ���� �������������� ������ �� ����
//		char* rev = (char*)calloc(n - m + 1, sizeof(char));
//		if (rev == NULL) {
//			printf("not enough memory: ");
//			return NULL;
//		}
//		for (int i = m; i < n + 1; i++) {
//			rev[i - m] = str[i];
//		}
//		rev[n - m + 1] = '\0';
//		return rev;
//	}
//	else {
//		char* rev = (char*)calloc(m - n + 1, sizeof(char));
//		if (rev == NULL) {
//			printf("not enough memory: ");
//			return NULL;
//		}
//		for (int i = n; i < m + 1; i++) { // zxctd - > cxz, m = 2, n = 0; i=2; rev[0]=str[2]=c; rev[1]=str[m+1] 
//			rev[i - n] = str[m - i + n];
//		}
//		rev[m - n + 1] = '\0';
//		return rev;
//	}
//}
//
//int ContainedInOrigin(char* rever, char* str) {
//	int lenStr, lenRever;
//	int counter;
//	if (rever == NULL || str == NULL) {
//		printf("empty strings\n");
//		return EMPTY_STR;
//	}
//	lenStr = StrLength(str);
//	lenRever = StrLength(rever);
//	counter = 0;
//	for (int i = 0; i < lenStr - lenRever+1; i++) {
//		for (int j = 0; j < lenRever; j++) {
//			if (rever[j] == str[i + j]) {
//				counter++;
//			}
//
//		}		
//		if (counter == lenRever) {
//			return CONTAINED;
//		}
//		counter = 0;
//	}
//	return N_CONTAINED;
//}
//int AlreadySorted(char* sorted, char* str, int words) { 
//	// �������� ��������� ��� ������� ������� � ���������������� ����������� sorted
//	int f ; 
//	char tmp;
//	int j ;// ������� ��� ������
//	int k ;// ������� ��� ������
//	k = j = 0;
//	tmp = 0;
//	f = N_SORTED;
//	// ���� ������ ������, �� ����� = 0, � ���� �� ����������
//	for (int i = 0; i < words; i++) {
//		f = SORTED;
//		while (1) {
//			tmp = sorted[j];
//			if (tmp == ',' || tmp == '\0' ) {
//				break;
//			}
//			if (tmp != str[k++] ) {
//				f = N_SORTED;
//			}
//			j++;
//		}
//		if (f == SORTED && str[k]=='\0') {//������ ������� ��� ������� �����
//			return f;					// ��� ����� ���������, ������� ��� ���� � ������
//		}
//		k = 0;
//		j++; // ���������� �������
//		
//	}
//	return N_SORTED;
//}
//
//char* FindMirror(char const* str) {
//	int words;
//	char* tmp;
//	words = 0;
//	int len = StrLength(str);
//	char* sorted;
//	sorted = NULL;
//	for (int i = 0; i < len - 1; i++) {
//		for (int j = i + 1; j < len; j++) {
//			tmp = Reverse(str, i, j);
//			if (tmp == NULL) {
//				printf("error occured while reversing\n");
//				return NULL;
//			}
//
//			if (AlreadySorted(sorted, tmp, words) == N_SORTED && ContainedInOrigin(tmp, str) == CONTAINED) {
//				if (words == 0) {
//					sorted = tmp;
//				}
//				else {
//					sorted = Concatination(sorted, tmp, COMMA);
//				}
//				words++;
//			}
//		}
//	}
//
//	return sorted;
//}
//
//int main() {
//	char* sorted;
//	char* str;
//	setlocale(LC_CTYPE, "Russian");
//	printf("������� DTS-5: ����� ���������� ��������\n");
//	while (1) {
//		printf("������� ������: ");
//		str = ReadParagraph();
//		if (str == NULL) {
//			return 0;
//		}
//		sorted = FindMirror(str);
//		if (sorted == NULL) {
//			printf("error in FindMirror\n");
//			return 0;
//		}
//		printf("���������     : ");
//		printf("%s\n", sorted);
//		free(sorted);
//	}
//	free(sorted);
//	return 0;
//}