给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

示例:
输入: S = "a1b2"
输出: ["a1b2", "a1B2", "A1b2", "A1B2"]

输入: S = "3z4"
输出: ["3z4", "3Z4"]

输入: S = "12345"
输出: ["12345"]
注意：

S 的长度不超过12。
S 仅由数字和字母组成。


分析

回溯算法，遍历字符串，判断是数字，大写字母，小写字母，做相应的处理。

数字的时候直接添加到字符串temp后面然后递归，如果是字母，需要把字母本身添加到temp字符串后面，递归完之后还要把字母本身从temp后面去掉，然后将其变身（大写变小写，小写变大写）放到temp字符串后面再递归调用。


class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> v;
        bt(v,S,0);
        return v;
    }
    void bt(vector<string>& v,string s,int i){
        if(i==s.length()){
            v.push_back(s);
            return;
        }
        if(s[i]>='a'&&s[i]<='z'){
            bt(v,s,i+1);
            s[i] = s[i]-'a'+'A';
            bt(v,s,i+1);
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            bt(v,s,i+1);
            s[i] = s[i]-'A'+'a';
            bt(v,s,i+1);
        }
        else
            bt(v,s,i+1);
    }
};


class Solution {
public:
    vector<string> ans;
    void fun(string str,int n){
        if(n==str.size()){
            ans.push_back(str);
            return;
        }
        fun(str,n+1);
        
        if(str[n]>='a'&&str[n]<='z'){
            str[n]=str[n]-'a'+'A';
            fun(str,n+1);
        }
        else if(str[n]>='A'&&str[n]<='Z'){
            str[n]=str[n]-'A'+'a';
            fun(str,n+1);
        }
    }
    vector<string> letterCasePermutation(string S) {
        fun(S,0);
        return ans;
    }
};