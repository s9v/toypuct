#include <bits/stdc++.h>
#define dbg(X) cerr << #X << " -> " << (X) << endl
#define A 0
#define B 1
using namespace std;

const int INF = 1e9;

int main() {
	int T;
	scanf("%d", &T);

	for (int _case = 1; _case <= T; _case++) {
		int n, m, f;
		int dist[110][110];
		int t[5010][2];
		
		scanf("%d %d %d", &n, &m, &f);
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = (i == j ?0 :INF);
		
		for (int i = 0; i < m; i++) {
			int a, b, g;
			scanf("%d %d %d", &a, &b, &g);
			a--;
			b--;
			dist[a][b] = g;
			dist[b][a] = g;
		}
		
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (dist[i][k] < INF && dist[k][j] < INF)
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		
		bool impossible = false;
		
		for (int i = 0; i < f; i++) {
			scanf("%d %d", &t[i][A], &t[i][B]);
			t[i][A]--;
			t[i][B]--;
			
			if (dist[ t[i][A] ][ t[i][B] ] == INF /*|| (i > 0 && dist[ t[i-1][B] ][ t[i][A] ] == INF)*/) {
				impossible = true;
			}
		}
		
		if (impossible) {
			printf("Case #%d: %d\n", _case, -1);
			continue;
		}
		
		int dp[110][2];
		
		// base cases
		dp[0][A] = dist[ 0 ][ t[0][A] ];
		dp[0][B] = dp[0][A] + dist[ t[0][A] ][ t[0][B] ];
		
		for (int i = 1; i < f; i++) {
			dp[i][A] = dp[i-1][B] + dist[ t[i-1][B] ][ t[i][A] ];
			dp[i][B] = min(
						dp[i-1][B] + dist[ t[i-1][B] ][ t[i][A] ] + dist[ t[i][A] ][ t[i][B] ],
						dp[i-1][A] + dist[ t[i-1][A] ][ t[i][A] ] + dist[ t[i][A] ][ t[i-1][B] ] + dist[ t[i-1][B] ][ t[i][B] ]
						);
		}
		
		printf("Case #%d: %d\n", _case, dp[f-1][B]);
	}

	return 0;
}
