#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	string s1;
	string s2;
	int n;
	int m;
	while(cin >> s1 >> n >> s2 >> m){
		int len_1 = s1.size();
		int len_2 = s2.size();
		int a = 0;
		int b = 0;
		int k = 0;
		for(int i = len_1; i>=0; i--){
			if(s1[i]-'0'==n)
			a+=n*pow(10,k++);
		
		}
		k=0;
		for(int i = len_1; i>=0; i--){
			if(s2[i]-'0'==m)
			b+=m*pow(10,k++);
		
		}
		cout << a + b << endl;

	}
}
