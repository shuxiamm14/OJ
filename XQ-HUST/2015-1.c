#include <stdio.h>
#include <string.h>

char tel[100] = {'.'};

int main(int argc, char *argv[]) {
	
	while(scanf("%s",tel)!=EOF){
		int length = strlen(tel);
		//printf("%d\n",length);
		if(length!=11) printf("No!\n");
		else if(tel[0]!='1')printf("No!\n");
		else if(tel[1]!='3'&&tel[1]!='5'&&tel[1]!='6'&&tel[1]!='8')printf("No!\n");
		else {
			int i = 2;
			while(tel[i]<='9'&&tel[i]>='0'){
				i++;
			}
			if(i==11) printf("Yes!\n");
			else printf("No!\n");
		}
	}
	return 0;
}