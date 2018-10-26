#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	int n = 0;
	char in;
	while(cin >> n >> in){
		if(n<1) break;
		vector<int> v;
		for(int i = 1;i<=n; i+=2){
			v.push_back(i);
		}
		int k = 0;
		int max = (n+1)/2;
		while(max>=v[k]){
			max-=v[k++];
		}
		int index = k-1;
		int start = index;
		for(int i = 0;i<index;i++){
			for(int k =0; k < (v[index]-v[start])/2;k++){
				cout << ' ';
			}
			for(int j = 0;j<v[start];j++){
				n--;
				cout << in;
			}
			start--;
			cout << endl;
		}
		for(int i = 0;i<=index;i++){
			for(int k =0; k < (v[index]-v[start])/2;k++){
				cout << ' ';
			}
			for(int j = 0;j<v[start];j++){
				n--;
				cout << in;
				
			}
			start++;
			cout << endl;
		}
		
		cout << n << endl;
		
	}
}