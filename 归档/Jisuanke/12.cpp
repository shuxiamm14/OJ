//整数转换成罗马数字
#include<iostream>
#include<string>
using namespace std;
#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000
//
int main(){
  char* digit[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
	char* ten[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	char* hundred[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC","DCCC","CM"};
	char* thousand[4] = {"","M","MM","MMM"};
  int num = 0;
  cin >> num ;
  if(num >= 1 && num <= 3999){
      int a, b, c ,d;
      a = num /1000;
      b = num % 1000 /100;
      c = num % 100 /10;
      d = num % 10;
      cout << thousand[a];
      cout << hundred[b];
      cout << ten[c];
      cout << digit[d];
  }
  return 0;
}
