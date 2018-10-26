#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const string result[10] = {"S","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(int argc, char *argv[]) {
	string s;
	while(cin >> s){
		//start
		int sum = 0;
		int i = s.size()-1;
		while(i>=0){
			if(s[i]>'9'||s[i]<'0') break;
			sum += s[i]-'0';
			i--;
		}
		//cout << sum << endl;
		stack<string> ret;
		while(sum%10!=0){
			int cur = sum % 10;
			ret.push(result[cur]);
			sum/=10;
		}
		while(!ret.empty()){
			cout << ret.top();
			ret.pop();
			if(!ret.empty()){
				cout << ' ';
			}
		}
		cout << endl;
		
		//end
		
	}
		
}