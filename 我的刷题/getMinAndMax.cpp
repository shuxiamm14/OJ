#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
	int n = 0;
	while (cin >> n) {
		//初始化
		vector<int> res;
		for (int i = 0; i < n; i++) {
			int temp = 0;
			cin >> temp;
			res.push_back(temp);
		}
		
		int max = res[0];
		int min = res[0];
		int delta = 0; //最大差值
		int count = 0; //计数
			
		//①O(n) = 1.5n
		//如果res[i] > max, 则max = res[i], delta = max - min;
		//如果res[i] < max && max - a[i] > delta, 则 min = res[i];
		//
		
		/*for (int i = 1; i < n; i++) {
			if (res[i]>max) {
				max = res[i];
				delta = max - min;
				count++;
			} else {
				count ++;
				if (max-res[i] > delta) {
					min = res[i];
					count++;
				}
			}
		
		}*/
		
		//② O(n) = n
		int deltaTemp = 0;
		for (int i = 1; i < n; i++) {
			if (res[i] - min > delta) {
				count++;
				delta = res[i] - min;
			} else {				
				if(res[i] - min < 0) {
					count ++;
					min = res[i];
					delta -= res[i] - min;
				} else {
					count ++;
				}				
			}		
		}
		if (delta > 0) {
			max = min + delta;
			count ++;
		} else if (delta == 0){
			max = max;
		}
		
		
		cout << "max:" << max << ',' << "min:" << min << ',' << "count:" << count << endl;
	
	}
}