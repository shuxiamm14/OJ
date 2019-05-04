//奇怪的国家
#include<stdio.h>
#include<string.h>

int main() {

	char a[50], b[50];

	int x;

	scanf("%s", &a);

	scanf("%s", &b);

	x = strlen(a);

	for (int i = 0; i<x; i++)

	{
		if (a[i] == b[i])

			printf("1");

		else

			printf("0");

	}
  return 0;
}
