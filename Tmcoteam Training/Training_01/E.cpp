#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#define  sz(X)		(int)X.size()
#define  mp(A,B)	make_pair(A,B)
#define  pb(X)		push_back(X)
using namespace std;
typedef pair<int,int> pi;
typedef vector< int > vi;
typedef vector< pi >  vpi;
const int INF = 1000000000;

int N;
int P, Q;
vpi g[1000000];
vpi gr[1000000];
bool vis[1000000];
int dst[1000000];
int res[1000000];

void dijk(int start, vpi G[1000000]) {
	fill(vis, vis+1000000, 0);
	fill(dst, dst+1000000, INF);
	
	dst[start] = 0;
	
	set<pi> s;
	s.insert(mp(dst[start], start));
	
	while (!s.empty()) {
		int cur = s.begin()->second;
		s.erase(s.begin());
		vis[cur] = 1;
		
		for (int i = 0; i < sz(G[cur]); i++) {
			int to = G[cur][i].first;
			int len = G[cur][i].second;
			
			if (!vis[to] && dst[to] > dst[cur]+len) {
				s.erase(mp(dst[to], to));
				dst[to] = dst[cur]+len;
				s.insert(mp(dst[to], to));
			}
		}
	}
}

int main() {
	cin >> N;
	
	while (N--) {
		cin >> P >> Q;
		
		for (int i = 0; i < P; i++)
			g[i].clear();
		
		for (int i = 0; i < P; i++)
			gr[i].clear();
		
		for (int i = 0; i < Q; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			g[a].pb(mp(b, c));
			gr[b].pb(mp(a, c));
		}
		
		dijk(0, g);
		
		fill(res, res+1000000, 0);
		for (int i = 0; i < P; i++)
			res[i] += dst[i];
		
		dijk(0, gr);
		
		for (int i = 0; i < P; i++)
			res[i] += dst[i];
		
		cout << accumulate(res, res+P, 0) << "\n";
	}
	
	return 0;
}
