//最大子阵列
#include<iostream>
using namespace std;
void swap(int &a,int &b){
  int temp = a ;
  a = b ;
  b = temp;
}

int sum_compare(int *a , int n){
  int *temp = new int[n];
  int *sum_max = new int[n];
  for(int i = 0 ; i < n ; i ++){
    temp[i] = 0;
    sum_max[i] = 0;
  }
  for(int i = 0 ; i < n ; i ++ ){
    for(int j = n - 1 ; j >= i ; j --){
      for(int k = j; k >= i ; k --){
        temp[j] += a[k];
      }
    }//求取和并放入数组
    for(int m = i ; m < n - 1; m ++){
      sum_max[i] = temp[m] > temp[m+1] ? temp[m]:temp[m+1];
    }//求取本层最大值
    for(int h = i ; h < n; h ++){
      temp[h] = 0;
    }//清零
  }

  int max;
  for(int i = 0 ; i < n - 1; i ++){
    max = sum_max[i] > sum_max[i+1] ? sum_max[i]:sum_max[i+1];
  }//求最大值
  return max;
}

int main(){
  int n = 0;
  while(cin >> n && n <= 1000 && n >= 0){
    int *maxarray = new int[n];
    for(int i = 0 ; i < n ; i ++){
      cin >> maxarray[i];
    }
    cout << sum_compare(maxarray,n) << endl;
    delete []maxarray;
  }
}
