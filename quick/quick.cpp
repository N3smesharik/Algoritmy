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
    int c = 0, max = a[k];
    if (2 * k + 1 < n)
    {
        int L = a[2 * k + 1];
        if (max < L)
        {
            max = L;
            c = 1;
        }
    }
    if (2 * k + 2 < n)
    {
        int R = a[2 * k + 2];
        if (max < R)
        {
            max = R;
            c = 2;
        }
    }
    if (max != a[k])
    {
        if (c == 1)
        {
            swap(&a[k], &a[2 * k + 1]);
            treesort(a, n, 2 * k + 1);
        }
        else if (c == 2)
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
int main()
{
    std::ifstream file;
    file.open("input.txt");
    int n;
    file >> n;
    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        file >> a[i];
    int start = GetTickCount64();
    head(a, n);
    start = GetTickCount64() - start;
    std::ofstream file1;
    file1.open("output.txt");
    file1 << n << "\n";
    for (int i = 0; i < n; i++)
        file1 << a[i] << " ";
    file1 << "\n" << start;
    free(a);
    return 0;
}