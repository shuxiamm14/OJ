#include <iostream>
using namespace std ;
const int maxn = 100000;
int main()
{
    int A[maxn];
    int n ;
    cin >> n ;
    for ( int i = 0 ; i < n ; ++i)
    {
        cin >> A[i];
    }//输入

    int thissum = 0 , maxsum = 0 , ele = A[0];
    for ( int i = 0 ; i < n ; ++i)
    {
          thissum += A[i];
          if( thissum > maxsum)
              maxsum = thissum ;
          if(thissum < 0)
              thissum = 0 ;
          if( A[i] > ele)
              ele = A[i];
    }


    if(maxsum==0)
    {
        cout<<ele;
    }else
    {
        maxsum=maxsum > ele ? maxsum:ele;
        cout<<maxsum;
    }
}
