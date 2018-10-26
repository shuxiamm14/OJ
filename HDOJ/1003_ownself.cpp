#include <iostream>
#define N_max 100000
using namespace std;
int main() {
/* code */
  int T = 1;
  int N = 1;
  int count = 1;
  cin >> T ;
  while (count <= T && T <= 20){
    cin >> N ;
    int m[N_max];
    int sum[N_max];
    if(N >= 1 && N <= N_max){
      for (int i = 0 ; i < N ; i++){
        cin >> m[i];
        if(i == 0) {
          sum[i] = m[i];
        }
        else{
          sum[i] = m[i] + sum[i - 1];
        }
      }
      cout << "Case " <<  count <<":" << endl ;
      for(int i = 0 ; i < 1 ; i++){
        int index = i ;
        for(int j = i ; j < N - i ; j ++){
          if(sum[index] < sum[j + 1]){
            index = j + 1 ;
          }

        }
        if(index != i){
          int temp = sum[i];
          sum[i] = sum[index];
          sum[index] = temp;
          cout << sum[i] << " "<< i + 1 <<" "<< index + 1 << endl ;
        }
      }
      cout << endl ;
    count ++;
    }
  }
  return 0 ;
}
