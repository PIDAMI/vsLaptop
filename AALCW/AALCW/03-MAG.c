#pragma warning(disable:4996)
#include "AALCW.h"

 /*03 MAG ���������� �����
 ������: �������� ���������, ������� ���� ���������� ����� �����, ����������
 ��������� ��������� : ����� ������������� �� 2, � ���� ��� ����� ����������� �
 ������, �� ��������� ����� � 2 ���� ������� : x...yz2 * 2 = 2x...yz.*/



//int main() {
//	int t = 2;
//	int rest = 0;
//	int counter = 0;
//	int arr[50];
//	while (!(t == 2 && rest == 0 && counter != 0)) {
//		if ((t *= 2) > 9) {
//			t %= 10;
//			t += rest;
//			printf("%d ", t);
//			rest = 1;
//		}
//		else {
//			t += rest;
//			printf("%d ", t);
//			rest = 0;
//		}
//		arr[counter] = t;
//		counter++;
//	}
//	printf("\nnumber of digits: %d\n", counter);
//	printf("the answer: ");
//	for (int i = counter - 1; i >= 0; i--) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}