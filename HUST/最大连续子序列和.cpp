#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int a[10] = {1,2,-1,3,5,-7,-8};
	int i = 0;
	int sum = 0;
	int max = 0;
	while(i<10){
		sum+=a[i];
		if(sum<0){
			sum=0;
			i++;
		}
		else{
			i++;
		}
		if(sum>max){
			max = sum;
		}
	}
	cout << max << endl; 
}