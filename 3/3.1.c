#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>

/**
*@brief Считывает значение, введенное с клавиатуры с проверкой ввода
*@return считанное значение
*/
double value();

/**
*@brief Рассчитывает значение по заданной функции
*@param x значение переменной
*@return рассчитанное значение переменной или NAN при ошибке
*/
double func(const double x);

/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Введите начальное значение: ");
    double start = value();

    printf("Введите конечное значение: ");
    double end = value();

    printf("Введите шаг: ");
    double step = value();
    checkStep(step);

    double x = start;
    printf("\nРезультаты табулирования функции y = 0.1x^2 - x*ln(x):\n");

    while (x < end + DBL_EPSILON)
    {
        double y = func(x);
        if (isnan(y))
        {
            printf("x = %.2lf, y = не существует (x должен быть > 0)\n", x);
        }
        else
        {
            printf("x = %.2lf, y = %.4lf\n", x, y);
        }
        x = x + step;
    }

    return 0;
}

double value()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Вы ввели неверное значение!\n");
        abort();
    }
    return value;
}

void checkStep(const double step)
{
    if (step <= DBL_EPSILON)
    {
        printf("Ошибка, шаг должен быть положительным\n");
        abort();
    }
}

bool defineOOF(const double x)
{
    return x > 0;
}

double func(const double x)
{
    // Функция: y = 0.1x^2 - x*ln(x)
    // Область определения: x > 0 (логарифм определен только для положительных чисел)

    if (x <= 0)
    {
        return NAN; // Возвращаем "не число" для недопустимых значений
    }

    return 0.1 * pow(x, 2) - x * log(x);
}
