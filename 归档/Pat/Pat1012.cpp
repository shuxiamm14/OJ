#include <iostream>
using namespace std;
typedef struct num{
	int a;
	char b;
} num;

int main(){
	num A[6];;
	int flag = 0;
	int count = 0;
	int n = 0;
	while(cin >> n){
		int in = 0;
		for(int i = 1; i <= 5; i ++){
			A[i].a = 0;
			A[i].b = 'N';
 		}
		for(int i = 0; i < n; i ++){
			cin >> in;
			if(in%5==0&&in%2==0){
				A[1].a+=in;
				A[1].b = 'Y';
			}	
			if(in%5==1){
				A[2].b = 'Y';
				if(flag == 0){
					A[2].a+=in;
					flag = 1;
				}
				else if(flag == 1){
					A[2].a-=in;
					flag = 0;
				}
			}
			if(in%5==2){
				A[3].b = 'Y';
				A[3].a++;
			}		
			if(in%5==3){
				A[4].b = 'Y';
				count ++;
				A[4].a+=in;
				
			}	
			if(in%5==4){
				A[5].b = 'Y';
				A[5].a = A[5].a < in ? in : A[5].a;
			}				
		}
		for(int i = 1; i <=5; i ++){
			
			if(A[i].b == 'Y'){
				if(i==4) {
					printf("%.1f ",(float)A[4].a/count);
					continue;
				}
				cout << A[i].a;
				
			}	
			else{
				cout << A[i].b;
			}
			if(i!=5)cout <<' '; 
		}
		cout << endl;
		count = 0;
		for(int i = 1; i <= 5; i ++){
			A[i].a = 0;
			A[i].b = 'N';
 		}
		
		
		
	}
	return 0;
} 