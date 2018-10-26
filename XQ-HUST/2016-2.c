#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char in[100];
	gets(in);
	//printf("%s\n",in);
	int i = 0;
	//1.
	while(in[i]==' '){
		i++;
	}                                                                                         
	for(;i<strlen(in);i++){
		printf("%c",in[i]);
	}
	//2.
	printf("\n");
	int j = 0;
	while(j<strlen(in)){
		if(in[j]!=' ') {
			printf("%c",in[j]);
			j++;
		}
		else if(in[j+1]!=' ') {
			printf("%c",in[j]);
			j++;
		}
		else {
			j++;
			continue;
		}
		
	}
	//3.
	printf("\n");
	int k = 0;
	while(k < strlen(in)-1){
		printf("%c",in[k]);
		if(((in[k]>='0'&&in[k]<='9') && ((in[k+1]>='a'&&in[k+1]<='z')||(in[k+1]>='A'&&in[k+1]<='Z')))
		||((in[k+1]>='0'&&in[k+1]<='9') && ((in[k]>='a'&&in[k]<='z')||(in[k]>='A'&&in[k]<='Z')))){
			printf("_");
		}
		k++;
	}
	printf("%c",in[k]);
	
}