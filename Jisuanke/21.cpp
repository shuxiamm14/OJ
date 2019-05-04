//排序后数组删除重复数字
#include<iostream>
using namespace std;

int main(){
  int n;
  while(cin >> n && n >= 1 && n <= 200){
    int *old_array = new int[n];
    for(int i = 0 ; i < n ; i ++){
      cin >> old_array[i];
    }
    int sum = n;
    int count = 1;
    for(int i = 0 ; i < n - 1 ; i += count){
      count = 1;
      for(int j = i + 1 ; j < n  && old_array[i] == old_array[j] ; j ++){
        count ++;
      }
      if(count >= 3){
        sum -= count - 2;
      }
    }
    cout << sum << endl;
  }
}
