#include <stdio.h>
#include <stdlib.h>

/**
* @brief считывает вещественное число
* @return возвращает вещественное число
*/
double input();

/**
* @brief рассчитывает значение абсолютной суммы трех чисел
* @param a - значение константы a
* @param b - значение константы b
* @param c - значение константы c
* @return рассчитанное значение
*/
double getAbsSum(const double a, const double b, const double c);

int main() {
	int negativeCount = 0;
	printf("Enter a: ");
	double a = input();
	printf("Enter b: ");
	double b = input();
	printf("Enter c: ");
	double c = input();
	if (a < 0) {
		negativeCount++;
	}
	if (b < 0) {
		negativeCount++;
	}
	if (c < 0) {
		negativeCount++;
	}
	printf("The ammount of negative numbers: %d\n", negativeCount);
	printf("The value of the absolute sum: %lf\n", getAbsSum(a,b,c));
}
double getAbsSum(const double a, const double b, const double c) {
	return abs(a+b+c);
}

double input() {
	double value = 0.0;
	int result = scanf_s("%lf", &value);
	if (result != 1) {
		perror("Invalid input!!!");
		abort();
	}
	return value;
}