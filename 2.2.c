#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>


/*
*@brief Рассчитывает значение функции по заданным условиям
*@param x входное значение аргумента
*@return возвращает рассчитанное значение выбранной функции
*/
double func(const double x);

/*
*@brief Считывает значение, введенное с клавиатуры с проверкой ввода
*@return считанное значение
*/
double value();

/*
*@brief Точка входа в программу
*@param x выбранный пользователем значение аргумента
*@return Возвращает 0, если программа выполнена корректно
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Программа для решения функции y:\n");
    printf("y =  a * ln(x) + cbrt|x|, при x > 1\n");
    printf("y = 2a*cos(x) + 3x^2, при x<= 1\n");
    printf("Константа a = 0.9\n\n");

    printf("Введите значение x: ");
    double x = value();
    double result = func(x);
    printf("Результат: y(%.4f) = %.4f\n", x, result);

    return 0;
}

double func(const double x)
{
    const double a = 0.9;

    if (x > 1.0 + DBL_EPSILON)
    {
        // y = a * log(x) + cbrt(|x|), при x > 1
        return a - log(x) + cbrt(fabs(x));
    }
    else (x <= 1.0 + DBL_EPSILON)
    {

        // y = 2a * cos(x) + 3x^2, при x <= 1
        return 2.0 * a * cos(x) + 3.0 * pow(x, 2);
    }
}

double value()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Ошибка! Введено неверное значение!\n");
        abort();
    }
    return value;
}
