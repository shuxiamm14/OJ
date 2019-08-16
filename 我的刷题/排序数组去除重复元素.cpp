#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	/*
	*排序数组筛选重复元素
	*
	* In 1 2 2 2 3 4 4 5 6 7 
	* Out 1 2 3 4 5 6 7
	*/
	vector<int> vec = {1,2,2,2,3,4,4,5,6,7};
	if(vec.empty()) return 0;
	int index = 0;
	for(int i = 1; i < vec.size(); i++){
		if (vec[i] != vec[index]) {
			vec[++index] = vec[i];
		}
	}
	vec.erase(vec.begin()+index+1,vec.end());
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << ' ';
	}
	
	
	
}