#pragma warning(disable:4996)
#include "AALCW.h"
/*
02 XPR ���������� ��������� 
 ������: �������� ���������, ���������������� ���������� �� �������� �������.
 ������ ������� � ���������������� �������� � �������������, ������������
 ������� ������ �����.


 ������ �����: "�������� ����� ������� ������ ���������
 �������� (if) �� �������������� ����������� ���������."
 � ������� ���� �� ����� ���� ��������, ������� 
 ������ ������������(����� ������ ���������� ������� �������� ���������)
 */

//int main() {
//	
//	double l, m, ro, d;
//	const double pi = 3.14159;
//	// ���������� ��� �������� �������� ����������
//	ro = 500.0;
//	l = 10.0;
//	m = 240.0;
//	d = 2 * sqrt(m / (pi * l * ro)); 
//	printf("Mass is %lf\n", m);
//	printf("Length is %lf\n", l);
//	printf("Density is %lf\n", ro);
//	printf("Diameter is %lf\n", d);
//
//	// ���������� ��� ����������, ���������� �� ������ �����, ��� ��������
//	printf("Enter mass of the stick: ");
//	scanf("%lf", &m);
//	printf("Enter length of the stick: ");
//	scanf("%lf", &l);
//	printf("Enter density of the stick: ");
//	scanf("%lf", &ro);
//	d = 2 * sqrt(m / (pi * l * ro));
//	printf("Diameter of the stick is %lf\n", d);
//	
//	// ���������� ��� ����������, ���������� �� ������ �����
//	// ��� ������������ ������� - ����� �� ���������
//	printf("Enter mass of the stick in range from 0.01 to 1000: ");
//	scanf("%lf", &m);
//	if (m > 1000 || m < 0.01) {
//		printf("\nNot appropriate value for mass");
//		return 1;
//	}
//
//	printf("Enter length of the stick in range from 0.0001 to 13500: ");
//	scanf("%lf", &l);
//	if (l > 13500 || l < 0.0001) {
//		printf("\nNot appropriate value for length");
//		return 1;
//	}
//
//	printf("Enter density of the stick in range from 0.01 to 100000: ");
//	scanf("%lf", &ro);
//	if (ro > 100000 || l < 0.01) {
//		printf("\nNot appropriate value for density");
//		return 1;
//	}
//
//	d = 2 * sqrt(m / (pi * l * ro));
//	printf("Diameter of the stick is %lf\n", d);
//
//	//���������� ��� ����������, ���������� �� ������ �����
//	// ������ �� ��� ���, ���� �� ����� ������� ���������� ��������
//	printf("Enter mass of the stick in range from 0.01 to 1000: ");
//	do {
//		scanf("%lf", &m);
//	} while (m > 1000 || m < 0.01);
//
//	printf("Enter length of the stick in range from 0.0001 to 13500: ");
//	do {
//		scanf("%lf", &l);
//	} while (l > 13500 || m < 0.0001);
//
//
//	printf("Enter density of the stick in range from 100000 to 0.01: ");
//	do {
//		scanf("%lf", &ro);
//	} while (ro > 100000 || ro < 0.01);
//
//	d = 2 * sqrt(m / (pi * l * ro));
//	printf("Diameter of the stick is %lf\n", d);
//	return 0;
//}