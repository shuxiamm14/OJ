//质数判断
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n>1 && n <= 1000){
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(n%i == 0){
                count++;
            }
        }
        if(count == 2){
          cout << "YES";
        }
        else cout << "NO";
      }
}
