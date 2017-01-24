#include <bits/stdc++.h>
#define ln(S) (S).length()
#define sz(V) (V).size()
#define pb push_back
using namespace std;

typedef vector<int> vi;

int t;
int n, m;

vi gr[1100];
int vis[1100];

bool dfs(int v, int clr) {
	vis[v] = clr;

	for (auto w: gr[v])
		if (vis[w] == 0) {
			if (! dfs(w, (clr == 1 ?2 :1)))
				return false;
		}
		else if (vis[w] != (clr == 1 ?2 :1)) {
			return false;
		}

	return true;
}

int main() {
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; ++i)
			gr[i].clear();

		fill(vis, vis+n, 0);

		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);

			a--;
			b--;

			gr[a].pb(b);
			gr[b].pb(a);
		}

		bool fine = true;

		for (int i = 0; i < n && fine; ++i)
			if (vis[i] == 0) {
				fine = fine && dfs(i, 1);
			}

		printf("%s\n", (fine ?"possible" :"impossible"));
	}

	return 0;
}