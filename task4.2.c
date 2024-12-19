#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>

/**
 *@param manual реализация способа заполнения массива числами, которые вводит пользователь
* @param random реализация способа заполнения массива рандомными(случайными) числами
*/
enum opetation {
    fillManually,
    fillRandomly
};

/**
 * @brief функция, считывающая вводимое значение
 * @return введенное значение
 */
int input(void);

/**
 * @brief функция, проверяющая ввод на положительность
 * @param value вводимое число
 * @return Возвращает: число, если число положительно; ошибку, если число отрицательно
 */
size_t posInput(void);

/**
 * @brief функция, которая создаёт массив размером n
 * @param n размер массива
 * @return созданный массив
 */
int* createArr(const size_t n);

/**
 * @brief функция, проверяющая корректность адреса указателя массива
 * @param arr массив
 * @return Возвращает ошибку, если потерялась память
 */
void checkArr(const int* arr);

/**
 * @brief функция, которая выводит массив пользователю
 * @param arr указатель на наш массив
 * @param n размер массива
 * @return наш массив
 */
void printArr(const int* arr, const size_t n);

/**
 * @brief функция, которая позволяет пользователю заполнить массив самостоятельно
 * @param arr массив
 * @param n количество элементов в массиве
 * @return массив, заполненный пользователем самостоятельно
 */
void fillArrManually(int* arr, const size_t n);

/**
 * @brief функция, которая позволяет пользователю заполнить массив с помощью случайных чисел
 * @param arr массив
 * @param n количество элементов в массиве
 * @return массив, заполненный случайными числами
 */
void fillArrRandomly(int* arr, const size_t n);

/**
 * @brief функция, которая копирует элементы из одного массива в новый
 * @param arr исходный массив
 * @param n размер массива
 * @return новый копированный массив, который повторяет исходный
 */
int* copyArr(const int* arr, const size_t n);

/**
 * @brief функция, заменяющая последний элемент, который делится на 3, нулём
 * @param arr исходный массив
 * @param n размер массива
 */
void replaceLastMultipleOfThree(int* arr, const size_t n);

/**
 * @brief функция, которая вычисляет новый размер массива
 * @param arr исходный массив
 * @param n количество элементов в массиве
 * @return новый размер массива
 */
size_t findNewSize(const int* arr, const size_t n);

/**
 * @brief функция, которая вставляет число K после всех четных элементов
 * @param arr массив
 * @param n количество элементов в массиве
 * @param k число, которое нужно вставлять
 * @return измененный массив
 */
int* insertKAfterEven(const int* arr, size_t n, const int k);


/**
 * @brief  Из элементов массива P формирует массив M 
 * @param array массив P (исходный)
 * @param M массив M
 * @param n количество элементов в массиве
 * @return массив M
 */
void arrFromPtoM(const int* arr, int* M, const size_t n);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
int main(void) { 
    printf("Введите размер массива: ");
    size_t n = posInput();
    printf("Введите число K: ");
    const int k = input();
    int* arr = createArr(n);
    printf("Как вы хотите заполнить массив? \n%d - Самостоятельно \n%d - Рандомными числами\n", fillManually, fillRandomly);
    int operation = input();
    switch(operation) {
        case fillManually:
            fillArrManually(arr, n);
            break;
        case fillRandomly:
            fillArrRandomly(arr, n);
            break;
        default:
            free(arr);
            errno = ERANGE;
            perror("Неверно введена функция");
            exit(EXIT_FAILURE);
            break;
    }
    printf("Исходный массив: ");
    printArr(arr, n);
    int* copiedArr = copyArr(arr, n);
    printf("\nМассив после замены: ");
    replaceLastMultipleOfThree(copiedArr, n);
    printArr(copiedArr, n);
    free(copiedArr);
    size_t newSize = findNewSize(arr, n);
    int* arrWithK = insertKAfterEven(arr, n, k);
    printf("\nМассив, после каждого чётного числа - число K ");
    printArr(arrWithK, newSize);
    free(arrWithK);
    int* M = createArr(n);
    arrFromPtoM(arr, M, n);
    printf("\nМассив M по заданному правилу: ");
    printArr(M, n);
    free(M);
    free(arr);

    return 0;
}

int input(void) {
    int value = 0;
    int res = scanf("%d", &value);
    if (res != 1) {
        errno = EIO;
        perror("Ошибка ввода (число должно быть целым)");
        exit(EXIT_FAILURE);
    }
    return value;
}

size_t posInput(void) {
    int value = input();
    if (value <= 0) {
        errno = EINVAL;
        perror("Ошибка ввода (число должно быть положительным)");
        exit(EXIT_FAILURE);
    }
    return (size_t)value;
}

int* createArr(const size_t n) {
    int* arr = (int*)malloc(n * sizeof(int));
    checkArr(arr);
    return arr;
}

void checkArr(const int* arr) {
    if (arr == NULL) {
        errno = ENOMEM;
        perror("Ошибка памяти, адрес указателя на массив оказался нулевым");
        exit(EXIT_FAILURE);
    }
}

void printArr(const int* arr, const size_t n) {
    checkArr(arr);
    for (size_t i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) { 
                printf(", ");
            }
    }
}

void fillArrManually(int* arr, const size_t n) {
    checkArr(arr);
    for (size_t i = 0; i < n; i++) {
        printf("Введите элемент %zu: ", i + 1);
        arr[i] = input();
    }
}

void fillArrRandomly(int* arr, const size_t n) {
    checkArr(arr);
    printf("Введите минимальное значение интервала \n");
    int min = input();
    printf("Введите максимальное значение интервала \n");
    int max = input();
    if (min > max) {
        errno = EINVAL;
        perror("У вас неправильно заданы границы интервала: конец должен быть меньше начала");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    for (size_t i = 0; i < n; i++) {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
}

int* copyArr(const int* arr, const size_t n) {
    checkArr(arr);
    int* copiedArr = createArr(n);
    for (size_t i = 0; i < n; i++) {
        copiedArr[i] = arr[i];
    }
    return copiedArr;
}

void replaceLastMultipleOfThree(int* arr, const size_t n) {
    checkArr(arr);
    for (size_t i = n; i > 0; i--) {
        if (arr[i - 1] % 3 == 0) {
            arr[i - 1] = 0;
            break;
        }
    }
}

size_t findNewSize(const int* arr, const size_t n) {
    checkArr(arr);
    size_t count = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    size_t newSize = n + count;
    return newSize;
}

int* insertKAfterEven(const int* arr, size_t n, const int k) {
    size_t newSize = findNewSize(arr, n);
    int* arrWithK = createArr(newSize);
    checkArr(arr);
    size_t a = 0;
    
    for (size_t i = 0; i < n; i++) {
        arrWithK[a++] = arr[i];
        if (arr[i] % 2 == 0) {
            arrWithK[a++] = k; 
        }
    }
    return arrWithK;
}

void arrFromPtoM(const int* array, int* M, const size_t n) {
    M[0] = 0;
    M[n - 1] = 0;
    for (size_t i = 1; i < n-1; i++) {
        if ((i + 1) % 4 == 0) {
            M[i] = 4 * abs(array[i]);
        }
        else {
            M[i] = -array[i] * (i + 1);
        }
    }
}