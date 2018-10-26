#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char *argv[]) {
	long long a,b;
	int d;
	while(cin >> a >> b >> d){
		if(d<=1||d>10) break;
		if(a<0||b<0)
		long long sum = a + b;
		stack<long long> s;
		while(sum!=0){
			s.push(sum%d);
			sum=sum/d;
		}  	
		while(!s.empty()){
			cout << s.top();
			s.pop();
		}
		cout << endl;
		
	}
	return 0;
}