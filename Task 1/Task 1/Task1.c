#include <stdio.h>

/**
* @brief рассчитывает количество теплоты, которое было израсходовано
* @param weight - значение константы веса тела
* @param firstTemp - значение константы начальной температуры
* @param secondTemp - значение константы конечной температуры
* @return рассчитанное значение
*/
double getHeatAmmount(const double weight, const double firstTemp, const double secondTemp);

/**
* @brief считывает вещественное число
* @return возвращает вещественное число
*/
double Input();

/**
* @brief Точка входа в программу.
* @return 0, в случае успеха.
*/
int main() {
    printf("Enter weight: ");
    double weight = Input();
    printf("Enter initial temperature: ");
    double firstTemp = Input();
    printf("Enter the final temperature: ");
    double secondTemp = Input();
    printf("Heat ammount of steel: %.2f", getHeatAmmount(weight, firstTemp, secondTemp));

    return 0;
}


double getHeatAmmount(const double weight, const double firstTemp, const double secondTemp)
{
    const double steelConst = 500;
    return steelConst*weight * (secondTemp-firstTemp);
}

double Input() {
    double value = 0.0;
    int result = scanf_s("%lf", &value);
    if (result != 1) {
        perror("Invalid input!");
    }
    return value;
}