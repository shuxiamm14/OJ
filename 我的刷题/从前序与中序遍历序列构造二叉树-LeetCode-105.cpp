#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/*
	// start from first preorder element 前序遍历的迭代器
	int pre_idx = 0;
	vector<int> pre;
	map<int,int> idx_map;
	TreeNode* helper(int in_left,int in_right)
	{
		// if there is no elements to construct subtrees 如果没有元素来构造树
		if(in_left == in_right)
			return NULL;        
		
		// pick up pre_idx element as a root 选取前序遍历中的值来构造树        
		TreeNode* root = new TreeNode(pre[pre_idx]);        
		
		// root splits inorder list 根将中序遍历分成左右两部分
		// into left and right subtrees        
		auto iter = idx_map.find(pre[pre_idx]);
		int index = iter->second;        
		// recursion 递归
		
		pre_idx++;
		// build left subtree 生成左树
		root->left = helper(in_left,index);
		// build right subtree 生成右树
		root->right = helper(++index,in_right);
		
		return root;        
	}
	
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		pre = preorder;        
		
		// build a hashmap value -> its index 构造map，储存中序遍历的值和位置
		int idx = 0;        
		for(auto i = inorder.begin(); i!=inorder.end(); i++){
			idx_map.insert(pair<int,int>(*i,idx++));
		}        
		return helper(0,inorder.size());        
	}
	*/
	int cur = 0;
		
		TreeNode* build(const map<int,int>& m, const vector<int>& pre, int left, int right){
			if(left >= right) return nullptr;
			
			TreeNode* root = new TreeNode(pre[cur]);
			
			auto pairNode = m.find(pre[cur]);
			int index = pairNode->second;
			cur++;
			
			root->left = build(m, pre, left, index);
			root->right = build(m, pre, index+1, right);
			
			return root;
		}
		
		
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			map<int,int> m;
			for(int i = 0; i < inorder.size(); i++){
				m.insert({inorder[i],i});
			}
			return build(m, preorder, 0, inorder.size());
			
		}
	void preorder(TreeNode* root){
		if (root) {
			cout << root->val;
			cout << ' ';
		}
		if (root->left) {
			preorder(root->left);
		}
		if (root->right) {
			preorder(root->right);
		}
		
	}
};


int main(int argc, char *argv[]) {
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
	
	Solution* solution = new Solution();
	solution->preorder(solution->buildTree(preorder, inorder)); 
	
	
}