#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define ARR_SIZE 100

/*
	Логинов Евгений. 89013827902. vk.com/jevlogin

1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.

2. Реализовать функцию возведения числа a в степень b:
	a. без рекурсии;
	b. рекурсивно;
	c. *рекурсивно, используя свойство четности степени.

3.* Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
	Прибавь 1
	Умножь на 2
Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. Сколько существует программ, которые число 3 преобразуют в число 20?
	а) с использованием массива;
	б) с использованием рекурсии.
*/

//	задаем значение первого элемента, чтобы обнулить остальные
int bin[ARR_SIZE] = { 0 };
//	кол-во действительных элементов
int size = 0;
//	будем использовать инициализатор запуска алгоритма, решения с рекурсией или без нее...
//	изначально, он ничему не равен.
int k;
//	выносим, так как будем использовать рекурсию
//	Подключили русский шрифт в консоли
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

	//	Пока используем переменные статические. Позже будем просить ввод от пользователя.
	long N;
	printf("Введите число для перевода: ");
	if (!(scanf("%i", &N)) || N < 0)
	{
		fprintf(stderr, "Вы пропустили ввод значения.");
		return 1;
	}
	printf("Какой способ алгоритма выбираете:\n");

	ConvertTwo(N);
	getch();
	k = NULL;
	system("cls");

	printf("Задание 2.\n\n");
	/*
		2. Реализовать функцию возведения числа a в степень b:
		a. без рекурсии;
		b. рекурсивно;
		c. *рекурсивно, используя свойство четности степени.
	*/
	int a, b;
	
	printf("Введите число и степень через пробел: ");
	if (!(scanf("%i %i", &a, &b)))
	{
		fprintf(stderr, "Вы пропустили ввод значения.");
		return 1;
	}
	printf("Какой способ алгоритма выбираете:\n");
	
	Power(a, b);

	return 0;
}

void Power(int a, int b)
{
	do
	{
		printf("С рекурсией (1) или без нее (0)?'\n Введите '1' или '0'\n");
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
		fprintf(stderr, "Вы ввели неверное значение!\n K может быть равно только или 1, или 0.\n Вы ввели %i\n", k);
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
	return printf("Полученное Число %li", Ta);
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
		printf("С рекурсией (1) или без нее (0)?'\n Введите '1' или '0'\n");
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
		fprintf(stderr, "Вы ввели неверное значение!\n K может быть равно только или 1, или 0.\n Вы ввели %i\n", k);
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