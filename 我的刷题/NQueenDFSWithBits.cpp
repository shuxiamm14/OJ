#include <iostream>

using namespace std;

static int sum = 0;
//使用位运算
void NQueensDFS(int n, int row, int col, int left, int right){
	if (row >= n) {
		sum ++;
		return;
	} else {
		int bits = (~(col | left | right)) & ((1 << n) - 1);
		while (bits > 0) {
			int p = bits & -bits;
			NQueensDFS(n, row + 1, col | p, (left | p) << 1, (right | p) >> 1);
			bits &= bits - 1;
		}
	}
}

int main(int argc, char *argv[]) {
	int m = 0;
	while (cin >> m) {
		NQueensDFS(m, 0, 0, 0, 0);
		cout << sum << endl;
		sum = 0;
	}
	
}