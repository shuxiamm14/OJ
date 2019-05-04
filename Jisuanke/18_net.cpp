#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int *a = new int[n + 1]();
    int i;
    for(i = 1; i <= n; ++i){
        cin >> a[i];
    }
    i = n;
    a[i] += 1;
    while(a[i] > 9){
        a[i] = 0;
        ++a[--i];
    }
    for(i = a[0] ? 0 : 1; i <= n; ++i){
        cout << a[i] << " ";
    }
}
