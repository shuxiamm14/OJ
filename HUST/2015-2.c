#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char a[100];
	char b[100];
	char c[200];
	scanf("%s %s",a,b);
	int i;
	for(i = 0; i < strlen(a); i++){
		c[i]=a[i];
	}
	for(i = strlen(a); i < strlen(a)+strlen(b); i++){

		c[i]=b[i-strlen(a)];
	}
	for(i = 0; i < strlen(a)+strlen(b); i++){

		printf("%c",c[i]);
	}
	printf("\n");
	int c_len = strlen(a)+strlen(b);
	for(i = 0; i < c_len; i += 2){
		printf("%c",c[i]);
	}
	printf(" ");
	for(i = 1; i < c_len; i += 2){
			printf("%c",c[i]);
		}
	printf("\n");
	for(i = 0; i < c_len; i++){
		int min = i;
		int j;
		for(j = i+2; j < c_len; j += 2){
			if(c[j]<c[min]){
				min = j;
			}
		}
		if(min != i){
			char temp = c[i];
			c[i] = c[min];
			c[min] = temp;
		}
	}
	for(i = 1; i < c_len; i++){
			int min = i;
			int j;
			for(j = i+2; j < c_len; j += 2){
				if(c[j]<c[min]){
					min = j;
				}
			}
			if(min != i){
				char temp = c[i];
				c[i] = c[min];
				c[min] = temp;
			}
		}
	for(i = 0; i < c_len; i += 2){
			printf("%c",c[i]);
	}
	printf(" ");
	for(i = 1; i < c_len; i += 2){
			printf("%c",c[i]);
	}
}
