#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/**
 * @brief Ввод размера массива
 * @return размер массива
 */
size_t getSize(const char* message);

/**
 * @brief Ввод данных типа int
 * @return Введённое значение
 */
int getValue();

/**
 * @brief Функция рандоминого заполнения массива с клавиатуры
 * @return Заполненный массив
 */
void fillrandom(int* arr, const size_t size);

/**
 * @brief Функция для заполнения массива с клавиатуры
 * @return Заполненный массив
 */
void fillmanual(int* arr, const size_t size);

/**
 * @brief Функция для вывода массива
 * @return Массив
 */
void printArray(int* arr, const size_t size);

/**
 * @brief Функция для нахождения минимального по модулю положительного элемента массива
 * @param cqt – Промежуточный минимальный по модулю положительный элемент массива
 * @return Минимальный по модулю положительный элемент массива
 */
int minarr(int* arr, const size_t size);

/**
 * @brief Функция для замены минимального по модулю положительного элемента массива на 0
 * @param zamena – минимальный по модулю положительный элемент массива
 * @return Изменённый массив
 */
void zamena_arr(int* arr, const size_t size, int minimal);

/**
 * @brief Функция для копирования массива
 * @return Копированный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Функция, которая создаёт новый массив, в котором отсутствуют числа, первая и последняя цифра которых чётная
 * @return Этот массив
 */
void newArray(int* arr, int* new_arr, const size_t size, const int new_size);

/**
 * @brief Функция, которая считает новый массив по правилу: элементы c 3-его по 12-ый находятся по формуле A(i)=(-1)*(D(i)*D(i)), остальные по формуле A(i)=D(i)-1
 * @return Этот массив
 */
void lastArray(int* arrx, int* last_arr, const size_t size);

/**
* @brief RANDOM - рандоминое заполнение массива
* @brief MANUAL - заполнение массива вручную
*/
enum { RANDOM, MANUAL };

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");
    size_t size = getSize("Введите размер массива: ");
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Error\n");
        abort();
    }
    printf("Введите способ заполнения массива:\n %d = случайными числами, %d = вводом с клавиатуры \n", RANDOM, MANUAL);
    int choice = getValue();
    switch (choice)
    {
    case RANDOM:
        fillrandom(arr, size);
        break;
    case MANUAL:
        fillmanual(arr, size);
        break;
    default:
        printf("Error\n");
        free(arr);
        abort();
    }
    printf("Исходный массив:\n");
    printArray(arr, size);
    int minimal = minarr(arr, size);
    int* copy_arr = copyArray(arr, size);
    printf("Массив, где минимальный по модулю положительный элемент заменён на 0:\n");
    zamena_arr(copy_arr, size, minimal);
    int new_size = 1;
    int* new_arr = (int*)malloc(new_size * sizeof(int));
    if (new_arr == NULL)
    {
        printf("Error\n");
        abort();
    }
    printf("Массив, из которого удалены элементы, у которых первая и последняя цифры чётные:\n");
    newArray(arr, new_arr, size, new_size);
    int* last_arr = copyArray(arr, size);
    printf("новый массив по правилу: элементы с 3-его по 12-ый находятся по формуле A(i)=(-1)a(D(i)*D(i)), остальные по формуле A(i)=D(i)-1 \n");
    lastArray(arr, last_arr, size);
    free(arr);
    free(copy_arr);
    free(new_arr);
    free(last_arr);
    return 0;
}

size_t getSize(const char* message)
{
    printf("%s", message);
    int value = getValue();
    if (value <= 0)
    {
        printf("Error\n");
        abort();
    }
    return (size_t)value;
}

int getValue()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Error \n");
        abort();
    }
    return value;
}

void fillrandom(int* arr, const size_t size)
{
    printf("Введите начало диадозона: \n");
    int start = getValue();
    printf("Введите конец диадозона: \n");
    int end = getValue();
    for (size_t i = 0; i < size; i += 1)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

void fillmanual(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i += 1)
    {
        printf("Введите элемент массива: ");
        arr[i] = getValue();
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i += 1)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int minarr(int* arr, const size_t size)
{
    int cnt = arr[0];
    for (size_t i = 1; i < size; i += 1)
    {
        if ((arr[i] < cnt) && (arr[i] > 0))
        {
            cnt = arr[i];
        }
    }
    return cnt;
}

void zamena_arr(int* arr, const size_t size, int minimal)
{
    int zamena = minimal;
    for (size_t i = 0; i < size; i += 1)
    {
        if (arr[i] == zamena)
        {
            arr[i] = 0;
        }
    }
    printArray(arr, size);
}

int* copyArray(const int* apr, const size_t size)
{
    int* copyArr = (int*)malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i += 1)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

void newArray(int* arr, int* new_arr, const size_t size, int new_size)
{
    new_size -= 1;
    for (size_t i = 0; i < size; i += 1)
    {
        char number[20];
        sprintf_s(number, "%d", arr[i]);
        if (!(((arr[i] % 10) % 2 == 0) && (((int)number[0]) % 2 == 0)))
        {
            new_arr[new_size] = arr[i];
            new_size += 1;
        }
    }
    printArray(new_arr, new_size);
}

void lastArray(int* arr, int* last_arr, const size_t size)
{
    for (size_t i = 0; i < size; i += 1)
    {
        if ((i >= 2) && (i <= 11))
        {
            last_arr[i] = -1 * (arr[i] * arr[i]);
            continue;
        }
        last_arr[i] = arr[i] - 1;
    }
    printArray(last_arr, size);
}
