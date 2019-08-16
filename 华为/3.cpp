#include <iostream>
#include <vector>
using namespace std;

bool find(string a, char b){
	
	for(int i = 0; i < a.size(); i++){
		
		if(a[i]==b){
			return true;
		}
	}
	
	return false;
	
	
	
	
}
int fun(vector<string> a, vector<string> b, int n){
	
	int sum = 0;
	for(int k = 0; k < n; k++){
		
		int i = 0;
		int j = 0;
		
		int replace = 0;
		if(a[k].size()!=b[k].size()){
			
			
			while(j<b[k].size()){
					
					
				if(!find(a[k],b[k][j])){
					sum++;
					
				}
					
					
				j++;
			}
				
			while(i<a[k].size()){
				
						
				if(!find(b[k],a[k][i])){
					sum++;
					
				}
						
						
				i++;	
			}
		}
		else{
			while(j<b[k].size()){
	
				if(!find(a[k],b[k][j])){
					sum++;
					
				}
					
					
				j++;
			}
				
			
		}
				
		
	}
	
	return sum;
	
}


int main(int argc, char *argv[]) {
	
	
	int n = 0;
	
	while(cin >> n){
		vector<string> resBefore;
		vector<string> resAfter;
		
			
		for(int  j = 0; j < n; j++){
			string temp;
			cin >> temp;
			resBefore.push_back(temp);				
		}
			
		for(int  j = 0; j < n; j++){
			string temp;
			cin >> temp;
			resAfter.push_back(temp);
		}
		
		
		
		cout << fun(resBefore, resAfter, n) << endl;
		
		
		
	}
}