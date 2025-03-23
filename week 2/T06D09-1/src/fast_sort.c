#include <stdio.h>

int inputed(float *a, int size);
int decimal(float a);
int sorted(int *a, int size);
int print(int *a, int size);
int sorted_q(int *a, int left, int right);
int sorted_h(int *a, int size);

int main()
{
    float a[10] = {0};
    int b[10] = {0};
    int c[10] = {0};
    int error = 0;
    int n = 10;

    if (!inputed(a, n))
        error = 1; // проверим на нормальный ввод массив

    for (int i = 0; i < n; i++)
    { // скопируем массив в b,c
        a[i] = (int)a[i];
        b[i] = a[i];
        c[i] = a[i];
    }

    if (sorted_q(c, 0, n - 1))
    { // проверим сортировку c
        print(c, n);
    }
    else
    {
        error = 1;
    }
    printf("\n");

    if (sorted_h(b, n))
    { // проверим сортировку b
        print(b, n);
    }
    else
    {
        error = 1;
    }

    if (error)
    {
        printf("n/a");
    }
    return 0;
}

int decimal(float a)
{
    if (a != (int)a)
    {
        return 0;
    }
    else
    {
        a = (int)a;
        return 1;
    }
}

int inputed(float *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!scanf("%f", &a[i]) || !decimal(a[i]))
        {
            return 0;
        }
    }
    return 1;
}

int sorted(int *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int p = 0; p < size - i - 1; p++)
        {
            if (a[p] > a[p + 1])
            {                    // сравниваем два соседних элемента.
                int tmp = a[p];  // если они идут в неправильном порядке, то
                a[p] = a[p + 1]; // меняем их местами.
                a[p + 1] = tmp;
            }
        }
    }
    return 1;
}

int sorted_q(int *a, int left, int right)
{
    int pivot = a[left]; // разрешающий элемент
    int l_hold = left;   // левая граница
    int r_hold = right;  // правая граница

    while (left < right)
    { // пока границы не сомкнутся
        // сдвигаем правую границу пока элемент [right] больше [pivot]
        while ((pivot <= a[right]) && (left < right))
            right--;

        if (left != right)
        {                       // если границы не сомкнулись
            a[left] = a[right]; // перемещаем элемент [right] на место разрешающего
            left++;             // сдвигаем левую границу вправо
        }

        while ((a[left] <= pivot) && (left < right))
            left++; // двигаем левую границу пока a[left] меньше a[pivot]

        if (left != right)
        {                       // если границы не сомкнулись
            a[right] = a[left]; // перемещаем элемент [left] на место [right]
            right--;            // сдвигаем правую границу вправо
        }
    }
    a[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    // Рекурсивно вызываем sorted_q для левой и правой части массива
    if (left < pivot)
        sorted_q(a, left, pivot - 1);
    if (right > pivot)
        sorted_q(a, pivot + 1, right);

    return 1;
}

void seed(int *a, int vertex, int bottom)
{                 // Функция "просеивания" через кучу - формирование кучи
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована

    while ((2 * vertex <= bottom) && (!done))
    { // Пока не дошли до последнего ряда
        if (2 * vertex == bottom)
        {
            maxChild = 2 * vertex; // если мы в последнем ряду, запоминаем левый потомок
        }
        else if (a[2 * vertex] > a[2 * vertex + 1])
        { // иначе запоминаем больший потомок из двух
            maxChild = 2 * vertex;
        }
        else
        {
            maxChild = 2 * vertex + 1;
        }

        if (a[vertex] < a[maxChild])
        {                         // если элемент вершины меньше максимального потомка
            int temp = a[vertex]; // меняем их местами
            a[vertex] = a[maxChild];
            a[maxChild] = temp;
            vertex = maxChild;
        }
        else
        {
            done = 1; // иначе пирамида сформирована
        }
    }
}

int sorted_h(int *a, int size)
{
    for (int i = (size / 2); i >= 0; i--) // Формируем нижний ряд пирамиды
        seed(a, i, size - 1);             // Просеиваем через пирамиду остальные элементы
    for (int i = size - 1; i >= 1; i--)
    {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        seed(a, 0, i - 1);
    }
    return 1;
}

int print(int *a, int size)
{
    int p;
    for (p = 0; p < size; p++)
    {
        printf("%d ", (int)(a[p]));
    }
    return 1;
}