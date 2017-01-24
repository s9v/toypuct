#include <bits/stdc++.h>
#define dbg(X) cerr << #X << " -> " << (X) << endl
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	for (int _case = 1; _case <= T; _case++) {
		int n, m;
		scanf("%d %d", &n, &m);

		multiset<int> heaps[310];
		int bought[310];
		int totcost = 0;

		for (int i = 0; i < n; i++) {
			bought[i] = 0;
			
			for (int j = 0; j < m; j++) {
				int c;
				scanf("%d", &c);
				heaps[i].insert(c);
			}

			int idx = i;

			for (int j = 0; j < i; j++)
			if ( not heaps[j].empty() && *heaps[j].begin() + 2*bought[j] + 1 < *heaps[idx].begin() + 2*bought[idx] + 1) {
				idx = j;
			}

			totcost += *heaps[idx].begin() + 2*bought[idx] + 1;
			bought[idx]++;
			heaps[idx].erase(heaps[idx].begin());
		}

		printf("Case #%d: %d\n", _case, totcost);
	}

	return 0;
}
