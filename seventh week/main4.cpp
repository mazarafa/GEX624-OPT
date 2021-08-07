#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int p;
		cin >> p;
		// it can be observed that the remainder of dividing 'p' by 2 and ('p' - 1) 
		// is equal to 1, so the answer is always 2 and the number before 'p' ('p' - 1)
		cout << 2 << " " << p - 1 << '\n';
	}
	return 0;
}