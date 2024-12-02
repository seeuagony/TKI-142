#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <float.h>

/**
 * @brief проверка введенного значения
 * @return возвращает значение
 */
double input(void);

/**
* @brief проверка значений интервала
* @param iStart начало интервала
* @param iEnd конец интервала
* @return ошибка, если интервал некорректный
*/
void intervalCheck(const double iStart, const double iEnd);

/**
* @brief проверяет значение шага
* @param step значение шага
* @return ошибка, если шаг некорректный
*/
void stepCheck(const double step);

/**
* @brief Вызвает функцию y = (e^a - e^(-a)) / 2
* @param a значение переменной a
* @return Возвращает значение функции
*/
double getFunc(const double a);

/**
* @brief Рассчитывает значение следующего элемента ряда
* @param a значение переменной a
* @param n индекс элемента последовательности
* @return Возвращает значение следующего элемента ряда
*/
double nextElement(const double previous, const double a, const int n);

/**
* @brief Рассчитывает значение суммы ряда с точностью доepsilon
* @param a значение переменной a
* @param eps значение величины точности
* @return Возвращает значение суммы ряда
*/
double getSum(const double a, const double eps);

/**
* @brief Точка входа в программу
* @return Возвращает 0 в случае успеха
*/
int main(void)
{
    const double eps = pow(20, -4);
    printf("Введите начало интервала: ");
    const double iStart = input();
    printf("Введите конец интервала: ");
    const double iEnd = input();
    intervalCheck(iStart, iEnd);
    printf("Введите значение шага: ");
    const double step = input();
    stepCheck(step);

    printf("%-10s %-15s %-15s\n", "a", "f(a)", "S(a)");
    for (double a = iStart; a <= iEnd + DBL_EPSILON; a += step) {
        printf("%-6.2f %-10.6f %-10.6f\n", a, getFunc(a), getSum(a, eps));
    }

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

void intervalCheck(const double iStart, const double iEnd) {
    if (iEnd <= iStart) {
        errno = EINVAL;
        perror("Неверно введён интервал");
        exit(EXIT_FAILURE);
    }
}

void stepCheck(const double step) {
    if (step <= DBL_EPSILON) {
        errno = EINVAL;
        perror("Неверно введен шаг или его (шага) значение слишком мало");
        exit(EXIT_FAILURE);
    }
}

double getFunc(const double a) {
    return (exp(a) - exp(-a)) / 2.0;
}

double nextElement(const double previous, const double a, const int n) {
    return previous * (a * a) / ((2 * n) * (2 * n + 1));
}

double getSum(const double a, const double eps) {
    double element = getFunc(a);
    double sum = 0.0;
    int n = 0;
    while (fabs(element) > eps) {
        sum += element;
        element = nextElement(sum, a, ++n);
    }
    return sum;
}
