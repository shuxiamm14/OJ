#include <iostream>

using namespace std;
int gcd(int m, int n) {
	return n == 0 ? m : gcd(n, m % n);
}
int main(int argc, char *argv[]) {
	int m = 0;
	int n = 0;
	while (cin >> m >> n){
		cout << gcd(m, n) << endl;
	}
}