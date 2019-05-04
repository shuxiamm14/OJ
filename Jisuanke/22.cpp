//计数与数数
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int same_count(string temp , int a , int b){
  int count = 1;
  for(int i = a ; i < b - 1 ; i ++){
    if(temp[i + 1] == temp[i]) count ++;
    if(temp[i + 1] != temp[i]) break;
  }
  return count;
}

int main(){
  int n;
  while(cin >> n && n >= 1 && n <= 30){
    string *array = new string[n];
    array[0] = "1";
    for(int i = 0 ; i < n ; i ++){//动态规划
      int size = array[i].size();
      for(int j = 0 ,c = same_count(array[i],j,size); j < size ; j += c ){
        //stringstream ss;
        //c = same(array[i],j,size);
        //ss << c ;
        //array[i + 1] = strcpy(c,array[i][j]);n>10出现栈溢出错误
        c = same_count(array[i],j,size);
        array[i + 1].push_back(c + '0');
        array[i + 1].push_back(array[i][j]);
      }
    }
    cout << array[n-1];
    cout << endl;
    delete []array;
  }
}
