#include<iostream>
#include<cmath>
using namespace std;

int pow(int x){
  return x * x;
}
int sqrt(int x)
{
    int x1=0;
    int x2=2 * x;
    double sq=0;
    while((x2-x1)>1)
    {
        if(sq*sq<x)
        {
            x1=sq;
            sq=(x1+x2)/2;
        }
        else if(sq*sq>x)
        {
            x2=sq;
            sq=(x1+x2)/2;
        }
        else
            return sq;
    }
    return sq;
}//没有AC
int sqrt_n(int x){
      double t = 1.0;
      while(fabs(t * t - x) > 1e-6){
          t = (t + x / t) / 2;////这是重点
     }//牛顿迭代法
     return t;
}//这是重点

int main(){
  int x;
  while(cin >> x){
    cout << sqrt_n(x) << endl;
  }
}
