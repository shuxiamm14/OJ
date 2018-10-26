#include <stdio.h>
#include <string.h>
void print_char(char in){
	char res[100] = {'0'};
	if(in>='a'&&in<='z'){
		int len = in - 'a';
		for(int i = in - 'a' ; i >= 0; i --){
			res[i] = in;
			in--;
			
		}
		in++;
		for(int i = 2*len; i >= len ; i --){
			res[i] = in;
			in ++;
		}
		
	}
	if(in>='A'&&in<='Z'){
			int len = in - 'A';
			for(int i = in - 'A' ; i >= 0; i --){
				res[i] = in;
				in--;
				
			}
			in++;
			for(int i = 2*len; i >= len ; i --){
				res[i] = in;
				in ++;
			}
			
	}
	printf("%s\n",res);	
}
int main(int argc, char *argv[]) {
	char in = '0';
	while(scanf("%c",&in)!=EOF){
		int sum = 0;
		if(in>='a'&&in<='z'){
			sum = in - 'a';
		}
		else {
			sum = in - 'A';
		}
		while(in>='a'&&in<='z'){
			for(int i = sum - (in - 'a') - 1; i >= 0; ){
				printf(" ");
				i--;
			}
			print_char(in--);
		}
		while(in>='A'&&in<='Z'){
			for(int i = sum - (in - 'A') - 1; i >= 0; ){
				printf(" ");
				i--;
			}
			print_char(in--);
		}
		
		
		
		
	}
}