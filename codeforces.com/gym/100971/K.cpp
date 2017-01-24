#include <bits/stdc++.h>
#define sz(X) (int)(X).size()
#define ln(X) (int)(X).length()
using namespace std;

int n;
string s;

int diffloc(int l, int r) {
	int lorig = l;
	while (l <= r) {
		if (s[l] != s[r])
			return l-lorig;
		l++;
		r--;
	}

	return -1;
}

int main() {
	cin >> s;

	n = ln(s);

	int idx = diffloc(0, n-1);

	if (idx == -1) {
		cout << "YES\n";
		cout << n/2 + (1);
	}
	else {
		if (diffloc(0 + idx + 1, n-1 - idx) == -1) {
			cout << "YES\n";
			cout << 0 + idx + (1);
		}
		else if (diffloc(0 + idx, n-1 - idx - 1) == -1) {
			cout << "YES\n";
			cout << n-1 - idx + (1);
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}