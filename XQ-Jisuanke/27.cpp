#include<iostream>
using namespace std;
int sum_N(int N){
  int sum = 0;
  while(N>=1){
    sum += N;
    N --;
  }
  return sum;
}
long long ans[10000];
int main(){
  int N;
  while(cin >> N && N >= 1 && N <= 39){
    int len = (N+1)*N/2;
    int half;
    if(len%2){
      cout << 0 << endl;
    }
    else{
      half = len/2;
		  ans[0] = 1;
		  for(int i = 1; i <= half; i++){
			     ans[i] = 0;
		  }
		  for(int i=1; i <= N; i++){
			   for(int j = half; j>=i; j--){
		         ans[j] += ans[j-i];
			   }
		  }
      cout << ans[half]/2 << endl;
      
    }
  }
}
