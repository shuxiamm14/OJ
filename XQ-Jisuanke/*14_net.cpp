#include<iostream>
using namespace std;

int getOnceNumber(int A[],int n){
    const int N=32;
    int cnt[N]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<N;j++){
            cnt[j]=(cnt[j]+(A[i]>>j&1))%3;
        }
    }
    int res=0;
    for(int i=0;i<N;i++){
        res+=(cnt[i]<<i);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int A[n];//after cin n
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<getOnceNumber(A,n)<<endl;
    return 0;
}
