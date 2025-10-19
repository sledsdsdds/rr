#include <stdio.h>
#include <stdlib.h>

/**
 * @brief рассчитывает объем параллелепипеда
 * @param length длина параллелепипеда
 * @param width ширина параллелепипеда  
 * @param height высота параллелепипеда
 * @return возвращает рассчитанный объем
 */
double getVolume(const double length, const double width, const double height);

/**
 * @brief рассчитывает площадь поверхности параллелепипеда
 * @param length длина параллелепипеда
 * @param width ширина параллелепипеда
 * @param height высота параллелепипеда
 * @return возвращает рассчитанную площадь поверхности
 */
double getSurfaceArea(const double length, const double width, const double height);

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет, что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    printf("Введите длину, ширину и высоту параллелепипеда: ");
    double length = getValue();
    checkValue(length);
    double width = getValue();
    checkValue(width);
    double height = getValue();
    checkValue(height);
    
    printf("Объем равен: %.2lf", getVolume(length, width, height));
    printf("Площадь поверхности равна: %.2lf", getSurfaceArea(length, width, height));

    return 0;
}

double getVolume(const double length, const double width, const double height)
{
    return length * width * height;
}

double getSurfaceArea(const double length, const double width, const double height)
{
    return 2 * (length * width + length * height + width * height);
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const double value)
{
    if (value <= 0 )
    {
        printf("Value have to be positive\n");
        abort();
    }
}
