//���������� �� Ҫ��ص�ԭ�����С����
//�Գ˻�����ż���� 
#include <cstdio>
using namespace std;
int main()
{
	int i,t,n,x,y;
	
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Scenario #%d:\n",i);
		scanf("%d %d",&x,&y);
		n=x*y;
		if(n%2==0)
			printf("%d.00\n",n);
		else
			printf("%d.41\n",n);
		printf("\n");
	}
	return 0;
}
