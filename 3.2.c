#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/**
 * @brief считывает целое значение введенное с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
int Value();

/**
 * @brief считывает вещественное значение введенное с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double Double();

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double SumN(const int n);

/**
 * @brief рассчитывает сумму членов последовательности, с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double SumE(const double e);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param k текущий номер члена (начинается с 1 для a_1)
 * @param prev предыдущий член a_{k-1}
 * @return следующий член a_k
 */
double Recurent(const int k, const double prev);

/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Введите n: ");
    int n = Value();
    checkPositive(n);
    printf("Сумма %d чисел последовательности равна %.15f\n", n, SumN(n));

    printf("Введите e: ");
    double e = Double();
    checkPositive(e);
    printf("Сумма последовательности с точностью %e равна %.15f\n", e, SumE(e));

    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Ошибка! Введено неверное значение.\n");
        exit(1);
    }
    return value;
}

double Double()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Ошибка! Введено неверное значение.\n");
        exit(1);
    }
    return value;
}

double SumN(const int n)
{
    double current = 1.0;
    double result = current;

    for (int k = 2; k <= n; k++)
    {
        current = Recurent(k, current);
        result += current;
    }
    return result;
}

double SumE(const double e)
{
    double current = 1.0;  // a_1
    double result = 0;
    int k = 1;

    while (fabs(current) >= e)
    {
        result += current;
        k++;
        current = Recurent(k, current);
    }
    return result;
}

double Recurent(const int k, const double prev)
{
    return -prev / ((2.0 * k - 2.0) * (2.0 * k - 1.0));
}

void checkPositive(const double value)
{
    if (!(value > 0))
    {
        printf("Ошибка, число должно быть положительным!\n");
        exit(1);
    }
}
