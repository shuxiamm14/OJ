#include <iostream>

using namespace std;

int gcd(int x, int y) {
    int t;
    while (y) {
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}
int main(int argc, char **argv) {
    int n;
    cin >> n;

    int a[10000] = { 0 };
    int b[10000] = { 0 };
    int t = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            if (gcd(i, j) == 1) {
                t++;
                a[t] = j;
                b[t] = i;
            }
        }
    }
    for (int i = 1; i <= t - 1; i++) {
        for (int j = i + 1; j <= t ; j++) {
            if (a[i] * b[j] > a[j] * b[i]) {
                int k;
                k = a[i];
                a[i] = a[j];
                a[j] = k;

                k = b[i];
                b[i] = b[j];
                b[j] = k;
            }
        }
    }
    cout << "0/1" << endl;
    for (int i = 1; i <= t; i++) {
        cout << a[i] << "/" << b[i] << endl;
    }
    cout << "1/1" << endl;
    return 0;
}
