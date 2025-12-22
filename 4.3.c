#include <stdio.h>
#include <stdlib.h>

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
 * @param rows - кол-во строк двумерного массива
 * @param columns - кол-во столбцов двумерного массива
 * @return Созданный массив
 */
int** getArray(const size_t rows, const size_t columns);

/**
 * @brief Функция для очистки массива
 * @param arr - исходный двумерный массива
 * @param rows - кол-во строк двумерного массива
 */
void freeArray(int** arr, const size_t rows);

/**
 * @brief Функция для заполнения массива с клавиатуры
 * @param arr - исходный двумерный массив
 * @param rows - кол-во строк двумерного массива
 * @param columns - кол-во столбцов двумерного массива
 */
void fillManual(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Функция для рандомного заполнения массива
 * @param arr - исходный двумерный массив
 * @param rows - кол-во строк двумерного массива
 * @param columns - кол-во столбцов двумерного массива
 */
void fillRandom(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Функция для вывода массива
 * @param arr - исходный двумерный массив
 * @param rows - кол-во строк двумерного массива
 * @param columns - кол-во столбцов двумерного массива
 */
void printArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Функция для замены минимального элемента стоблца на 0
 * @param copy_arr - копированный исходный двумерный массив
 * @param rows - кол-во строк двумерного массива
 * @param columns - кол-во столбцов двумерного массива
 */
void minColumns(int** copy_arr, const size_t rows, const size_t columns);

/**
 * @brief Функция для копирования массива
 * @param arr - исходный двумерный массив
 * @param rows - кол-во строк двумерного массива
 * @param columns - кол-во столбцов двумерного массива
 * @return Копированный массив
 */
int** copyArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Функция для нахождения максимального элемента двумерного массива
 * @param @param arr - исходный двумерный массив
 * @param rows - кол-во строк двумерного массива
 * @param columns - кол-во столбцов двумерного массива
 * @return Максимальный элемент двумерного массива
 */
int maxArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Функция для нахождения кол-ва строк массива, содержащих максимальный элемент массива
 * @param @param arr - исходный двумерный массив
 * @param rows - кол-во строк двумерного массива
 * @param columns - кол-во столбцов двумерного массива
 * @param maxArr - максимальный элемент двумерного массива
 * @return Кол-во строк массива, содержащих хотя бы 1 максимальный элемент массива
 */
size_t cntMaxArray(int** arr, const size_t rows, const size_t columns, const int maxArr);

/**
 * @brief Функция для добавления последней строки массива после каждой из строк, в которых есть максимальный элемент
 * @param copy_arr - копированный исходный двумерный массив
 * @param rows - кол-во строк двумерного массива
 * @param columns - кол-во столбцов двумерного массива
 * @param maxArr - максимальный элемент двумерного массива
 * @param cntMax - сколько раз встречается максимальный элемент двумерного массива в строке
 * @return Изменённый массив
 */
int** lastArray(int** copy_arr, const size_t rows, const size_t columns, const int maxArr, const size_t cntMax);

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
    size_t rows = getSize("Введите кол - во строк массива : ");
    size_t columns = getSize("Введите кол-во столбцов массива: ");
    int** arr = getArray(rows, columns);

    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами, %d - вручную с клавиатуры:\n", RANDOM, MANUAL);
    int choice = getValue();

    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, rows, columns);
        break;
    case MANUAL:
        fillManual(arr, rows, columns);
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

size_t getSize(char* message)
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
    int** arr = malloc(rows * sizeof(int*));
    if (arr == NULL)
    {
        printf("Error\n");
        exit(1);
    }

    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = malloc(columns * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Error\n");
            exit(1);
        }
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

void fillManual(int** arr, const size_t rows, const size_t columns)
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

void fillRandom(int** arr, const size_t rows, const size_t columns)
{
    printf("Введите начало диапазона случайных чисел: ");
    int start = getValue();
    printf("Введите конец диапазона случайных чисел: ");
    int end = getValue();

    if (start < end)
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
    int** copyArr = malloc(rows * sizeof(int*));
    if (copyArr == NULL)
    {
        printf("Error\n");
        exit(1);
    }

    for (size_t i = 0; i < rows; i++)
    {
        copyArr[i] = malloc(columns * sizeof(int));
        if (copyArr[i] == NULL)
        {
            printf("Error\n");
            exit(1);
        }
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
    int new_index = 0;

    for (size_t j = 0; j < columns; j++)
    {
        last_arr[new_index][j] = copy_arr[new_index][j];
    }
    new_index += 1;

    int Flag = 0;
    for (size_t j = 0; j < columns; j++)
    {
        if (copy_arr[new_index][j] == maxArr)
        {
            Flag = 1;
            break;
        }
    }

    if (Flag == 1)
    {
        for (size_t j = 0; j < columns; j++)
        {
            last_arr[new_index][j] = copy_arr[rows - 1][j];
        }
        new_index += 1;
    }
    return last_arr;
}
