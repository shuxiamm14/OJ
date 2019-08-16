/*
题目描述
给定两个-100到100的整数x和y,对x只能进行加1，减1，乘2操作，问最少对x进行几次操作能得到y？
例如：
a=3,b=11: 可以通过3*2*2-1，3次操作得到11；
a=5,b=8：可以通过(5-1)*2，2次操作得到8；

输入描述:
输入以英文逗号分隔的两个数字，数字均在32位整数范围内。
输出描述:
输出一个数字
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入

3,11
输出

1

*/


#include <iostream>

using namespace std;





int min(int a, int b, int c){
	
	if( a >= b && a >= c) return a;
	else if( b >= a && b >= c) return b;
	else if( c >= b && c >= a) return c;

	
}

int fun(int a, int b, int & dep){
	
	
	if(a == b) return 1;
	else{
		
		int add_1 = fun(a+1, b , dep);
		int reduce_1 = fun(a-1, b, dep);
		int mul_2 = fun(a*2, b, dep);
		
		return min(add_1, reduce_1, mul_2);	
	}
	//栈溢出，先放弃
	
}


int main(int argc, char *argv[]) {
	int a = 0;
	int b = 0;
	
	cin >> a;
	getchar();
	cin >> b;
	int depth = b-a;
	cout << fun(a, b, depth);
	
	return 0;
}