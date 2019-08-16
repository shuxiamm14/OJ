#include <iostream>
#include <vector>
using namespace std;


void fun(vector<int> &a, int start, int end, int k, int length){
	
	
	int max = 0;
	
	

	for(int count = 0; count < k; count++){
		vector<int> b;
		b = a;
		
		int h = 0;
		int sum = 0;
		
		for(int i = start; i >= 0 && i >= start - count; --i){
			if(b[i] == 0){
				b[i] = 1;
				sum ++;
				h++;
			}
			else if(b[i] == 1){
				h++;
				continue;
			}
		
		}
		for(int j = end; j < b.size() && j <= k - count - sum; ++ j){
			
			if(b[j] == 0){
				b[j] = 1;
				h++;
			}
			else if(b[j] == 1){
				h++;
				continue;
			}
			
		}
		
		if(h > length) {
			length = h;
			
			a = b;
			
		}
		
	}
	
	
	
	
	
}


int main(int argc, char *argv[]) {
	int n = 0;
	int k = 0;
	
	while(cin >> n >> k){
		vector<int> res;
		for(int i = 0; i < n; ++i){
			int temp = 0;
			cin >> temp;
			res.push_back(temp);
			
		}
		int index = 0;
		int length = 0;
		int max = 0;
		for(int i = 0; i < n; ++i){
			if(res[i] == 0) {
				length = 0;
				continue;
				
			}
			
			
			length ++;
			if(max < length) {
				max = length;
				index = i;
			}
			
		}

		
		int start = index - length + 1;
		
		fun(res, start - 1, index + 1, k, length);
		
		
		length = 0;
		max = 0;
		for(int i = 0; i < n; ++i){
			if(res[i] == 0) {
				length = 0;
				continue;
				
			}
			length ++;
			if(max < length) {
				max = length;
				index = i;
			}
		}
		
		for(int i = 0; i < n; ++i){
			cout << res[i] << ' ';
		}
		cout << max << endl;
		
		
		
	}
}