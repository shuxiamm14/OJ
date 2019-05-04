//单独的数字
#include<iostream>
#include<string>
using namespace std;

int main(){
  int n = 0;
  int  a[500];
  cin >> n;
  if(n >= 1 && n <=500){
    for(int i = 0 ; i < n ; i ++){
      cin >> a[i];
    }
    for(int i = 0 ; i < n ; i ++){
      int count_left = 0;
      int count_right = 0;
      int index = i;
      for(int j = index + 1 ; j <= n - index; j++){
        if(a[index] == a[j]){
          count_right ++;
        }
      }
      for(int j = index - 1 ; j >= 0 ; j --){
        if(a[index] == a[j]){
          count_left ++;
        }
      }
      if(count_left == 0 && count_right == 0 ){
        cout << a[i] << " ";
      }
    }
  }
  cout << endl;
}
