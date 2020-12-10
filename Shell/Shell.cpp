// ConsoleApplication25.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <Windows.h>
int fastpow(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return a;
    else
    {
        int b = fastpow(a, n / 2);
        return b * b;
    }
}
void swap(int* a, int* b)
{
    int f = *a;
    *a = *b;
    *b = f;
}
int main()
{
    std::ifstream file;
    file.open("input.txt");
    int n, i = 1, k = 2;
    file >> n;
    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        file >> a[i];
    clock_t start = clock();
    while (i <= n)
    {
        for (int j = i; j < n; j++)
            for (int k = j - i; k >= 0 && a[k] > a[k + i]; k -= i)
                swap(&a[k], &a[k + i]);
        i = fastpow(2, k) - 1;
        k += 1;
    }
    start = clock() - start;
    std::ofstream file1;
    file1.open("output.txt");
    file1 << n << "\n";
    for (int i = 0; i < n; i++)
        file1 <<  a[i] << " ";
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
