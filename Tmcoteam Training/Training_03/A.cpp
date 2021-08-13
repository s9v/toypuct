#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#define  sz(X)    (int)X.size()
using namespace std;

int n;
int m = 'z'-'a'+1+'Z'-'A';
int f[100][100];
int c[100][100];
int pr[100];
int vis[100];
vector<int> gr[100];
int res;

int zet(char x) { // zet??
	if (isupper(x))
		return 'z'-'a'+1+x-'A';
	return x-'a';
}

void flood() {
	while (true) {
		fill(pr, pr+100, -1);
		fill(vis, vis+100, 0);
		
		queue<int> q;
		q.push(zet('A'));
		vis[zet('A')] = true;
		pr[zet('A')] = zet('A');
		
		while ( ! q.empty()) {
			int u = q.front();
			q.pop();
			
			for (int i = 0; i < sz(gr[u]); i++) {
				int v = gr[u][i];
				
				if (vis[v])
					continue;
				
				if (c[u][v]-f[u][v] > 0) {
					pr[v] = u;
					q.push(v);
					vis[v] = true;
				}
			}
		}
		
		if (pr[zet('Z')] == -1)
			break;
		
		int curflow = INT_MAX;
		for (int v = zet('Z'); v != zet('A') ; v = pr[v]) {
			int u = pr[v];
			curflow = min(curflow, c[u][v]-f[u][v]);
		}
		
		for (int v = zet('Z'); v != zet('A') ; v = pr[v]) {
			int u = pr[v];
			f[u][v] += curflow;
			f[v][u] -= curflow;
		}
		
		res += curflow;
	}
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		char a, b;
		int cap;
		cin >> a >> b >> cap;
		
		if (c[zet(a)][zet(b)] == 0) {
			gr[zet(a)].push_back(zet(b));
			gr[zet(b)].push_back(zet(a));
		}
		c[zet(a)][zet(b)] += cap;
		c[zet(b)][zet(a)] += cap;
	}
	
	flood();
	
	cout << res << "\n";
	
	return 0;
}
