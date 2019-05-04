#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char in[100];
	while(scanf("%s",in)!=EOF){
		if(strlen(in)==1&&in[0]=='0') {
			printf("Yes!\n");
			continue;
		}
		if(in[0]=='0'&&in[1]!='x'&&in[1]!='X'){
			int sum = 0;
			for(int i = 1; i < strlen(in); i ++){
				if(in[i]>='0'&&in[i]<='7'){
					sum++;
				}
			}
			if(sum == strlen(in)-1) printf("Yes!\n");
			else printf("No!\n");
		}
		if(in[0]=='0'&&(in[1]=='x'||in[1]=='X')){
			int sum = 0;
			for(int i = 2; i < strlen(in); i ++){
				if((in[i]>='0'&&in[i]<='9')||(in[i]>='a'&&in[i]<='f')||(in[i]>='A'&&in[i]<='F')){
					sum++;
				}
			}
			if(sum == strlen(in)-2) printf("Yes!\n");
			else printf("No!\n");
		}
		if(in[0]!='0'){
			int sum = 0;
			for(int i = 0; i < strlen(in); i ++){
				if(in[i]>='0'&&in[i]<='9'){
					sum++;
				}
			}
			if(sum == strlen(in)) printf("Yes!\n");
			else printf("No!\n");
		}
		
		
		
	}
	
}