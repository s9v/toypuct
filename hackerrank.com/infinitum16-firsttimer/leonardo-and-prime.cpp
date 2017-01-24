#include <bits/stdc++.h>
using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int main() {
	int q;
	scanf("%d", &q);

	while (q--) {
		long long n;
		scanf("%lld", &n);

		int ans = 0;
		long long prd = 1;

		while (prd <= n/primes[ans]) {
			prd *= primes[ans];
			ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}