/*
1013 Digital Roots
Time Limit : 1000 ms  Memory Limit : 32768 K  Output Limit : 5120 K 

GUN C++
*/

#include <iostream.h>
#include <string.h>

using namespace std;

#define MAX 10000
int main()
{
	int len,ca,num2,root;
	char num[MAX];
	while(cin>>num && num[0]!='0')
	{
		len=strlen(num);
		root=0;
		num2=0;
			for(ca=0;ca<len;ca++)
				switch(num[ca])
				{
				case '0':
					break;
				case '1':
					num2+=1;
					break;
				case '2':
					num2+=2;
					break;
				case '3':
					num2+=3;
					break;
				case '4':
					num2+=4;
					break;
				case '5':
					num2+=5;
					break;
				case '6':
					num2+=6;
					break;
				case '7':
					num2+=7;
					break;
				case '8':
					num2+=8;
					break;
				case '9':
					num2+=9;
					break;
				}
		root=num2;
		while(root>=10)
		{
            root=0;
			while(num2>0)
			{	root+=num2%10;num2/=10;}
			num2=root;	
		}
		cout<<root<<endl;
	}
	return 0;	
}
