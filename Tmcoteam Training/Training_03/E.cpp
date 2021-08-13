#include <iostream>
#include <cassert>
#include <cmath>
#include <map>
using namespace std;
const int INF = 1000000000;

int n, m, k;
int nplg;
map<string, int> plg;
string tmp;
string tmp2;

int rec[200];
int dev[200];
int admx[500][500];
bool vis[200];
int matchL[200];
int matchR[200];
int res;

int gettype(string x) {
	if (plg.find(x) == plg.end())
		plg[x] = nplg++;
	return plg[x];
}

bool bpm(int u) {
	for (int v = 0; v < n; v++)
		if (admx[ dev[u] ][ rec[v] ] != INF) {
			if (vis[v])
				continue;
			
			vis[v] = true;
			
			if (matchR[v] < 0 || bpm(matchR[v])) {
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}
	
	return false;
}

int main()
{
	fill(admx[0], admx[500], INF);
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		rec[i] = gettype(tmp);
	}
	
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> tmp >> tmp;
		dev[i] = gettype(tmp);
	}
	
	cin >> k;
	
	for (int i = 0; i < k; i++) {
		cin >> tmp >> tmp2;
		admx[gettype(tmp)][gettype(tmp2)] = 1;
	}
	
	for (int i = 0; i < nplg; i++)
		admx[i][i] = 0;
	
	for (int k = 0; k < nplg; k++)
	for (int i = 0; i < nplg; i++)
	for (int j = 0; j < nplg; j++)
	if (admx[i][k] != INF && admx[k][j] != INF)
	admx[i][j] = min(admx[i][j], admx[i][k] + admx[k][j]);
	
	fill(matchL, matchL+100, -1);
	fill(matchR, matchR+100, -1);
	
	for (int i = 0; i < m; i++) {
		fill(vis, vis+100, 0);
		
		if ( ! bpm(i))
			res++;
	}
	
	cout << res << "\n";
	
	return 0;
}
