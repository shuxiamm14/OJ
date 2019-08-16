#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > part(vector<vector<int> > a){
	
	int n = a.size();
	vector<vector<int> > ret = a;
	
	for(int i = 0; i < n; i ++){
		
		for(int j = 0; j < n; j++){
			
			ret[j][n-i-1] = a[i][j];
		}
		
	}
	
	return ret;
	
}


vector<vector<int> > fun(vector<vector<int> >a, int b){
	
	if(b == 0) return a;
	
	else if(b == 1) return part(a);

	else if(b == 2) return part(part(a));
	
	else return part(part(part(a)));
	
	
}



int main(int argc, char *argv[]) {
	int n = 0;
	
	while(cin >> n){
		
		vector<vector<int> > res;
		
		for(int i = 0; i < n; i ++){
			vector<int> temp;
			for(int j = 0; j < n; j++){
				int a = 0;
				cin >> a;
				temp.push_back(a);
			}
			res.push_back(temp);
		}
		
		int m = 0;
		cin >> m;
		
		vector<vector<int> > ret;
		
		ret = fun(res, m%4);
		
		for(int i = 0; i < n; i ++){
			
			for(int j = 0; j < n; j++){
				cout << ret[i][j] << ' ';
			}
			cout << endl;
		}
		
		
		
	}
}