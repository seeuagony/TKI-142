#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

/**
 * @brief Проверка введенного значения
 * @return Возвращает значение
 */
double input(void);

/**
 * @brief Считывает введенное целое значение
 * @return Возвращает считанное проверенное значение, иначе - ошибка
 */
int intInput(void);

/**
 * @brief Выводит сумму n элементов
 * @param n - количество элементов последовательности для суммирования
 * @return Рассчитанное значение
 */
double getSum(const int n);

/**
 * @brief Рассчитывает значение суммы всех членов последовательности, по модулю не меньше заданного числа e
 * @param e Значение заданного числа e
 * @return Рассчитанное значение суммы
 */
double getGreaterThanE(const double e);

/**
 * @brief Проверяет, что введенное целое число положительное
 * @return Возвращает считанное проверенное значение, иначе - ошибка
 */
int isPositiveInt(void);

/**
 * @brief Проверяет, что введенное число положительное
 * @return Возвращает считанное проверенное значение, иначе - ошибка
 */
double isPositiveDouble(void);

/**
 * @brief Рассчитывает следующий рекуррентный член последовательности
 * @param currentTerm Текущий член последовательности
 * @param k Текущий индекс элемента
 * @return Выводит рассчитанный следующий рекуррентный член последовательности
 */
double nextTerm(double current, int k);

/**
 * @brief Точка входа в программу 
 * @return 0 в случае успеха
 */
int main(void) {
    printf("Введите количество элементов последовательности (n): ");
    const int n = isPositiveInt();
    printf("Введите значение e (точность для модуля): ");
    const double e = isPositiveDouble();

    printf("Сумма первых %d членов последовательности: %.10lf\n", n, getSum(n));
    printf("Сумма членов последовательности, по модулю не меньше числа %.10lf: %.10lf\n", e, getGreaterThanE(e));

    return 0; 
}

double input(void) {
    double value = 0.0;
    int result = scanf("%lf", &value);
    if (result != 1) {
        errno = EIO;
        perror("Ошибка ввода!");
        exit(EXIT_FAILURE);
    }
    return value;
}
double isPositiveDouble(void) {
    double value = input();
    if (value <= DBL_EPSILON) {
        errno = EINVAL;
        perror("Число слишком маленькое или отрицательное!");
        exit(EXIT_FAILURE);
    }
    return value;
}

int intInput(void) { 
    int value = 0; 
    int result = scanf("%d", &value);
    if (result != 1) {
        errno = EIO;
        perror("Ошибка ввода");
        exit(EXIT_FAILURE);
    }
    return value;
}

int isPositiveInt(void) {
    int value = intInput();
    if (value <= 0) {
        errno = EINVAL;
        perror("Число должно быть положительным!");
        exit(EXIT_FAILURE);
    }
    return value;
}

double nextTerm(const double current, const int k) {
    return current * -1.0 * (2.0 + k) / (k + 1.0);
}

double getSum(const int n) {
    double sum = 0.0;
    double currentTerm = 1.0;
    for (int k = 0; k < n; k++) {
        sum += currentTerm;
        currentTerm = nextTerm(currentTerm, k);
    }
    return sum;
}

double getGreaterThanE(const double e) {
    double sum = 0.0;
    double currentTerm = 1.0;
    int k = 1;
    while (fabs(currentTerm) >= e+DBL_EPSILON) {
        sum += currentTerm;
        currentTerm = nextTerm(currentTerm, k);
        k++;
    }
    return sum;
}