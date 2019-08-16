#include <iostream>

using namespace std;

bool IsPowerOfTwo(int x){
	return x > 0 && !(x & (x-1));
}

int main(int argc, char *argv[]) {
	int n = 0;
	while (cin >> n) {
		if (IsPowerOfTwo(n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
}