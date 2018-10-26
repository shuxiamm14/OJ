//元素移除
#include<iostream>
using namespace std;

int removeElement(int *A, int n, int elem){
  int num_delete = 0;
  for ( int i = 0 ; i < n ; i++){
    if(A[i]==elem){num_delete++;}
  }
  return n - num_delete;
}

int main(){
  int n;
  int elem_delete = 0;
  int A[100];
  cin >> n ;
  if(n <= 100 && n >= 1){
    for(int i = 0 ; i < n ; i ++){
      cin >>A[i];
    }
    cin >> elem_delete;
    int length = removeElement(A, n, elem_delete);
    cout << length ;
    cout << endl;

  }
}
