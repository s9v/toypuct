#include <bits/stdc++.h>
using namespace std;

typedef long long llint;

int n, m;

int P[10009][109];
int T[10009];

llint sum(int x) {
	llint s = 0;

	for (int i = 0; i < n; ++i) {
		s += abs(T[i] - T[x]);
	}

	return s;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &P[i][j]);
		}
	}

	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			T[i] = P[i][j];
		}

		sort(T, T+n);

		int l = 0;
		int r = n-1;

		while (r-l >= 3) {
			int m1 = l + (r-l)/3;
			int m2 = r - (r-l)/3;

			if (sum(m1) <= sum(m2)) {
				r = m2;
			}
			else {
				l = m1;
			}
		}

		int x = -1;

		for (int i = l; i <= r; ++i) {
			if (x == -1 || sum(i) < sum(x)) {
				x = i;
			}
		}

		printf("%d ", T[x]);
	}

	return 0;
}