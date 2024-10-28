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
double getY(double x);

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
    const double step = input();
    stepCheck(step);
    for (double x = iStart; x <= iEnd + DBL_EPSILON; x += step) {
        if (!xCheck(x)) {
            printf("Неверно введено значение x!");
        }
        else {
            printf("x = %.3lf, y = %.3lf\n", x, getY(x));
        }
    }


}

double input(void) {
    double value = 0.0;
	int result = scanf("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Input error!");
		exit(EXIT_FAILURE);
	}
	xCheck(value);
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

bool xCheck(const double x) {
	return x > DBL_EPSILON;
}

double getY(const double x) {
    return (sqrt(1-x) - tan(x));
}