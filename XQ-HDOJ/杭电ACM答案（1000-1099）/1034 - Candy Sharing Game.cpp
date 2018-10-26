#include <cstdio> 
using namespace std; 
int num[1000],tmp[1000],t,n,r; 

inline bool isequal() 
{ 
    int i,t=num[0]; 
    for(i=1;i<n;i++) 
        if(num[i]!=t) 
            break; 
    if(i==n) 
        return false; 
    else 
        return true; 
} 
int main() 
{ 
    int i; 
    bool flag; 
     
    while(scanf("%d",&n)==1 && n) 
    { 
        for(i=0;i<n;i++) 
            scanf("%d",&num[i]); 
        i=0;r=0; 
        while( isequal() ) 
        { 
            r++; 
            tmp[0] = num[n - 1]/2 + num[0]/2; 
            for(i = 1; i < n; i++) 
                tmp[i] = num[i - 1]/2 + num[i]/2; 
            for(i = 0; i < n; i++) 
                if(tmp[i]%2 == 1) 
                    num[i]=tmp[i]+1; 
                else 
                    num[i]=tmp[i]; 
        } 
        printf("%d %d\n",r,num[0]); 
    } 
    return 0; 
} 

