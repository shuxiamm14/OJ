//函数规律
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int count = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '0' || s[i] == '6' || s[i] == '9'){
            ++count;
        }else if(s[i] == '8'){
            count += 2;
        }
    }
    cout << count << endl;
}
