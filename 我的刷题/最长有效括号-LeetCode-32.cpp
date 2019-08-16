#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int longestValidParentheses(const string& s) {
		
		vector<int> dp(s.size(),0);
		int resMax = 0;
		
		for (int i = 1; i < dp.size(); i++) {
			if (s[i] == ')') {
				
				if (s[i-1] == '(') {
					
					dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
					
				} else if (i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '(') {
					
					dp[i] = dp[i-1] + ( (i-dp[i-1]) >= 2 ? dp[i-dp[i-1] - 2] : 0 )  + 2;
					
				}
				resMax = max(resMax, dp[i]);
				
			}
		}
		return resMax;
		
	}
};


int main(int argc, char *argv[]) {
	
	string s;
	while(cin >> s) {
		
		Solution* solution= new Solution;
		
		cout << solution->longestValidParentheses(s) << endl;
		
	}
	
}