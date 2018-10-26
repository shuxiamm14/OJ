#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
	int num;
	int d;
	int c;
	bool operator <(const student &A) const{
		if(d+c != A.d+A.c)
			return d+c>A.d+A.c;
		else if(d != A.d)
			return d>A.d;
		else return num<A.num;
	}
};

int main()
{
	int n,l,h,i,count=0;
	vector<student> v1,v2,v3,v4;
	student temp;
	scanf("%d %d %d",&n,&l,&h);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&temp.num,&temp.d,&temp.c);
		if((temp.d>=l)&&(temp.c>=l))
		{
			count++;
			if((temp.d>=h)&&(temp.c>=h))
				v1.push_back(temp);
			else if(temp.d>=h)
				v2.push_back(temp);
			else if(temp.d>=temp.c)
				v3.push_back(temp);
			else v4.push_back(temp);
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	sort(v3.begin(),v3.end());
	sort(v4.begin(),v4.end());
	vector<student>::iterator itr;
	printf("%d\n",count);
	for(itr=v1.begin();itr!=v1.end();++itr)
		printf("%d %d %d\n",itr->num,itr->d,itr->c);
	for(itr=v2.begin();itr!=v2.end();++itr)
		printf("%d %d %d\n",itr->num,itr->d,itr->c);
	for(itr=v3.begin();itr!=v3.end();++itr)
		printf("%d %d %d\n",itr->num,itr->d,itr->c);
	for(itr=v4.begin();itr!=v4.end();++itr)
		printf("%d %d %d\n",itr->num,itr->d,itr->c);
	system("pause");
	return 0;
}