#include <bits/stdc++.h>
#define ln(S) (S).length()
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long llint;

int k;
int w[(1<<21)];

llint ans = 0;

llint dfs(int v, int h) {
	if (h == k) {
		return 0;
	}
	else {
		llint dist1 = dfs(2*v+1, h+1) + w[2*v+1];
		llint dist2 = dfs(2*v+2, h+1) + w[2*v+2];

		// cerr << dist1 << " " << dist2 << "\n";

		ans += abs(dist1 - dist2);

		return max(dist1, dist2);
	}
}

int main() {
	// cerr << (1<<21);
	scanf("%d", &k);

	int n = (1 << (k+1)) - 1;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d", &w[i]);
	}

	dfs(0, 0);

	for (int i = 0; i < n; ++i)
	{
		ans += w[i];
	}

	cout << ans;

	return 0;
}
