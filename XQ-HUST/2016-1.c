#include <stdio.h>

int main(int argc, char *argv[]) {
	float score[7];
	for(int i = 0; i < 7;i ++){
		scanf("%f",&score[i]);
	}
	for(int i = 0; i < 7; i++){
			int min = i;
			for(int j = i+1; j < 7; j ++){
				if(score[j]<score[min]){
					min = j;
				}	
			}
			if(min != i){
				float temp = score[i];
				score[i] = score[min];
				score[min] = temp;
			}
		}
	printf("\n");
	float ret = 0;
	for(int i = 1; i < 6 ;i ++){
		ret += score[i];
	}
	printf("%.1f\n",ret/5);
	
	
	
}