#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	long long c1,c2;
	while(cin >> c1 >> c2){
		if(c1>c2) break;
		long long res = (c2 - c1)/100;
		if((c2-c1)%100>=50)res++;
		int h = 0;
		int m = 0;
		int s = 0;
		h = res/3600;
		m = res%3600/60;
		s = res%3600%60;
		if(h>10)
			cout << h;
		else if(h<=10)
			cout << 0 << h;
		cout <<':';
		if(m>10)
			cout << m;
		else if(m<=10) 
			cout << 0 << m; 
		cout << ':';
		if(s>10)
			cout << s << endl;
		else if(s<=10)
			cout << 0 << s << endl;
		
	}
}