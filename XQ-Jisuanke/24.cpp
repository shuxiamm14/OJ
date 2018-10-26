//两数之和
#include<iostream>
using namespace std;

int main(){
  int n = 0;
  while(cin >> n && n >= 1 && n <= 500){
    int *p = new int[n];
    for(int i = 1 ; i <= n ; i ++){
      cin >> p[i];
    }
    int target = 0;
    cin >> target;
    if(target >= 1 && target <= 1000){
      for(int i = 1 ; i <= n ; i ++){
        for(int j = i ; j <= n && p[i] + p[j+1] == target ; j ++){
          cout << i  << " " << j + 1 << endl;
        }
      }
    }

  }
}
