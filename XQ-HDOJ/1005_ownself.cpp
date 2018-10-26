#include<iostream>
using namespace std;

int func(int a,int b,int n){
  int _a = a;
  int _b = b;
  int _n = n;
  if(_n == 1 || _n == 2) return 1;
  else{
    int out = (_a * func(_a,_b,_n -1) + _b * func(_a,_b,_n - 2)) % 7;
    return out;
  }
}

int main(){
  int a = 0;
  int b = 0;
  int n = 0;
  while(cin >> a && cin >> b && cin >> n)
  {
    if(a >= 1 && a <= 1000&& b >= 1&& b <= 1000 && n >= 1 && n <= 100000000){

      int out = func(a,b,n);
      cout << out << endl;
    }
  }
}
