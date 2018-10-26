#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
	int in[1001][2];
	int len = 0;
	for(int i = 0; ;i++){
		cin >> in[i][0] >> in[i][1];
		len++;
		if(in[i][1]==0) break;
		
	}
	if(len == 1 && in[0][1]==0){
		cout << 0 << ' ' << 0 << endl;
		return 0;
	}
	for(int i = 0; i < len; i ++){
		if(in[i][1]!=0){
			cout << in[i][0]*in[i][1] << ' ' << in[i][1]-1;
			if(in[i+1][1]!=0) cout << ' ';
		}
		
	}
	cout << endl;
	return 0;
}