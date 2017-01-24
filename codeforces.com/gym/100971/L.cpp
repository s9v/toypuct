#include <bits/stdc++.h>
#define sz(X) (int)(X).size()
#define ln(X) (int)(X).length()
using namespace std;

int n;
int a[200100];
int b[200100];

bool wins(int *a, int *b) { // a wins over b
	int score = 0;
	
	int i = 0;
	int j = 0;
	while (i < n && j < n) {
		if (b[j] < a[i]) {
			score++;
			j++;
		}

		i++;
	}

	return score >= n/2 + 1;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(a, a+n);
	sort(b, b+n);

	bool awin = wins(a, b);
	bool bwin = wins(b, a);

	if (awin && bwin) {
		cout << "Both";
	}
	else if (awin) {
		cout << "First";
	}
	else if (bwin) {
		cout << "Second";
	}
	else {
		cout << "None";
	}

	return 0;
}