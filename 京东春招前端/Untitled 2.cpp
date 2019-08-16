#include <iostream>
#include <vector>
/*

队列最小修改
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
已知一个奇怪的队列，这个队列中有n个数，初始状态时，顺序是1,2,3,4,…n，是1-n按顺序排列。这个队列只支持一种操作，就是把队列中的第i号元素提前到队首(1<i<=n)，如有4个元素，初始为1，2，3，4,可以将3提前到队首，得到3，1，2，4 。

现在给出一个经过若干次操作之后的序列，请你找出这个序列至少是由原序列操作了多少次得到的。

输入
第一行是一个整数n(1<=n<=10^5)，表示序列中数字的数量。

接下来一行有n个数，是1-n的一个全排列。数字之间用空格隔开。

输出
输出仅包含一个数字，表示至少操作了几次


样例输入
5
5 2 1 3 4
样例输出
2

规则
请尽量在全场考试结束10分钟前调试程序，否则由于密集排队提交，可能查询不到编译结果 
点击“调试”亦可保存代码
编程题可以使用本地编译器，此页面不记录跳出次数

*/
using namespace std;
int main(int argc, char *argv[]) {
	int n = 0;
	while(cin >> n){
		
		vector<int> res;
		
		for(int i = 0; i < n; ++i){
			int temp = 0;
			cin >> temp;
			res.push_back(temp);
		}
		int count = n;
		for(int i = n-1; i >= 1; --i){
			
			if(res[i]>res[i-1]) count--;
			else {
				count --;
				break;
			}
			
		}
		cout << count << endl;
		
	}
}