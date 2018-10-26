//加一
#include<iostream>
using namespace std;
int ten_pow(int in){
  int out = 1;
  for(int i = 0 ; i < in ; i ++){
    out *= 10;
  }
  return out;
}

int main(){
  int n = 0;
  cin  >> n ;
  if(n >= 1 && n <= 100){
    int *p = new int[n + 1];
    for(int i = n - 1 ; i >= 0 ; i --){
      cin >> p[i];
    }
    p[0] ++;
    p[n] = 0;
    for(int i = 0; i < n ; i ++){
      if(p[i] == 10){
        p[i] = 0;
        p[i + 1] += 1;
      }
    }
    if(p[n - 1] == 0 ){
      p[n] = 1;
    }


  if(p[n] == 0){
    for(int i = n - 1 ; i >= 0 ; i --){
      cout << p[i] << " ";
      if( (i+1) % 10 == 0){cout << endl;}
    }
  }

  if(p[n] == 1){
    for(int i = n ; i >= 0 ; i --){
      cout << p[i] << " ";
      if( (i+1) % 10 == 0){cout << endl;}
      }
    }
  }
  return 0;
}
