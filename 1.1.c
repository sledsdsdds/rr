#define _USE_MATH_DEFINES // for C
#include <math.h>
#include <stdio.h>

/**
 * @brief Рассчитывает функцию В по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getB(const double x, const double y, const double z);

/**
 * @brief Рассчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getA(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x = 2.0;
    const double y = 0.7;
    const double z = -1.0;
    printf("A = %lf", getA(x, y, z));
    printf("B = %lf", getB(x, y, z));
    return 0;
}

double getA(const double x, const double y, const double z)
{
    return cbrt(x * y * z + fabs(z * sin(y)));
}

double getB(const double x, const double y, const double z)
{
    return y * cos(x * z * sin(y)) + 3;
}
