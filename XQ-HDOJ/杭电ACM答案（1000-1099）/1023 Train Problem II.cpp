//和Problem: 1130 ( How Many Trees? ) 相同, 1134 Game of Connections , 1023 Train Problem II
//求二叉树计数
//C(2n,n)-C(2n,n-1)=C(2n,n) / (n+1) 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include <algorithm> 
using namespace std; 

#define MAXN 9999 
#define DLEN 4 

class BigNum{ 
private: 
   int a[300];//DLEN digs for a position 
   int len; 
public: 
   BigNum(){len = 1;memset(a,0,sizeof(a));} 
   BigNum(const int b); 
   BigNum(const BigNum & T); 

   bool     Bigger(const BigNum &) const; 
   BigNum & operator=(const BigNum &); 
   BigNum & Add(const BigNum &); 
   BigNum & Sub(const BigNum &); 
   BigNum operator+(const BigNum &) const; 
   BigNum operator-(const BigNum &) const; 
   BigNum operator*(const BigNum &) const; 
   BigNum operator/(const int   &) const; 
   void Print(); 

   BigNum operator+=(const BigNum &) ; 
   BigNum operator-=(const BigNum &) ; 
   BigNum operator*=(const BigNum &) ; 
   BigNum operator/=(const int   &) ; 
}; 
BigNum::BigNum(const int b) 
{ 
   int c,d = b; 

   len = 0; 
   memset(a,0,sizeof(a)); 
   while(d > MAXN){ 
      c = d - d / (MAXN + 1) * (MAXN + 1); 
      d = d / (MAXN + 1); 
      a[len++] = c; 
   } 
   a[len++] = d; 
} 
BigNum::BigNum(const BigNum & T) : len(T.len) 
{ 
   int i; 
   memset(a,0,sizeof(a)); 
   for(i = 0 ; i < len ; i++) 
      a[i] = T.a[i]; 
} 
bool  BigNum::Bigger(const BigNum & T) const 
{ 
   int ln; 
   if(len > T.len) return true; 
   else if(len == T.len){ 
      ln = len - 1; 
      while(a[ln] == T.a[ln] && ln >= 0) ln--; 
      if(ln >= 0 && a[ln] > T.a[ln]) return true; 
      else return false; 
   } 
   else return false; 
} 
BigNum & BigNum::operator=(const BigNum & n) 
{ 
   len = n.len; 
   memset(a,0,sizeof(a)); 
   for(int i = 0 ; i < len ; i++) 
      a[i] = n.a[i]; 
   return *this; 
} 
BigNum & BigNum::Add(const BigNum & T) 
{ 
   int i,big; 

   big = T.len > len ? T.len : len; 
   for(i = 0 ; i < big ; i++) 
   { 
      a[i] = a[i] + T.a[i]; 
      if(a[i] > MAXN) 
      { 
         a[i + 1]++; 
         a[i] = a[i] - MAXN - 1; 
      } 
   } 
   if(a[big] != 0) len = big + 1; 
   else len = big; 

   return *this; 
} 
BigNum & BigNum::Sub(const BigNum & T) 
{ 
   int i,j,big; 

   big = T.len > len ? T.len : len; 
   for(i = 0 ; i < big ; i++){ 
      if(a[i] < T.a[i]){ 
         j = i + 1; 
         while(a[j] == 0) j++; 
         a[j--]--; 
         while(j > i) a[j--] += MAXN; 
         a[i] = a[i] + MAXN + 1 - T.a[i]; 
      } 
      else a[i] -= T.a[i]; 
   } 
   len = big; 
   while(a[len - 1] == 0 && len > 1) len--; 
   return *this; 
} 
BigNum BigNum::operator+(const BigNum & n) const 
{ 
   BigNum a = *this; 

   a.Add(n); 
   return a; 
} 
BigNum BigNum::operator-(const BigNum & T) const 
{ 
   BigNum b = *this; 

   b.Sub(T); 
   return b; 
} 
BigNum BigNum::operator*(const BigNum & T) const 
{ 
   BigNum ret; 
   int i,j,up; 
   int temp,temp1; 

   for(i = 0 ; i < len ; i++){ 
      up = 0; 
      for(j = 0 ; j < T.len ; j++){ 
         temp = a[i] * T.a[j] + ret.a[i + j] + up; 
         if(temp > MAXN){ 
            temp1 = temp - temp / (MAXN + 1) * (MAXN + 1); 
            up = temp / (MAXN + 1); 
            ret.a[i + j] = temp1; 
         } 
         else { 
            up = 0; 
            ret.a[i + j] = temp; 
         } 
      } 
      if(up != 0) 
         ret.a[i + j] = up; 
   } 
   ret.len = i + j; 
   while(ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--; 
   return ret; 
} 
BigNum BigNum::operator/(const int & b) const 
{ 
   BigNum ret; 
   int i,down = 0; 

   for(i = len - 1 ; i >= 0 ; i--){ 
      ret.a[i] = (a[i] + down * (MAXN + 1)) / b; 
      down = a[i] + down * (MAXN + 1) - ret.a[i] * b; 
   } 
   ret.len = len; 
   while(ret.a[ret.len - 1] == 0) ret.len--; 
   return ret; 
} 
void BigNum::Print() 
{ 
   int i; 

   cout << a[len - 1]; 
   for(i = len - 2 ; i >= 0 ; i--){ 
      cout.width(DLEN); 
      cout.fill('0'); 
      cout << a[i]; 
   } 
   cout << endl; 
} 

BigNum BigNum::operator*=(const BigNum & T) 
{ 
   BigNum ret; 
   int i,j,up; 
   int temp,temp1; 

   for(i = 0 ; i < len ; i++){ 
      up = 0; 
      for(j = 0 ; j < T.len ; j++){ 
         temp = a[i] * T.a[j] + ret.a[i + j] + up; 
         if(temp > MAXN){ 
            temp1 = temp - temp / (MAXN + 1) * (MAXN + 1); 
            up = temp / (MAXN + 1); 
            ret.a[i + j] = temp1; 
         } 
         else { 
            up = 0; 
            ret.a[i + j] = temp; 
         } 
      } 
      if(up != 0) 
         ret.a[i + j] = up; 
   } 
   ret.len = i + j; 
   while(ret.a[ret.len - 1] == 0 && ret.len > 1) ret.len--; 
   *this=ret; 
   return ret; 
} 
BigNum BigNum::operator/=(const int & b) 
{ 
   BigNum ret; 
   int i,down = 0; 

   for(i = len - 1 ; i >= 0 ; i--){ 
      ret.a[i] = (a[i] + down * (MAXN + 1)) / b; 
      down = a[i] + down * (MAXN + 1) - ret.a[i] * b; 
   } 
   ret.len = len; 
   while(ret.a[ret.len - 1] == 0) ret.len--; 
   *this=ret; 
   return ret; 
} 


const int Max=100; 

int main() 
{ 
    int t,n,ca; 
    BigNum ans; 

    while(cin>>n) 
    { 
    	if(n==-1)
    		break;
        for(ca=2*n,ans=1;ca>=n+2;ca--) 
        { 
            ans*=ca; 
        } 
        for(ca=2;ca<=n;ca++) 
        { 
            ans/=ca; 
        } 
         
        ans.Print(); 
    } 
    return 0; 
} 
