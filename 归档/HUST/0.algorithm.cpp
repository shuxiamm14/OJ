#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    int a[13]={-1,2,5,3,5,32,-4,35,-1,5,23,325,0};
    for(int i=0;i<13;i++){
        cout<<a[i];
        if(i<12){
            cout << ",";
        }
    }
    cout<<endl;
    sort(a,a+13);
    for (int i = 0; i<13;i++)
    {
        cout << a[i];
        if (i < 12)
        {
            cout << ",";
        }
    }
    cout<<endl;
    return 0;
}
