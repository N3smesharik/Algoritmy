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
    long long int start = GetTickCount64();
    while (i <= n)
    {
        for (int j = i; j < n; j++)
            for (int k = j - i; k >= 0 && a[k] > a[k + i]; k -= i)
                swap(&a[k], &a[k + i]);
        i = fastpow(2, k) - 1;
        k += 1;
    }
    start = GetTickCount64() - start;
    std::ofstream file1;
    file1.open("output.txt");
    file1 << n << "\n";
    for (int i = 0; i < n; i++)
        file1 <<  a[i] << " ";
    file1 << "\n" << start;
    free(a);
}
