#include<iostream>
#include <cstring>

using namespace std;
string result[100];

string change(string s) { //按照转换规则进行字符串的转换
	string tmp = "";
	int len = s.length(), i, j, m;
	for (i = 0; i < len; i = i + m) {
		m = 1;
		for (j = i + 1; j < len; j++) {
			if (s[i] == s[j])
				m++;
			else
				break;
		}
		char c = m + '0'; //整型数字转换为字符
		tmp.push_back(c);
		tmp.push_back(s[i]);
	}
	return tmp;
}
string dp(int n) {   //动态规划函数
	string result = "1";
	for (int i = 1; i < n; ++i) {
		result = change(result);
	}
	return result;
}

int main() {
	int n;
	while (cin >> n)
		cout << dp(n) << endl;
}
