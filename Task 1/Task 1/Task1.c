#include <stdio.h>
#include <math.h>

/**
* @brief рассчитывает выражение A по формуле
* @param x - значение константы х
* @param y - значение константы y
* @param a - значение константы z
* @return рассчитанное значение
*/
double getA(double const x, double const y, double const z);

/**
* @brief рассчитывает выражение B по формуле
* @param x - значение константы х
* @param y - значение константы y
* @param a - значение константы z
* @return рассчитанное значение
*/
double getB(double const x, double const y, double const z);

/**
* @brief Точка входа в программу.
* @return 0, в случае успеха.
*/
int main() {

	const double x = 0.3;
	const double y = 2.9;
	const double z = 0.5;
	printf("%f\n", getA(x, y, z));
	printf("%f", getB(x, y, z));

	return 0;
}

double getA(const double x, const double y, const double z) {
	return ((pow(z, 2) * x) + ((pow(exp(1.0), -x)) * (cos(y * x)))) / y*x - pow(exp(1.0), -x)*sin(y*x) + 1;
}
double getB(const double x, const double y, const double z) {
	return (pow(exp(1.0), 2 * x) * log(z + x)) - (pow(y, 3 * x) * log(y - x));
}
