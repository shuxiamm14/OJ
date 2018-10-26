#include<iostream>
#include<cstring>
using namespace std;
bool is[125001];
int a[125001];
int main() {

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            is[i * i + j * j] = 1;
    int k = 0;
    for (int i = 0, z = m * m * 2; i <= z; ++i)
        if (is[i])
            a[k++] = i;
    int l = 1, ma = (m * m * 2 - 0) / (n - 1);
    int nu = 0;
    for (; l <= ma; ++l) {
        for (int i = 0; a[i] + (n - 1) * l <= m * m * 2 && i < k; ++i) {
            bool f = 1;
            for (int j = 1; j < n && f; ++j)  
                if (!is[a[i] + j * l]) {
                    f = 0;
                }
            if (f) {
                printf("%d %d\n", a[i], l);
                ++nu;
            }
        }
    }
    if (!nu)
        puts("NONE");
    return 0;
}
