#include <iostream>

int floor(int n){
	if(n==1) return 1;
	if(n==2) return 1;
	else 
	return floor(n-1) + floor(n-2);
}
using namespace std;
int main(int argc, char *argv[]) {
	int n = 0;
	while(cin >> n){
		cout << floor(n) << endl;
	}
}