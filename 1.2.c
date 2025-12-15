#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
 * @brief рассчитывает объем информации в килобайтах
 * @param bytes объем в байтах
 * @return возвращает объем в килобайтах
 */
double getKilobytes(const double bytes);

/**
 * @brief рассчитывает объем информации в мегабайтах
 * @param bytes объем в байтах
 * @return возвращает объем в мегабайтах
 */
double getMegabytes(const double bytes);

/**
 * @brief рассчитывает объем информации в гигабайтах
 * @param bytes объем в байтах
 * @return возвращает объем в гигабайтах
 */
double getGigabytes(const double bytes);

/**
 * @brief рассчитывает объем информации в терабайтах
 * @param bytes объем в байтах
 * @return возвращает объем в терабайтах
 */
double getTerabytes(const double bytes);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double bytes = 0;

    setlocale(LC_ALL, "Russian");
    printf("Введите объем информации в байтах: ");
    if (scanf_s("%lf", &bytes) != 1 || bytes <= 0)
    {
        printf("Ошибка! Введите положительное число.\n");
        return 1;
    }

    printf("\nРезультаты конвертации:\n");
    printf("Объем в байтах: %.2lf\n", bytes);
    printf("Объем в килобайтах: %.6lf\n", getKilobytes(bytes));
    printf("Объем в мегабайтах: %.6lf\n", getMegabytes(bytes));
    printf("Объем в гигабайтах: %.6lf\n", getGigabytes(bytes));
    printf("Объем в терабайтах: %.6lf\n", getTerabytes(bytes));

    printf("\nОбъяснение формул:\n");
    printf("1 Килобайт (КБ) = 1024 байта\n");
    printf("1 Мегабайт (МБ) = 1024 КБ = 1024 * 1024 байт\n");
    printf("1 Гигабайт (ГБ) = 1024 МБ = 1024 * 1024 * 1024 байт\n");
    printf("1 Терабайт (ТБ) = 1024 ГБ = 1024 * 1024 * 1024 * 1024 байт\n");

    return 0;
}

double getKilobytes(const double bytes)
{
    return bytes / 1024.0;
}

double getMegabytes(const double bytes)
{
    return bytes / (1024.0 * 1024.0);
}

double getGigabytes(const double bytes)
{
    return bytes / (1024.0 * 1024.0 * 1024.0);
}

double getTerabytes(const double bytes)
{
    return bytes / (1024.0 * 1024.0 * 1024.0 * 1024.0);
}
