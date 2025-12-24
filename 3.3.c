#include <float.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <locale.h>

/**
 * @brief считывает вещественное значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble();

/**
 * @brief Проверяет, что минимальное значение меньше максимального
 * @param min минимальное значение промежутка
 * @param max максимальное значение промежутка
 */

void checkMinMax(const double min, const double max);

/**
 * @brief Проверяет, что шаг функции больше нуля.
 * @param step значение шага функции
 */

void checkStep(const double step);
/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */

void checkPositive(const double value);
/**
 * @brief Вычисляет экспоненту в степени 2х
 * @param x значение параметра x
 * @return экспоненциальное значение аргумента
 */

double e_Func(const double x);
/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @param x значение параметра x
 * @return рассчитанное значение коэффициента
 */

double getRecurent(const int i, const double x);
/**
 * @brief рассчитывает сумму членов последовательности с точностью e
 * @param e заданная точность
 * @param x значение параметра x
 * @return рассчитанное значение
 */

double getSumE(const double e, const double x);
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */

int main(void)

{
    setlocale(LC_ALL, "Russian");
    printf("Введите минимум: \n");
    const double min = getDouble();
    printf("Введите максимум: \n");
    const double max = getDouble();
    checkMinMax(min, max);
    printf("Введите шаг: \n");
    const double step = getDouble();
    checkStep(step);
    printf("Введите е: \n");
    double e = getDouble();
    checkPositive(e);

    for (double x = min; x < max + step; x += step)

    {
        printf("x = %.6lf, e^2x = %.6lf, S = %.6lf\n", x, e_Func(x), getSumE(e, x));

    }
    return 0;

}

double getDouble()

{
    double value = 0;
    if (!scanf_s("%lf", &value))

    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

void checkMinMax(const double min, const double max)

{
    if (fabs(min - max) <= DBL_EPSILON)

    {
        printf("Error\n");
        exit(1);
    }

}

void checkStep(const double step) 
{
    if (step <= DBL_EPSILON)

    {
        printf("Error\n");
        exit(1);
    }
}

void checkPositive(const double value)

{
    if (value < -DBL_EPSILON)
    {
        printf("Error\n");
        exit(1);
    }
}

double e_Func(const double x)
{
    return exp(2 * x);
}

double getRecurent(const int i, const double x)
{
    return 2 * x / (i + 1);
}

double getSumE(const double e, const double x)
{
    double current = 1;
    double result = current;
    for (int i = 1; fabs(current) > e; i++)
    {
        current *= getRecurent(i, x);
        result += current;
    }
    return result;
}
