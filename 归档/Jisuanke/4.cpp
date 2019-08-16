//斐波那契
#include<iostream>
using namespace std;
int fab(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    else return fab(n-1) + fab(n-2);
}
int main(){
    int n;
    cin >> n ;
    if( n >= 0 && n <= 50)
    {
        cout << fab(n) << endl;
    }
    return 0;
}
