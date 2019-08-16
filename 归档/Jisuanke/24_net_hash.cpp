#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> result;
	map<int, int> hashMap;
	for (int i = 0; i < numbers.size(); i++) {
		if (!hashMap.count(numbers[i]))
			hashMap.insert(pair<int, int>(numbers[i], i));
		if (hashMap.count(target - numbers[i])) {
			int n = hashMap[target - numbers[i]];
			if (n < i) {
				result.push_back(n + 1);
				result.push_back(i + 1);
				return result;
			}
		}
	}
}

int main(int argc, char **argv) {
	int n,target;
	cin>>n;
	vector<int> nums;
	int temp;
	for(int i =0;i<n;i++)
	{
		cin>>temp;
		nums.push_back(temp);
	}
	cin>>target;
	vector<int> res;
	res = twoSum(nums,target);
	for(int j = 0;j < res.size();j++)
	{
		cout<<res[j]<<" ";
	}
	cout<<endl;
	return 0 ;
}
