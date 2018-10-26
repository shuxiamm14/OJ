//泥塑课
#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int a[9], b[9], c[9], area[9];
		string name[8];
		if (n <= 9 && n >= 2) {
			for (int i = 0; i < n; i++) {
				cin >> a[i] >> b[i] >> c[i];
				cin >> name[i];
				area[i] = a[i] * b[i] * c[i];
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (area[j] > area[j + 1]) {
						int temp = area[j];
						area[j] = area[j + 1];
						area[j + 1] = temp;
						string name_temp = name[j];
						name[j] = name[j + 1];
						name[j + 1] = name_temp;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				if (i = n - 1) cout << name[i] << " took clay from ";
			}
			cout << name[0] << "." << endl;
		}
	}
	return 0;
}
