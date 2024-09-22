#include <stdio.h>
/**
* @brief рассчитывает выражение getDistance по формуле
* @param boatSpeed - значение константы скорости лодки
* @param riverSpeed - значение константы скорости реки
* @param time - значение константы времени
* @return рассчитанное значение
*/
double getDistance(const double boatSpeed, const double riverSpeed, const int time);

/**
* @brief Точка входа в программу.
* @return 0, в случае успеха.
*/
int main() {
    double boatSpeed, riverSpeed;
    int time;
    printf("Enter boat speed (km/h): ");
    scanf_s("%lf", &boatSpeed);
    printf("Enter river speed (km/h): ");
    scanf_s("%lf", &riverSpeed);
    printf("Enter total travel time (hours): ");
    scanf_s("%d", &time);
    double distance = getDistance(boatSpeed, riverSpeed, time);
    printf("Total travel: %.2f km\n", getDistance(boatSpeed, riverSpeed, time));

    return 0;
}

double getDistance(double boatSpeed, double riverSpeed, int time) {
    return ((riverSpeed + boatSpeed) * time);
}