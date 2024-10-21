#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h> 
#include <errno.h>

/**
 * @brief проверка введенного значения
 * @return возвращает значение
 */
double input(void);

/**
 * @brief рассчитывает значение функции по формуле
 * @param x значение переменной x
 * @return возвращает рассчитанное значение функции, при x < 2
 */
double firstOperation(const double x, const double a);

/**
 * @brief рассчитывает значение функции по формуле
 * @param x значение переменной x
 * @return возвращает рассчитанное значение фукнции, при x >= 2
 */
double secondOperation(const double x, const double a);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void) {
    const double a = 1.36;
    printf("Enter x: ");
    const double x = input();
    if (x < 0.5) {
        printf("Function value = %lf", firstOperation(x, a));
    }
    else {
        printf("Function value = %lf", secondOperation(x, a));
    }
    return 0;
}

double input(void) 
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

double firstOperation(const double x, const double a) { 
    return ((M_PI)/2 + x*a - exp(a*x));
}

double secondOperation(const double x, const double a) { 
    return (pow(x, 3)*a + 28);
}