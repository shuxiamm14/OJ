#include <iostream>
using namespace std;

int maxsum(int *a,int n){
  int *p = new int[n];
  int max = a[0];
  int sum = 0;
  for(int i = 0 ; i < n ; i ++){
    if(sum >= 0){
      sum += a[i];//只要和大于0继续求和
    }
    else{
      sum = a[i];//如果上一次出现和小于0，清空，并置为当前数
    }
    if(sum > max){
      max = sum;//和保存在了max
    }
  }
  return max;

}

int main(){
  int n = 0;
  while(cin >> n && n >= 1 && n <= 1000){
    int *array = new int[n];
    for(int i = 0 ; i < n ; i ++){
      cin >> array[i];
    }
    cout << maxsum(array,n) << endl;
  }
  return 0;
}
