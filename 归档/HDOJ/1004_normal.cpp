#include <iostream>
using namespace std;
#define NMAX 1000

int main()
{
    int n,ca,cb,kinds,max,times[NMAX]={0};
    char list[NMAX][16],strnow[16];
    while(cin>>n && n!=0)
    {
        kinds=0;
        for(ca=0;ca<n;ca++)
        {
            cin>>strnow;//输入
            if(kinds==0)
            {
              strcpy(list[0],strnow);//存入数组
              times[0]++;//此颜色次数增加
              kinds++;//类型数目增加
              continue;
            }
            for(cb=0;cb<kinds;cb++)//此次颜色类型是否已经存在，有则增加无则break
            {
                if(strcmp(strnow,list[cb])==0)
                {
                  times[cb]++;//次数增加
                  break;
                }
            }
            if(cb==kinds)//？发现可以去掉
            {
              strcpy(list[kinds],strnow);
              times[kinds]++;
              kinds++;
            }
        }
        max=0;
        for(ca=0;ca<kinds;ca++)//取出次数最多的类型，建立索引
            if(times[ca]>times[max])//类似于选择排序
                max=ca;
        cout<<list[max]<<endl;//依据索引输出颜色类型
        for(ca=0;ca<kinds;ca++)//清零
            times[ca]=0;
    }
    return 0;
}
