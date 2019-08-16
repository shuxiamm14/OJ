class Solution {
public:
	vector<string> res;
	
	vector<string> restoreIpAddresses(string s) {
		string temp;
		dfs(s,temp,0);
		return res;
	}
	
	void dfs(string s, string& temp, int word_num){
		if(word_num == 4){
			if(s.empty()) res.push_back(temp);
		}
		else{
			if(word_num > 0) temp += '.';
			for(int i = 1; i <= 3 && i <= s.length(); ++i){
				if(valid(s.substr(0,i))){
					temp += s.substr(0,i);
					dfs(s.substr(i,s.length()-i),temp,word_num+1);
					temp.erase(temp.length()-i,i);
				}
			}
			temp.pop_back();
		}
	}
	
	bool valid(const string& s){
		if(s.empty() || (s[0] == '0' && s.size()>1) ) return false;
		int val = stoi(s);
		if(val >= 0 && val <= 255) return true;
		return false;
	}
};