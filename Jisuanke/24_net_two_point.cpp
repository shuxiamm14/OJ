#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &number, int target)
{
	int index1, index2;
	vector<int> v = number;
	for (int i = 0; i < v.size(); i++) 
    {
		for (int j = i + 1; j < v.size(); j++)
        {
			if (v[i] + v[j] == target)
            {
				index1 = i;
				index2 = j;
			}
		}
	}
	vector<int> re;
	re.push_back(index1+1);
	re.push_back(index2+1);
	return re;
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
