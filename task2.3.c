#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/**
 * @brief проверка введенного значения
 * @return возвращает значение
 */
double Input(void);

/**
 * @brief рассчитывает площадь участка
 * @param siteHeight значение переменной длины участка
 * @param siteWidth значение переменной ширины участка
 * @return возвращает площадь участка
 */
double siteArea(const double siteHeight, const double siteWidth);

/**
 * @brief рассчитывает площадь первого дома
 * @param fHouseHeight значение переменной длины дома
 * @param fHouseWidth значение переменной ширины дома
 * @return возвращает площадь первого дома
 */
double firstArea(const double fHouseHeight, const double fHouseWidth);

/**
 * @brief рассчитывает площадь первого дома
 * @param sHouseHeight значение переменной длины дома
 * @param sHouseWidth значение переменной ширины дома
 * @return возвращает площадь первого дома
 */
double secondArea(const double sHouseHeight, const double sHouseWidth);

/**
 * @brief рассчитывает площадь первого дома
 * @param sHouseHeight значение переменной длины дома
 * @param sHouseWidth значение переменной ширины дома
 * @return возвращает площадь первого дома
 */
int houseFits(const double siteHeight, const double siteWidth, const double fHouseHeight, const double fHouseWidth, const double sHouseHeight, const double sHouseWidth);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void) {
    printf("Введите длину и ширину участка\n"); 
    const double siteHeight = Input();
    const double siteWidth = Input();
    printf("Введите длину и ширину первого дома\n");
    const double fHouseHeight = Input();
    const double fHouseWidth = Input();
    printf("Введите длину и ширину второго дома\n");
    const double sHouseHeight = Input();
    const double sHouseWidth = Input();
      if (houseFits(siteHeight, siteWidth, fHouseHeight, fHouseWidth, sHouseHeight, sHouseWidth)) {
        printf("Дома помещаются на участок.\n");
    } 
    else {
        printf("Дома не помещаются на участок.\n");
    }

    return 0;
}

double Input(void) 
{ 
    double value; 
    int result = scanf("%lf", &value);
    if (result != 1 || value < 0) {
        errno = EIO;
        perror("Input error!!!\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

double firstArea(const double fHouseHeight, const double fHouseWidth) {
    return fHouseHeight * fHouseWidth;
}

double secondArea(const double sHouseHeight, const double sHouseWidth) {
    return sHouseHeight * sHouseWidth;
}

double siteArea(const double siteHeight, const double siteWidth) {
    return siteHeight * siteWidth;
}

int houseFits(const double siteHeight, const double siteWidth, const double fHouseHeight, const double fHouseWidth, const double sHouseHeight, const double sHouseWidth) {
    double fHouseArea = firstArea(fHouseHeight, fHouseWidth);
    double sHouseArea = secondArea(sHouseHeight, sHouseWidth);
    double finalSiteArea = siteArea(siteHeight, siteWidth);
    //проверка площади
    if (fHouseArea + sHouseArea < finalSiteArea) {
        // оба дома вдоль стены участка
        if ((fHouseHeight + sHouseHeight <= siteHeight && fHouseWidth <= siteWidth && sHouseWidth <= siteWidth) || (fHouseWidth + sHouseWidth <= siteWidth && fHouseHeight <= siteHeight && sHouseHeight <= siteHeight)) {
            return 1;
        }
        //один из домов повернут на 90 градусов
        if ((fHouseHeight + sHouseWidth <= siteHeight && fHouseWidth <= siteWidth && sHouseHeight <= siteWidth) || (fHouseWidth + sHouseHeight <= siteWidth && fHouseHeight <= siteHeight && sHouseWidth <= siteHeight)) {
            return 1;
        }
    }
    else {
        return 0;
    }
}