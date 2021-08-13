// https://gist.github.com/moogod/8036675

#include <iostream>
using namespace std;
const int M = 128; // pigeons
const int N = 128; // holes
 
bool graph[M][N];
bool seen[N];
int matchL[M];
int matchR[N];
int n, m;
 
bool bpm(int u)
{
	for (int v = 0; v < n; v++)
		if (graph[u][v]) {
			if (seen[v])
				continue;
			
			seen[v] = true;
			
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
	cin >> m; // pigeons
	cin >> n; // holes
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	
	fill(matchL, matchL+M, -1);
	fill(matchR, matchR+N, -1);
	
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		fill(seen, seen+N, 0);
		
		if (bpm(i))
			cnt++;
	}
	
	// cnt contains the number of happy pigeons
	// matchL[i] contains the hole of pigeon i or -1 if pigeon i is unhappy
	// matchR[j] contains the pigeon in hole j or -1 if hole j is empty
	
	cout << "cnt -> " << cnt << "\n";
	cout << "matchings :\n";
	for (int i = 0; i < m; i++)
		cout << i+1 << " -> " << matchL[i]+1 << "\n";
	 
	return 0;
}
