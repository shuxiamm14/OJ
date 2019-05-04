//矩阵翻转
#include<iostream>
using namespace std;
int main(){
  int m,n,t;
  cin >> m >> n >> t ;
  int **array = new int *[m];
  for(int i = 0 ; i < m ; i++){
    array[i] = new int[n];
  }
  //
  for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < n; j++){
      cin >> array[i][j];
    }
  }
  //
  if(t == 0){
    for(int i=0;i<m;i++) {
      for(int j=0;j<n/2;j++) {
        int temp = array[i][j];
        array[i][j] = array[i][n-j-1];
        array[i][n-j-1] = temp;
      }
    }
  }

  if(t == 1){
    for(int i=0;i<m/2;i++) {
      for(int j=0;j<n;j++) {
        int temp = array[i][j];
        array[i][j] = array[m-i-1][j];
        array[m-i-1][j] = temp;
      }
    }

  }
  for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < n ; j++){
      cout << array[i][j] << " ";
      if(j + 1 == n){
        cout << endl;
      }
    }
  }
  for (int i=0;i<m;i++)
  {
    delete[] array[i]; //先撤销指针元素所指向的数组
  }
  delete[] array;
  return 0;
}
