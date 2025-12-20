#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
* @brief Выводит приветствие в зависимости от времени суток
* @param hour час времени (тип int)
* @return не возвращает значения (void)
*/
void print_greeting(const int hour);

/*
* @brief Проверяет корректность введённого часа
* @param hour час времени (тип int)
* @return возвращает 1 если час корректный, 0 если нет (тип int)
*/
int is_valid_hour(const int hour);

/*
* @brief Точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int hour;
    int value;
    printf("Введите время суток в часах (0-23): ");
    value = scanf_s("%d", &hour);

    if (value == 1)
    {
        if (is_valid_hour(hour))
        {
            printf("Время: %d:00\n", hour);
            print_greeting(hour);
        }
        else
        {
            printf("Неверное значение: час должен быть от 0 до 23\n");
        }
    }
    else
    {
        printf("Неверное значение: введите целое число\n");
    }

    return 0;
}

int is_valid_hour(const int hour)
{
    return (hour >= 0 && hour <= 23);
}

void print_greeting(const int hour)
{
    if (hour >= 6 && hour <= 11)
    {
        printf("Доброе утро!\n");
    }
    else if (hour >= 12 && hour <= 17)
    {
        printf("Добрый день!\n");
    }
    else if (hour >= 18 && hour <= 23)
    {
        printf("Добрый вечер!\n");
    }
    else if (hour >= 0 && hour <= 5)
    {
        printf("Доброй ночи!\n");
    }
}
