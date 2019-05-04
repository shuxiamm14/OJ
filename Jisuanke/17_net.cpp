#include<iostream>
#include<vector>
using namespace std;

bool tiao(vector<int> ivec,int n)
{
    if(n==1)//只有一个元素， 返回true
    {
      return true;
    }
    int i=0;
    while(i<n-1)
    {
        i += ivec[i];
        if(ivec[i]==0 && i!=n-1)//当某一元素为0，并且它不是最后一个元素时，一定跳不到最后一个下标
        {
            return false;
        }
        if(i==n-1)
        {
            return true;
        }
    }
    return true;
}

int main()
{
    vector<int> ivec;
    int num,m,n;
    cin >>num;
    n=num;
    while(num>0)
    {
        cin>>m;
        ivec.push_back(m);
        num--;
    }
    if(tiao(ivec,n))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;

}
