#include <stdio.h>

/**
* @brief рассчитывает дистанцию, которую прошла лодка
* @param boatSpeed - значение константы скорости лодки
* @param riverSpeed - значение константы скорости реки
* @param time - значение константы времени
* @return рассчитанное значение
*/
double getDistance(const double boatSpeed, const double riverSpeed, const double time);

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
    printf("Enter boat speed (km/h): ");
    double boatSpeed = Input();
    printf("Enter river speed (km/h): ");
    double riverSpeed = Input();
    printf("Enter total travel time (hours): ");
    double time = Input();
    printf("Total travel: %.2f km\n", getDistance(boatSpeed, riverSpeed, time));

    return 0;
}

double getDistance(const double boatSpeed, const double riverSpeed, const double time) {
    return ((riverSpeed + boatSpeed) * time);
}
double Input() {
    double value = 0.0;
    int result = scanf_s("%lf", &value);
    if (result != 1) {
        perror("Invalid input!");
    }
    return value;
}