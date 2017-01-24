#include <bits/stdc++.h>
#define sz(X) (int)(X).size()
using namespace std;

int n;
int l[200100];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &l[i]);
	}

	sort(l, l+n);

	if (l[n-1] - l[0] + 1 <= l[0] + l[1] - 1) {
		printf("YES\n%d\n", l[n-1] - l[0] + 1);
	}
	else {
		printf("NO\n");
	}

	return 0;
}