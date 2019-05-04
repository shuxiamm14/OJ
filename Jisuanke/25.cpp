#include<iostream>
#include<vector>
using namespace std;
void swap(int &a,int &b){
  int temp = a;
  a = b;
  b = temp;
}
template <class T>
void shell_sort(T *a,int n){
  int len = n ;
  int h = 1;
  while(h < len / 3){
    h *= 3 ;
  }
  while(h >= 1){
    for(int i = h - 1 ; i < len ; i ++){
      for(int j = i ; j  >= h ; j -= h ){
        if(a[j] < a[j - h]){
          swap(a[j],a[j - h]);
        }
      }
    }
    h /= 3;
  }
}
int main(){
  int N = 0;
  int M = 0;
  cin >> N;
  cin >> M;
  int **p = new int*[M+1];
  for(int i = 0 ; i <= M ; i ++){
    p[i] = new int[M+1];
  }//二维数组初始化
  for(int i = 0 ; i <= M ; i ++){
    for(int j = 0 ; j <= M ; j ++){
      p[i][j] = i * i + j * j;
    }
  }//赋值
  cout << "#" << " ";
  for(int i = 0 ; i <= M ; i ++){
    cout << i << " ";
  }//格式化
  cout << endl;
  for(int i = 0 ; i <= M ; i ++){
    for(int j = 0 ; j <= M ; j ++){
      if(j == 0) cout << i << " ";
      cout << p[i][j] << " ";
      if(j == M){cout << endl;
      }
    }
  }//输出
  int *new_list = new int[(M+1)*(M+1)];
  for(int i = 0 ; i <= M ; i ++){
    for(int j = 0 ; j <= M ; j ++){
      new_list[i * (M + 1) + j] = i * i + j * j;
    }
  }//新数组
  cout << "##################" << endl;
  cout << "#" << " ";
  for(int i = 0 ; i <= M ; i ++){
    cout << i << " ";
  }//格式化
  cout << endl;
  for(int i = 0 ; i <= M ; i ++){
    for(int j = 0 ; j <= M ; j ++){
      if(j == 0) cout << i << " ";
      cout << new_list[i * (M + 1)+ j] << " ";
      if(j == M){cout << endl;
      }
    }
  }//输出
  shell_sort(new_list,(M+1)*(M+1));//希尔排序
  for(int i = 0 ; i <= (M+1)*(M+1) - 1 ; i ++){
    cout << new_list[i] << " ";
  }



  for (int i = 0;i <= M ; i ++){
    delete[] p[i]; //先撤销指针元素所指向的数组
  }
  delete[] p;
  delete[] new_list;//销毁
}
