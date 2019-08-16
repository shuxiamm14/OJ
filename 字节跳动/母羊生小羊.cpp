#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	
	int n = 0;
	while(cin >> n){
		vector<int> res;
		
		res.push_back(0);
		res.push_back(1);
		int ret = 1;
		for(int i = 2; i < n+1; ++i){
			
			
			if(i-2<0){
				res.push_back(0);
			}
			else if(i-2>=0){
				int temp = 0;
				for(int j = i - 2; j >= 1 && j >= i - 6; --j){
					temp += res[j];
				}
				
				if(i-10>=1){
					temp -= res[i-10];	
				}
				
				
				res.push_back(temp);
				ret += temp;

			}	
			
		}
		
		cout << ret << endl;
		
		
		
	}
	
}