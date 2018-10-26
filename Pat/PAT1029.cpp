#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	string s1;
	string s2;
	while(cin >> s1 >> s2){
		int length_s1 = s1.size();
		int length_s2 = s2.size();
		for(int i = 0,j = 0; i < length_s1 && j < length_s2; ){
			if(s1[i]=='_'){
				i++;
				continue;
			}
			if(s1[j]=='_'){
				j++;
				continue;
			}
			if(s1[i]==s2[j]){
				i++;
				j++;
			}
			else{
				cout << s1[i];
				j = 0;
				i++;
				
			}
		}
	}
}