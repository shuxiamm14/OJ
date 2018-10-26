#include<iostream>
#include<string>
int main()

{
	char lm[10000];
	int i,count = 0;
	gets(lm);
	for(i = 0;i < strlen(lm);i++)
	{
		switch(lm[i])
		{
			case 'M': count += 1000; break;
			case 'D': count += 500; break;
			case 'C':
				if(lm[i+1] == 'D' || lm[i+1] == 'M')
					count -= 100;
				else
					count += 100;
				break;
			case 'L': count += 50; break;
			case 'X':
				if(lm[i+1] == 'L' || lm[i+1] == 'C')
					count -= 10;
				else
					count += 10;
				break;
			case 'V': count += 5; break;
			case 'I':
				if(lm[i+1] == 'V')
					count--;
				else
					count++;
				break;
		}
	}
	printf("%d\n",count);
	return 0;
}
