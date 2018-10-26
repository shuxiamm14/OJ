#include <iostream>

using namespace std;
const char Day[8][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(int argc, char *argv[]) {
	string s[4];
	while(cin >> s[0] >> s[1] >> s[2] >> s[3]){
		int day = 0;
		int h = 0;
		int m = 0;
		int count = 0;
		for(int i = 0;i <s[0].size(); i++){
			for(int j = 0; j < s[1].size(); j++){
				if(s[0][i]>='0'&&s[0][i]<='9'&&s[1][j]>='0'&&s[1][j]<='9'&&count==0)continue;
				if(s[0][i]==s[1][j]&&count == 1){
					if(s[0][i]>='0'&&s[0][i]<='9')
						h = s[0][i] - '0';
					if(s[0][i]>='A'&&s[0][i]<='Z')
						h = s[0][i] - 'A' + 11;
				}
				if(s[0][i]==s[1][j]&&count == 0){
					count ++;
					if(s[0][i]>='A'&&s[0][i]<='Z')
						day = s[0][i] - 'A';
					if(s[0][i]>='a'&&s[0][i]<='z')
						day = s[0][i] - 'a';
				}
				
			}
			
		}
		int flag = 0;
		for(int i = 0;i <s[2].size(); i++){
			for(int j = 0; j < s[3].size(); j++){
				if(s[2][i]==s[3][j]&&flag == 0){
					m = j;
					flag = 1;
				}
			}
			
		}
		if(m<10)
			cout << Day[day] << ' '<< h << ":0" << m << endl;
		else
			cout << Day[day] << ' '<< h << ':' << m << endl;
	}
	
}