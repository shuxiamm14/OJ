class Solution {
public:
	
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> temp;
		subSetsCell(nums, 0, res, temp);
		
		return res;
		
		
	}
	void subSetsCell(vector<int>& nums, int index, vector<vector<int>>& res,vector<int>& temp) {
		res.push_back(temp);
		for (int j = index; j < nums.size(); ++j) {
			temp.push_back(nums[j]);
			subSetsCell(nums, j+1, res, temp);
			temp.erase(temp.end()-1);
		}
	}
};

//https://leetcode-cn.com/problems/subsets/solution/hui-su-suan-fa-by-powcai-5/
//https://leetcode-cn.com/problems/subsets/solution/er-jin-zhi-wei-zhu-ge-mei-ju-dfssan-chong-si-lu-9c/