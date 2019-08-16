#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
void QSort(int a[], int low, int high)
{
    if (low >= high)
        return;
    int pivot = a[low], l = low, h = high;
    for (; l < h;)
    {
        for (; l < h && a[h] >= pivot; h--)
            ;
        a[l] = a[h];
        for (; l < h && a[l] <= pivot; l++)
            ;
        a[h] = a[l];
    }
    a[l] = pivot;
    QSort(a, low, l - 1);
    QSort(a, l + 1, high);
}
int main()
{
    int n = 0;
    int a[1001];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        QSort(a, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
