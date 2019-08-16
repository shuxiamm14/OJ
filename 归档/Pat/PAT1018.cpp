#include <iostream>
#include <map>
using namespace std;
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(int argc, char *argv[]) {
	int n = 0;
	while(cin >> n){
		map<char, int> m[2];
		m[0]['C']=0;
		m[0]['B']=0;
		m[0]['J']=0;
		m[1]['C']=0;
		m[1]['B']=0;
		m[1]['J']=0;
		int count_win[2] = {0};
		int count_lose[2] = {0};
		int count_equal[2] = {0};
		char p[100][2];
		for(int i = 0; i < n; i ++){
			cin >> p[i][0] >> p[i][1];		
		}
		for(int i = 0; i < n; i ++){
			if(p[i][0]==p[i][1]){
				count_equal[0]++;
				count_equal[1]++;
			}
			if(p[i][0]=='C'&&p[i][1]=='J'){
				count_win[0]++;
				m[0]['C']++;
				count_lose[1]++;
			}
			if(p[i][0]=='C'&&p[i][1]=='B'){
				count_win[1]++;
				m[1]['B']++;
				count_lose[0]++;
			}
			if(p[i][0]=='B'&&p[i][1]=='J'){
				count_win[1]++;
				m[1]['J']++;
				count_lose[0]++;
			}
			if(p[i][0]=='B'&&p[i][1]=='C'){
				count_win[0]++;
				m[0]['B']++;
				count_lose[1]++;
			}		
			
			if(p[i][0]=='J'&&p[i][1]=='C'){
				count_win[1]++;
				m[1]['C']++;
				count_lose[0]++;
			}
			if(p[i][0]=='J'&&p[i][1]=='B'){
				count_win[0]++;
				m[0]['J']++;
				count_lose[1]++;
			}	
		}
		cout << count_win[0] << ' ' <<count_equal[0] << ' ' << count_lose[0];
		cout << endl;
		cout << count_win[1] << ' ' <<count_equal[1] << ' ' << count_lose[1];
		cout << endl;
		int max_index_0 = max(max(m[0]['B'],m[0]['C']),m[0]['J']);
		if(m[0]['B']==max_index_0) cout << 'B';
		else if(m[0]['C']==max_index_0) cout << 'C';
		else if(m[0]['J']==max_index_0) cout << 'J';
		cout << ' ';
		int max_index_1 = max(max(m[1]['B'],m[1]['C']),m[1]['J']);
		if(m[1]['B']==max_index_0) cout << 'B';
		else if(m[1]['C']==max_index_0) cout << 'C';
		else if(m[1]['J']==max_index_0) cout << 'J';
		cout << endl;
		
		
	}
	
}