#include <stdio.h>
#include <locale.h>

/*
* @brief Рассчитывает общее сопротивление при последовательном соединении
* @param r1 сопротивление первого резистора (тип double)
* @param r2 сопротивление второго резистора (тип double)
* @param r3 сопротивление третьего резистора (тип double)
* @return возвращает общее сопротивление (тип double)
*/
double total_resistance(const double r1, const double r2, const double r3);

/*
* @brief Точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    double r1, r2, r3;
    int value1, value2, value3;

    printf("Введите сопротивление R1: ");
    value1 = scanf_s("%lf", &r1);

    printf("Введите сопротивление R2: ");
    value2 = scanf_s("%lf", &r2);

    printf("Введите сопротивление R3: ");
    value3 = scanf_s("%lf", &r3);

    if (value1 == 1 && value2 == 1 && value3 == 1)
    {
        if (r1 > 0 && r2 > 0 && r3 > 0)
        {
            double total = total_resistance(r1, r2, r3);  // переменная для общего сопротивления (тип double)
            printf("Общее сопротивление при последовательном соединении: %.2lf Ом\n", total);
        }
        else
        {
            printf("Неверное значение: сопротивления должны быть положительными\n");
        }
    }
    else
    {
        printf("Неверное значение: введите числа\n");
    }

    return 0;
}
double total_resistance(const double r1, const double r2, const double r3)
{
    return r1 + r2 + r3;
}
