#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define ARR_SIZE 100

/*
	������� �������. 89013827902. vk.com/jevlogin

1. ����������� ������� �������� �� ���������� ������� � ��������, ��������� ��������.

2. ����������� ������� ���������� ����� a � ������� b:
	a. ��� ��������;
	b. ����������;
	c. *����������, ��������� �������� �������� �������.

3.* ����������� ����������� ����������� ����� �����, ���������� �� ������. � ����������� ��� �������, ������ ������� �������� �����:
	������� 1
	������ �� 2
������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� ����� � 2 ����. ������� ���������� ��������, ������� ����� 3 ����������� � ����� 20?
	�) � �������������� �������;
	�) � �������������� ��������.
*/

//	������ �������� ������� ��������, ����� �������� ���������
int bin[ARR_SIZE] = { 0 };
//	���-�� �������������� ���������
int size = 0;
//	����� ������������ ������������� ������� ���������, ������� � ��������� ��� ��� ���...
//	����������, �� ������ �� �����.
int k;
//	�������, ��� ��� ����� ������������ ��������
//	���������� ������� ����� � �������
int i;

int Ta = 1;

void binPrint();

void ConvertTwo(long N);

void convertToBin(long n);

long convertToBinRecursion(long n);

long PowerNotRecursion(int a, int b);

long PowerRecursion(int a, int b);

void Power(int a, int b);

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");

	//	���� ���������� ���������� �����������. ����� ����� ������� ���� �� ������������.
	long N;
	printf("������� ����� ��� ��������: ");
	if (!(scanf("%i", &N)) || N < 0)
	{
		fprintf(stderr, "�� ���������� ���� ��������.");
		return 1;
	}
	printf("����� ������ ��������� ���������:\n");

	ConvertTwo(N);
	getch();
	k = NULL;
	system("cls");

	printf("������� 2.\n\n");
	/*
		2. ����������� ������� ���������� ����� a � ������� b:
		a. ��� ��������;
		b. ����������;
		c. *����������, ��������� �������� �������� �������.
	*/
	int a, b;
	
	printf("������� ����� � ������� ����� ������: ");
	if (!(scanf("%i %i", &a, &b)))
	{
		fprintf(stderr, "�� ���������� ���� ��������.");
		return 1;
	}
	printf("����� ������ ��������� ���������:\n");
	
	Power(a, b);

	return 0;
}

void Power(int a, int b)
{
	do
	{
		printf("� ��������� (1) ��� ��� ��� (0)?'\n ������� '1' ��� '0'\n");
	} while (!(scanf("%i", &k)) || k > 1);
	if (k == 0)
	{
		system("cls");
		PowerNotRecursion(a, b);
	}
	else if (k == 1)
	{
		system("cls");
		PowerRecursion(a, b);
	}
	else
	{
		system("cls");
		fprintf(stderr, "�� ����� �������� ��������!\n K ����� ���� ����� ������ ��� 1, ��� 0.\n �� ����� %i\n", k);
	}
}

long PowerRecursion(int a, int b)
{
	if (b)
	{
		Ta *= a;
		b--;
		return PowerRecursion(a, b);
	}
	return printf("���������� ����� %li", Ta);
}

long PowerNotRecursion(int a, int b)
{
	long p = 1;
	int Tb = b;
	while (Tb)
	{
		p *= a;
		Tb--;
	}
	return printf("%i ^ %i = %li", a, b, p);
}

void ConvertTwo(long N)
{
	do
	{
		printf("� ��������� (1) ��� ��� ��� (0)?'\n ������� '1' ��� '0'\n");
	} while (!(scanf("%i", &k)) || k > 1);

	if (k == 0)
	{
		system("cls");
		convertToBin(N);
		binPrint();

	}
	else if (k == 1)
	{
		system("cls");
		convertToBinRecursion(N);
		binPrint();
	}
	else
	{
		system("cls");
		fprintf(stderr, "�� ����� �������� ��������!\n K ����� ���� ����� ������ ��� 1, ��� 0.\n �� ����� %i\n", k);
	}
}

void binPrint()
{
	int i;
	for (i = size - 1; i >= 0; i--)
		printf("%d", bin[i]);
	printf("\n");
}

void convertToBin(long n)
{
	int i = 0;
	while (n > 0)
	{
		bin[i++] = n % 2;
		n /= 2;
	}
	size = i;
}

long convertToBinRecursion(long n)
{
	if (n > 0)
	{
		bin[i++] = n % 2;
		return convertToBinRecursion(n / 2);
	}
	size = i;
}