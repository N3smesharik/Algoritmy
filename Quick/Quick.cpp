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
void quick(int* a, int n)
{
    int l = 0, r = n - 1, P = a[n / 2];
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
        quick(a, r + 1);
    if (l < n)
        quick(&a[l], n - l);
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
    clock_t start = clock();
    quick(a, n);
    start = clock() - start;
    std::ofstream file1;
    file1.open("output.txt");
    file1 << n << "\n";
    for (int i = 0; i < n; i++)
        file1 << a[i] << " ";
    file1 << "\n" << start * 1000000;
    free(a);
}