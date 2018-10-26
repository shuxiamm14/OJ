#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char in[100];
	char res[100];
	while(scanf("%s",in)!=EOF){
		if(strlen(in)%2 == 1){
			in[strlen(in)] = '0';
		}
		int i = 0;
		int j = 1;
		int k = 0;
		while(j<strlen(in)){
			char sum = (in[i] - '0')*10 + in[j] - '0' + 32;
			i+=2;
			j+=2;
			res[k++] = sum;
		}
		printf("%s\n",res);
	}
}