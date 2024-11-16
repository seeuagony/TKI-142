#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

/**
 * @brief проверка введенного значения
 * @return возвращает значение
 */
double input(void);

/**
 * @brief Считывает введеное целое значение
 * @return возвращает считанное проверенное значение, иначе - ошибка
 */
int intInput(void);

/**
 * @brief Выводит сумму n элементов
 * @param n - числа элементов последовательности для суммирования
 * @return - рассчитанное значение
 */
double getSum(const int n);

/**
 * @brief рассчитывает значение суммы всех членов последовательности, не меньше заданного числа е
 * @param n кол-во элементов последовательности
 * @param e значение заданного числа е
 * @return рассчитанное значение суммы
 */
double getLessThanE(const int n, const double e);

/**
 * @brief проверяет считанное число на положительность
 * @return возвращает считанное проверенное значение, иначе - ошибка
 */
int isPositiveInt(void);

/**
 * @brief проверяет считанное число на положительность
 * @return возвращает считанное проверенное значение, иначе - ошибка
 */
double isPositiveDouble(void);

/**
 * @brief рассчитывает следующий рекуррентный член последовательности
 * @param currentTerm текущий член последовательности
 * @param k текущий индекс элемента
 * @return выводит рассчитанный следующий рекуррентный член последовательности
 */
double nextTerm(double current, int a);

/**
 * @brief точка входа в программу 
 * @return 0 в случае успеха
 */
int main(void) {
    printf("Введите количество элементов последовательности: ");
    const int n = isPositiveInt();
    printf("Введите значение e: ");
    const double e = isPositiveDouble();
    printf("Сумма первых %d членов последовательности: %.3lf\n", n, getSum(n));
    printf("Сумма членов последовательности, по модулю не меньше числа e: %.3lf\n", getLessThanE(n, e));

    return 0; 
}

double input(void) {
    double value = 0.0;
    int result = scanf("%lf", &value);
    if (result != 1) {
        errno = EIO;
        perror("Input error!");
        exit(EXIT_FAILURE);
    }
    return value;
}

int intInput(void) { 
    int value = 0; 
    int result = scanf("%d", &value);
    if (result != 1) {
        errno = EIO;
        perror("Input error");
        exit(EXIT_FAILURE);
    }

    return value;
}

int isPositiveInt(void) {
    int value = intInput();
    if (value < 0) {
        errno = EINVAL;
        perror("Input is negative!");
        exit(EXIT_FAILURE);
    }
    return value;
}

double isPositiveDouble(void) {
    double value = input();
    if (value < DBL_EPSILON) {
        errno = EINVAL;
        perror("Input is too small or negative!");
        exit(EXIT_FAILURE);
    }
    return value;
}

double nextTerm(double current, int k) {
    return current * -(1.0 + k) / (k + 1);
}

double getSum(const int n) {
    double sum = 0.0;
    double currentTerm = 1.0;
    for (int k = 0; k <= n; k++) {
        sum += currentTerm;
        currentTerm = nextTerm(currentTerm, k);
    }
    return sum;
}

double getLessThanE(const int n, const double e) {
    double sum = 0.0;
    double currentTerm = 1.0;
    for (int k = 0; k <= n; k++) {
        if (fabs(currentTerm) < e) {
            break; 
        }
        sum += currentTerm;
        currentTerm = nextTerm(currentTerm, k);
    }
    return sum;
}