//移除重复元素
#include<iostream>
using namespace std;

int num_delete(int *A,int n,int i){
  int count = 0 ;
  for(int j = i+1 ; j < n ; j ++){
    if(A[j] == A[i]){
      count ++;
    }
  }
  return count;
}


int main(){
  int n = 0;
  int A[1000] = {0};
  int sum_delete_count = 0;
  cin >> n ;
  if(n >= 1 && n <= 1000){
    for(int i = 0 ; i < n ; i++){
      cin >> A[i];
    }
    for(int i = 0 ; i < n ; i++){
      sum_delete_count += num_delete(A,n,i + sum_delete_count);
      for(int k = i + 1 ; k < i + 1 + num_delete(A,n,i) ; k++){
          A[k] = A[i + 1 + sum_delete_count];
      }
    }
    for(int i = n ; i > n - sum_delete_count + 1 ; i--){
      A[i] = 0;
    }
    cout << n - sum_delete_count;
    cout << endl;
  }
  for(int i = 0 ; i < n - sum_delete_count ; i++){
    cout << A[i] << " ";
  }

  return 0;
}
