#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	vector<int> m;
	for(int i = 0; i < 10; i ++){
		int a = 0;
		cin >> a;
		while(a--){
			m.push_back(i);
		}
	}
	sort(m.begin(),m.end());
	int index = 0;
	for(int i = 0;i<m.size();){
		if(m[i]==0){
			i++;
		}
		else{
			index = i;
			break;
		}
	}
	cout << m[index];
	for(int i = 0; i<m.size();i++){
		if(i!=index)
		cout << m[i];
	}
	cout << endl;
	
}