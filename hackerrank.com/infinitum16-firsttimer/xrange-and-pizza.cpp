#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	int loc = 0;
	bool rev = false;

	for (int i = 0; i < m; ++i) {
		int type, k;

		scanf("%d %d", &type, &k);

		if (type == 1) {
			loc = (loc + 2*k) % (2*n);
		}
		else {
			rev ^= true;
			loc = (2*k - loc + 2*n) % (2*n);
		}
	}

	if (rev) {
		printf("2 %d", loc/2);
	}
	else {
		printf("1 %d", (2*n - loc)/2);
	}
}