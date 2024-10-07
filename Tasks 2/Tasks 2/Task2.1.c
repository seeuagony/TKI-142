#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

typedef enum {
    getNegatives,
    getAbsoluteSum
} opType;

/**
 * @brief считает число отрицательных чисел
 * @param a значение параметра a
 * @param b значение параметра b
 * @param c значение параметра c
 * @return количество отрицательных чисел
 */
int countNegatives(double const a, double const b, double const c);

/**
 * @brief считает абсолютную сумму чисел
 * @param a значение параметра a
 * @param b значение параметра b
 * @param c значение параметра c
 * @return абсолютную сумму чисел, округленную до целого
 */
int absoluteSum(double const a, double const b, double const c);

/**
 * @brief Считывает вещественное число
 * @return возвращает вещественное число
 */
double input(void);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void) {
    printf("Enter a: ");
    double a = input();
    printf("Enter b: ");
    double b = input();
    printf("Enter c: ");
    double c = input();
    int check = 0; 
    printf("Select the type of operation: \n1 - Calculate the number of negative numbers\n2 - Calculate the absolute sum\n");
    scanf("%d", &check); 
    if (check != 1 && check != 2) { 
        printf("Operation selection error!\n");
        return 1; 
    }
    switch (check) {
        case 1: 
            printf("Number of negative numbers = %d\n", countNegatives(a, b, c));
            break;
        case 2: 
            printf("Absolute sum = %d\n", absoluteSum(a, b, c));
            break;
        default:
        errno = ERANGE;
        perror("Function not mentioned");
        exit(EXIT_FAILURE);
    }
    return 0;
}

double input() {
    double value = 0.0;
    int result = scanf_s("%lf", &value);
    if (result != 1) {
        errno = EIO;
        perror("Invalid input!!!");
        exit(EXIT_FAILURE);
    }
    return value;
}

int countNegatives(double const a, double const b, double const c) {
    int negativeCount = 0;
    if (a < 0) negativeCount++;
    if (b < 0) negativeCount++;
    if (c < 0) negativeCount++;
    return negativeCount;
}

int absoluteSum(double const a, double const b, double const c) {
    return fabs(a + b + c);
}