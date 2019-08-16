/*
题目描述
输入N，求N！末尾的第一个非零数字。如6 ! = 720，因此6的阶乘末尾的非零位是2。
输入描述:
仅一行，包含一个整数N（0<=N<=10,000,000）
输出描述:
仅一行，包含一个整数，表示最右边的非零的值
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入

6
输出

2
说明
6 ! = 720
*/
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	
	int N = 0;
	while(cin >> N){
		if(N==0) cout << 0 << endl;
		vector<int> res;
		res.push_back(1);
		for(int i = 2; i <= N; ++i){
			
			int temp = res.back();
			int mul = i * temp;
			
			while(mul % 10 == 0){
				mul /= 10;
			}
			res.push_back(mul % 10);
			
			
		}
		cout << res[N-1] << endl;
		
		
	}
	
}