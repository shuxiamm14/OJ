#include<iostream>
using namespace std;
#define N 101
int main()
{
    int n = 0;
    int matrix[N][N];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                cout << matrix[j][i] << " ";
            }
            cout << matrix[n - 1][i] << endl;
        }
    }

    return 0;
}