// ConsoleApplication26.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <Windows.h>
void swap(int* a, int* b)
{
    int f = *a;
    *a = *b;
    *b = f;
}
void treesort(int* a, int n, int k)
{
    int max = a[k], L = a[2 * k + 1], R = a[2 * k + 2], c = 0;
    if (2 * k + 1 < n && max < L)
    {
        max = L;
        c = 1;
    }
    if (2 * k + 2 < n && max < R)
    {
        max = R;
        c = 2;
    }
    if (max != a[k])
    {
        if (c == 1)
        {
            swap(&a[k], &a[2 * k + 1]);
            treesort(a, n, 2 * k + 1);
        }
        else
        {
            swap(&a[k], &a[2 * k + 2]);
            treesort(a, n, 2 * k + 2);
        }
    }
}
void head(int* a, int n)
{

    for (int k = n / 2 - 1; k >= 0; k--)
    {
        treesort(a, n, k);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        treesort(a, i, 0);
    }
}
void quick(int* a, int n, int depth)
{
    int l = 0, r = n - 1, P = a[n / 2];
    if (depth <= 0)
        head(a, n);
    else
    {
        while (true)
        {
            while (a[l] < P || a[r] > P)
            {
                if (a[l] < P) l++;
                if (a[r] > P) r--;
            }
            if (l <= r)
            {
                swap(&a[l], &a[r]);
                l++;
                r--;
            }
            if (l > r)
                break;
        }
        if (r > 0)
            quick(a, r + 1, depth - 1);
        if (l < n)
            quick(&a[l], n - l, depth - 1);
    }
}
int main()
{
    std::ifstream file;
    file.open("input.txt");
    int n;
    file >> n;
    int depth = 2 * int(pow(n, 1 / 2)) + 1; 
    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        file >> a[i];
    clock_t start = clock();
    quick(a, n, depth);
    start = clock() - start;
    std::ofstream file1;
    file1.open("output.txt");
    file1 << n << "\n";
    for (int i = 0; i < n; i++)
        file1 << a[i] << " ";
    file1 << "\n" << start;
    free(a);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
