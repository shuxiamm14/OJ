#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool prime(int n){
		int i;
		for(i=2;i<=(int)sqrt((double)n);i++)
			if(n%i==0)
				return 0;
		return 1;
}



int main(int argc, char *argv[]) {
	int m = 0;
	int n = 0;
	while(cin>>m>>n){
		if(n<m)break;
		if(n>10000||m>10000||n<0||m<0) break;
		int count = 1;
		vector<int> res;
		for(int i = 2; count <= n;i++){
			if(prime(i)){
				count ++;
				res.push_back(i);
			}
		}
		int count_row = 0;
		for(int i = m-1; i < n;i++){
			count_row ++;
			cout << res[i];
			if(count_row%10==0){
				cout << endl;
			}
			else if(i!=n-1) cout << ' ';
		}
		
		
		
	}
}