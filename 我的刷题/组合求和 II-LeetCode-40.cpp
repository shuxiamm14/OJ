class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> ans;
		recurs(candidates, ans, 0, target);
		return res;
	}
	void recurs(vector<int>& candidates, vector<int>& ans, int pos, int target) {
		if (target==0) {
			res.push_back(ans);
			return;
		}
		for (int i = pos; i < candidates.size(); ++i) {
			if (target - candidates[i] >= 0) {
				if (i!=pos && candidates[i]==candidates[i-1]) // 去掉重复
					continue;
				ans.push_back(candidates[i]);
				recurs(candidates, ans, i+1, target-candidates[i]);
				ans.pop_back();
			}
			else { // 剪枝
				break;
			}
		}
	}
};



/*递归回溯，同时要去重。
为啥能通过比较相同然后移动扫描下标就能去重？
假设[l, r]区间中要找一个和为target。通过函数backTracking(v, l, r， target)就能求出来解。
而如果[l+1, r]区间有好几个值跟v[l]相等，但是此区间==v[l]元素的个数一定比v[l, r]区间==v[l]元素的个数少；
所以对于"含有v[l]的解"中，前者的答案一定包含后者，所以我们只需要求一次就行；
后面相同的元素直接跳过去。

图示：假设这个相同的数为3

3 [3......3333.....3(第k个3)]4677899....p
l l+1                                   r

既然区间[l+1, r]能够求出和为target的组合，其中包含了[l+1, r]区间所有含3的解的情况。
而区间[l, r]3的个数比[l+1, r]3的个数更多，那么毫无疑问，[l, r]的解将覆盖[l+1, r]解中含有3的情况。*/ 
class Solution {
private:
	vector<vector<int>> ans;
	vector<int> curComb;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> c = candidates;//拷贝vector，保证算法对输入数据不产生修改。
		sort(c.begin(), c.end());//排序，方便后续操作
		int start = 0, end = 0;//排序后，排除尾部所有>target的数
		for (; end < c.size(); end++) { if (c[end] > target) break; }
		backTracking(c, start, end == c.size() ? end - 1 : end, target);
		return ans;
	}
private:
	void backTracking(vector<int>& c, int l, int r, int target) {

		if (target < 0) return;//target<0
		if (!target) {//target==0
			ans.push_back(curComb);
			return;
		}
		//target > 0
		for (int i = l; i <= r && c[i] <= target; i++) {
			if (i != l && c[i] == c[i-1]) continue;//remove duplicate solution.
			curComb.push_back(c[i]);
			backTracking(c, i + 1, r, target - c[i]);
			curComb.pop_back();
		}
	}
};