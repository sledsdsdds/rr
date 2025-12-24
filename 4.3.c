#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
 * @brief Ввод данных типа int
 * @return Введённое значение
 */
int getValue();
/**
 * @brief Ввод размера массива
 * @return размер массива
 */
size_t getSize(const char* message);
/**
 * @brief Создание массива
 * @return Созданный массив
 */
int** getArray(const size_t rows, const size_t columns);
/**
 * @brief Функция для очистки массива
 */
void freeArray(int** arr, const size_t rows);
/**
 * @brief Функция для заполнения массива с клавиатуры
 */
void fillmanual(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Функция для рандомного заполнения массива
 */
void fillrandom(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Функция для вывода массива
 */
void printArray(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Функция для замены минимального элемента стоблца на 0
 * @param tind - индекс строки, в которой находится минимальный элемент текущего столбца
 * @param tmin - минимальный элемент текущего столбца
 */
void minColumns(int** copy_arr, const size_t rows, const size_t columns);
/**
 * @brief Функция для копирования массива
 * @return Копированный массив
 */
int** copyArray(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Функция для нахождения максимального элемента двумерного массива
 * @param max - максимальный элемент двумерного массива
 * @return Максимальный элемент
 */
int maxArray(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Функция для нахождения кол-ва строк массива, содержащих максимальный элемент массива
 * @param cnt - кол-во этих строк
 * @param Flag - переменная "флаг"
 * @return Кол-во строк массива, содержащих хотя бы 1 максимальный элемент массива
 */
size_t cntMaxArray(int** arr, const size_t rows, const size_t columns, const int maxArr);
/**
 * @brief Функция для добавления последней строки массива после каждой из строк, в которых есть максимальный элемент
 * @param new_index - текущий индекс строки внутри массива
 * @param Flag - переменная "флаг"
 * @return Изменённый массив
 */
int** lastArray(int** copy_arr, const size_t rows, const size_t columns, const int maxArr, const size_t cntMax);
/**
 * @brief проверяет успешность выделения памяти
 * @param arr указатель для проверки
 * @note завершает программу при ошибке выделения памяти
 */
void checkArray(void* arr);
/**
* @brief RANDOM - рандомное заполнение массива
* @brief MANUAL - заполнение массива вручную с клавиатуры
*/
enum { RANDOM, MANUAL };
/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");
    size_t rows = getSize("Введите кол-во строк массива: ");
    size_t columns = getSize("Введите кол-во столбцов массива: ");
    int** arr = getArray(rows, columns);
    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами, %d - вручную с клавиатуры:\n", RANDOM, MANUAL);
    int choice = getValue();
    switch (choice)
    {
    case RANDOM:
        fillrandom(arr, rows, columns);
        break;
    case MANUAL:
        fillmanual(arr, rows, columns);
        break;
    default:
        printf("Error\n");
        freeArray(arr, rows);
        return 1;
    }
    printf("Исходный двумерный массив:\n");
    printArray(arr, rows, columns);
    int** copy_arr = copyArray(arr, rows, columns);
    minColumns(copy_arr, rows, columns);
    printf("Массив, где в каждом столбце минимальный элемент заменён на 0:\n");
    printArray(copy_arr, rows, columns);
    const int maxArr = maxArray(arr, rows, columns);
    const size_t cntMax = cntMaxArray(arr, rows, columns, maxArr);
    int** last_arr = lastArray(copy_arr, rows, columns, maxArr, cntMax);
    printf("Массив с вставленными последними строками после строк с максимальным элементом массива:\n");
    printArray(last_arr, rows + cntMax, columns);
    freeArray(arr, rows);
    freeArray(copy_arr, rows);
    freeArray(last_arr, rows + cntMax);
    return 0;
}

int getValue()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkArray(void* arr)
{
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
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

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = (int**)malloc(rows * sizeof(int**));
    void checkArray(void* arr);
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = (int*)malloc(columns * sizeof(int));
        checkArray(arr[i]);
    }
    return arr;
}

void freeArray(int** arr, const size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

void fillmanual(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Введите a[%zu,%zu] = ", i, j);
            arr[i][j] = getValue();
        }
    }
}

void fillrandom(int** arr, const size_t rows, const size_t columns)
{
    printf("Введите начало диапазона случайных чисел: ");
    int start = getValue();
    printf("Введите конец диапазона случайных чисел: ");
    int end = getValue();
    if (start <= end)
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                arr[i][j] = (rand() % (end - start + 1)) + start;
            }
        }
    }
    else
    {
        printf("Error\n");
        abort();
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void minColumns(int** copy_arr, const size_t rows, const size_t columns)
{
    for (size_t j = 0; j < columns; j++)
    {
        int tind = 0;
        int tmin = copy_arr[0][j];
        for (size_t i = 1; i < rows; i++)
        {
            if (copy_arr[i][j] < tmin)
            {
                tmin = copy_arr[i][j];
                tind = i;
            }
        }
        copy_arr[tind][j] = 0;
    }
}

int** copyArray(int** arr, const size_t rows, const size_t columns)
{
    int** copyArr = getArray(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            copyArr[i][j] = arr[i][j];
        }
    }
    return copyArr;
}

int maxArray(int** arr, const size_t rows, const size_t columns)
{
    int max = arr[0][0];
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

size_t cntMaxArray(int** arr, const size_t rows, const size_t columns, const int maxArr)
{
    size_t cnt = 0;
    for (size_t i = 0; i < rows; i++)
    {
        int Flag = 0;
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] == maxArr)
            {
                Flag = 1;
                break;
            }
        }
        if (Flag == 1)
        {
            cnt += 1;
        }
    }
    return cnt;
}

int** lastArray(int** copy_arr, const size_t rows, const size_t columns, const int maxArr, const size_t cntMax)
{
    int** last_arr = getArray(rows + cntMax, columns);
    size_t new_index = 0;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            last_arr[new_index][j] = copy_arr[i][j];
        }
        int containsMax = 0;
        for (size_t j = 0; j < columns; j++)
        {
            if (copy_arr[i][j] == maxArr)
            {
                containsMax = 1;
                break;
            }
        }
        if (containsMax)
        {
            new_index++;
            for (size_t j = 0; j < columns; j++)
            {
                last_arr[new_index][j] = copy_arr[rows - 1][j];
            }
        }
        new_index++;
    }

    return last_arr;
}
