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
* @brief ввод значения шага с проверкой на положительность
* @return возвращает значение шага
*/
double inputStep(void);

/**
* @brief проверка значения x
* @param x значение переменной x
* @return успех - True, неудача - False
*/
bool xCheck(const double x);

/**
* @brief Функция, заданная формулой
* @param x значение переменной x
* @return возвращает значение функции в случае успеха
*/
double getY(const double x);

/**
* @brief Точка входа в программу
* @return Возвращает 0 в случае успеха
*/
int main(void) {
    printf("Введите начало и конец интервала: \n");
    const double iStart = input();
    const double iEnd = input();
    intervalCheck(iStart, iEnd);
    printf("Введите значение шага: ");
    const double step = inputStep();
    for (double x = iStart; x <= iEnd + DBL_EPSILON; x += step) {
        if (!xCheck(x)) {
            printf("Недопустимое значение x: %.3lf\n", x);
        } else {
            printf("x = %.3lf, y = %.3lf\n", x, getY(x));
        }
    }

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

void intervalCheck(const double iStart, const double iEnd) {
    if (iEnd - iStart < DBL_EPSILON) {
        errno = EIO;
        perror("Неверно введён интервал!!!");
        exit(EXIT_FAILURE);
    }
}

void stepCheck(const double step) {
    if (step <= DBL_EPSILON) {
        errno = EIO;
        perror("Неверно введён шаг!!!");
        exit(EXIT_FAILURE);
    }
}

double inputStep(void) {
    double step = input();
    stepCheck(step);
    return step;
}

bool xCheck(const double x) {
    if (x >= 1) {
        return false;
    }
    if (fabs(cos(x)) < DBL_EPSILON) { //тангенс будет неопределён, если его косинус будет равен нулю
        return false;
    }

    return true;
}

double getY(const double x) {
    return sqrt(1 - x) - tan(x);
}