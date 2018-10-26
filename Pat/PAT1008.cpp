#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	int n = 0;
	int t = 0;
	while(cin >> n >> t){
		t = t%n;
		if(n<0||n>100) return 0;
		if(t<0) return 0;
		//start
		int *p = new int[n];
		for(int i = 0; i < n; i++){
			cin >> p[i];
		}
		for(int i = n-t; i < n;i++){
			cout << p[i] << ' ';
		}
		for(int i = 0;i < n-t-1; i ++){
			cout << p[i] << ' ';
		}
		cout << p[n-t-1]<< endl;

		//end;
	}
	
}