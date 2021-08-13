#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
#define  pb  push_back
#define  mp  make_pair
#define  sz(X)  (int)X.size()
#define  ln(X)  (int)X.length()
 using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int INF = 1e9;

int n, m;
vpii gr[250];
pii paths[25000];
int bada, badb;

int dist[250];

int dijka()
{
	int start = 0;
	int finish = n-1;
	
	set<pii> s;
	fill(dist, dist+n, INF);
	dist[start] = 0;
	s.insert(mp(dist[start],start));
	
	while (!s.empty())
	{
		int v = s.begin()->second;
		s.erase(s.begin());
		
		for (int i = 0; i < sz(gr[v]); i++)
		{
			int u = gr[v][i].first;
			int l = gr[v][i].second;
			
			if ((v == bada && u == badb) || (v == badb && u == bada))
				l *= 2;
			
			if (dist[u] > dist[v]+l)
			{
				s.erase(mp(dist[u],u));
				dist[u] = dist[v]+l;
				s.insert(mp(dist[u],u));
			}
		}
	}
	
	return dist[finish];
}

int main()
{
	ifstream fin("rblock.in");
	ofstream fout("rblock.out");
	
	fin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b, l;
		fin >> a >> b >> l;
		a--;
		b--;
		paths[i] = mp(a,b);
		gr[a].pb(mp(b,l));
		gr[b].pb(mp(a,l));
	}
	
	bada = -1;
	badb = -1;
	int res = dijka();
	
	int mxres = 0;
	for (int i = 0; i < m; i++)
	{
		bada = paths[i].first;
		badb = paths[i].second;
		mxres = max(mxres, dijka());
	}
	
	fout << mxres-res;
	
	return 0;
}
