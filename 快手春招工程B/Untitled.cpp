/*
题目描述
给定两个字符串，已知可以使用三种方式进行变换
1. 插入一个字符
2. 删除一个字符
3. 更改一个字符
请设计一个算法，找到两个字符串之间的经历几次最小变换，可以字符串1转换成字符串2
输入描述:
输入两个字符串，字符串的长度<=1000
输出描述:
最小变换次数
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入

hello
helle
输出

1
*/
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	
	string str1;
	string str2;
	
	while(cin >> str1 >> str2){
		int count = 0;
		
		//更改
		if(str1.size() == str2.size()){
			int i = 0;
			int j = 0;
			
			while(i < str1.size() && j < str2.size()){
				if(str1[i] != str2[j]){
					count ++;
				}
				++i;
				++j;
				
			}
			cout << count << endl;
			return 0;
		}
		
		
		//插入或删除
		if(str1.size() != str2.size()){
			
			if(str1.size() > str2.size()){
				count += str1.size() - str2.size();
				for(int i = 0; i < str2.size(); ++i){
					bool flag = false;
					for(int j = 0; j < str1.size(); ++j){
						if(str1[j] == str2[i]){
							flag = true;
							break;
						}
					}
					if(flag == false){
						count ++;
					}
				}

			}
			
			else{
				count += str2.size() - str1.size();
				for(int i = 0; i < str1.size(); ++i){
					bool flag = false;
					for(int j = 0; j < str2.size(); ++j){
						if(str2[j] == str1[i]){
							flag = true;
							break;
						}
					}
					if(flag == false){
						count ++;
					}
				}

			}
			cout << count << endl;
			return 0;
			
		}
	}
}