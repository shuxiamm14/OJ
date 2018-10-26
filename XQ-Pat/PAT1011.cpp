#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	int n = 0;
	while(cin >> n){
		double p[11][3]={0};
		if(n>10||n<0) continue;
		int a,b,c;
		for(int i = 0; i < n; i++){
			cin >> p[i][0] >> p[i][1] >> p[i][2];
		}
		for(int i = 0; i < n; i++){
			if(p[i][0]+p[i][1]>p[i][2])	cout << "Case #" << i+1 <<':' << " true" << endl;
			else cout << "Case #" << i+1 <<':' << " false" << endl;
		}
		
		
		
		
	}
	return 0;
}