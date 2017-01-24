#include <bits/stdc++.h>
#define ln(S) (S).length()
#define sz(V) (V).size()
#define pb push_back
using namespace std;

typedef vector<int> vi;

const int LARGE = 1e9;

int dmin[5100];
int dmax[5100];

int fib[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};

int main() {
	int n;
	int nfib = sizeof(fib) / sizeof(int);

	scanf("%d", &n);

	fill(dmin, dmin + n + 1, LARGE);
	fill(dmax, dmax + n + 1, -LARGE);

	dmin[0] = 0;
	dmax[0] = 0;

	for (int i = 1; i < nfib; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j-fib[i] >= 0) {
				dmin[j] = min(dmin[j], dmin[j - fib[i]] + fib[i-1]);
				dmax[j] = max(dmax[j], dmax[j - fib[i]] + fib[i-1]);
			}
		}
	}

	printf("%d %d", dmin[n], dmax[n]);

	return 0;
}