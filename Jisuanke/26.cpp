#include<iostream>
using namespace std;

int main(){
  int N;
  int x, y, z = 0;
  while(cin >> N && N >= 1 && N <= 1000){
    int p[1000] = {0};
    for(int i = 0 ; i < N ; i ++){cin >> p[i];}
    int count1,count2,count3 = 0;
    for(int i = 0 ; i < N ; i ++){
      if(p[i] == 3){count3 ++;}
      if(p[i] == 2){count2 ++;}
      if(p[i] == 1){count1 ++;}
    }
    int count = 0;
    for(int i = 0 ; i < count1; i ++){
      if(p[i] != 1){x ++;}
    }
    for(int i = count1 ; i < count1 + count2; i ++){
      if(p[i] != 3){y ++;}
    }
    for(int i = count1 + count2 ; i < N; i ++){
      if(p[i] != 2){z++;}
    }
    if (y>z) x+=y;
    else x+=z;
    cout << x << endl;
  }

}
