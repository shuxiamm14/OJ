/* #include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n = 0;
    int matrix[6][5] = {0};
    while (scanf("%d", &n) != EOF)
    {
        if(n<=0||n>=1001){
            break;
        }
        else{
            for (int i = 2; i < 6; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    scanf("%d", &matrix[i][j]);
                }
            }
            for (int j = 0; j < 5; j++)
            {
                for (int k = 2; k < 4; k++)
                {
                    for (int i = 2; i < 7 - k; i++)
                    {
                        if (matrix[i][j] > matrix[i+1][j])
                        {
                            swap(matrix[i][j], matrix[i+1][j]);
                        }
                    }
                }
                matrix[0][j] = matrix[5][j];
                matrix[1][j] = matrix[4][j];
            }
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            n--;
            if(n<=0||n>=1001){
                break;
            }
        }
        
    }
    return 0;
}
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int i = 0, j = 0, k = 0;
    for (i = 0; i < n; i++)
    {
        int data[4][5];
        int con[2][5];
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 5; k++)
            {
                scanf("%d", &data[j][k]);
            }
        }
        int max[2];
        for (j = 0; j < 5; j++)
        {
            max[0] = data[0][j];
            max[1] = data[1][j];
            for (k = 2; k < 4; k++)
            {
                if (data[k][j] < max[0] && data[k][j] < max[1])
                {
                    ;
                }
                else if (data[k][j] <= max[0] && data[k][j] > max[1])
                {
                    max[1] = data[k][j];
                }
                else if (data[k][j] > max[0] && data[k][j] <= max[1])
                {
                    max[0] = max[1];
                    max[1] = data[k][j];
                }
                else if (data[k][j] > max[0] && data[k][j] > max[1])
                {
                    if (max[0] > max[1])
                    {
                        max[1] = data[k][j];
                    }
                    else
                    {
                        max[0] = max[1];
                        max[1] = data[k][j];
                    }
                }
            }
            con[0][j] = max[0];
            con[1][j] = max[1];
        }

        //输出结果
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 5; k++)
            {
                printf("%d ", con[j][k]);
            }
            printf("\n");
        }
    }
}