#include <stdio.h>
#include <string.h>
#include <math.h>
char change(char in){
	int temp[4];
	for(int i = 0; i < 4; i ++){
		temp[i] = in % 2;
		in = in >> 1;
	}
	char ret = in;
	for(int i = 0; i < 4; i ++){
		ret = ret << 1;
		ret += temp[i];
	}
	return ret;
}


int main(int argc, char *argv[]) {
	char input[100];
	while(scanf("%s",input)!=EOF){
		printf("%s\n",input);
		char temp[100];
		int k = 0;
		for(int i = 0;i < strlen(input);i++){
			int sum = 0;
			for(int j = 0; j < strlen(temp); j ++){
				if(temp[j]!=input[i])sum++;
					
			}
			if(sum == strlen(temp))
			temp[k++] = input[i];
		}
		printf("%s\n",temp);
		
		char ret[100];
		for(int i = 0; i < strlen(temp); i++){
			ret[i] = change(temp[i]);
			if(ret[i]>='a'&&ret[i]<='z'){
				ret[i] -= 32;
			}	
		}
		printf("%s\n",ret);	
	}
}