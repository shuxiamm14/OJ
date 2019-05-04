#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n >= 1 && n <= 500){
    if(n == 1) cout << "true" << endl;
    else{
      int* A = new int[n];
      for(int i = 0 ; i < n ; i ++){
        cin >> A[i];
      }
      int p = 0;
      while(p != n - 1 ){
        if(A[p] == 0 && p != n - 1){cout << "false" << endl;break;}
        p += A[p];
        if( p == n - 1 ){cout << "true" << endl;}
      }
      delete [] A;
    }
  }
}
