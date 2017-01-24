#include <bits/stdc++.h>
#define sz(X) (int)(X).size()
using namespace std;

int p[200100];
vector<int> fixpts;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		p[i]--;
		if (p[i] == i)
			fixpts.push_back(i);
	}

	printf("%d\n", (sz(fixpts)+1)/2);
	for (int i = 0; i < sz(fixpts); i += 2) {
		if (i+1 < sz(fixpts)) {
			printf("%d %d\n", fixpts[i]+1, fixpts[i+1]+1);
		}
		else {
			printf("%d %d\n", fixpts[i]+1, (fixpts[i] != 0 ?0 :1)+1);
		}
	}

	return 0;
}