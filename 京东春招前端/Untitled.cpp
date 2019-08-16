#include <iostream>
/*
最长区间
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
拉齐有一个01序列，他可以对这个序列进行任意多次变换，每次变换都是把序列的最后若干个元素放到最前面，例如：010011，将最后3个元素011放到最前面，序列变为011010。所有变换结束后，拉齐需要挑出一个全为1的连续区间，要求最大化区间长度。

输入
共一行，一个01串，仅包含0或1。序列长度不超过50000。

输出
一个整数，表示最长区间的长度。


样例输入
11011
样例输出
4

提示
首先做一次变换，将末尾两个1提到开头变成11110，显然最长区间是1111，长度为4。
规则
请尽量在全场考试结束10分钟前调试程序，否则由于密集排队提交，可能查询不到编译结果 
点击“调试”亦可保存代码
编程题可以使用本地编译器，此页面不记录跳出次数

*/
using namespace std;
int main(int argc, char *argv[]) {
	string s;
	
	while(cin >> s){
		
		//s += s;
		
		int max = 0;
		
		for(int i = 0; i < s.size(); ++i){
			
			int count = 0;
			if(s[i] == '1'){
				++count;
			}
			else{
				continue;
			}
			for(int j = i + 1; ; ++j){
				if(j == s.size()) j = 0;
				if(j == i){
					break;
				}
				if(s[j] == s[i]){
					++count;
				}
				else{
					count = 0;
					break;
				} 
				
				if(count > max) max = count;
				
			}
		}
		cout << max << endl;
		
	}
}