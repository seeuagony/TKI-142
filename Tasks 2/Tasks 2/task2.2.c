#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <errno.h>
#define PI 3.14159265358979323846
/**
 * @brief проверка введенного значения
 * @return возвращает значение
 */
double input();

/**
 * @brief рассчитывает значение функции по формуле
 * @param x значение переменной x
 * @return возвращает рассчитанное значение функции, при x < 2
 */
double getA(const double x, const double a);

/**
 * @brief рассчитывает значение функции по формуле
 * @param x значение переменной x
 * @return возвращает рассчитанное значение фукнции, при x >= 2
 */
double getB(const double x, const double a);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void) {
    const double a = 1.36;
    printf("Enter x: ");
    const double x = input();
    if (x < 0.5) {
        printf("Function value = %lf", getA(x, a));
    }
    else {
        printf("Function value = %lf", getB(x, a));
    }
    return 0;
}

double input() 
{ 
    double value; 
    int result = scanf("%lf", &value);
    if (result != 1) {
        errno = EIO;
        perror("Input error!!!\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

double getA(const double x, const double a) { 
    return (PI/2 + x*a - exp(a*x));
}

double getB(const double x, const double a) { 
    return (pow(x, 3)*a + 28);
}