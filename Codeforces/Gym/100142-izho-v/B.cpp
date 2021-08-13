#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <set>
#define  pb  push_back
#define  mp  make_pair
using namespace std;
typedef vector< pair<int,int> > vpi;
const int INF = 1e9;

int n, m;
int r1, r2;
vpi gr[100000];

int dist1[100000];
int dist2[100000];

void dijka(int start, int *dist)
{
	set< pair<int,int> > s;
	fill(dist, dist+n, INF);
	dist[start] = 0;
	s.insert(mp(dist[start], start));
	
	while ( ! s.empty())
	{
		int v = s.begin()->second;
		s.erase(s.begin());
		
		for (auto x: gr[v])
		{
			int u = x.first;
			int d = x.second;
			
			if (dist[u] > dist[v] + d)
			{
				s.erase(mp(dist[u], u));
				dist[u] = dist[v] + d;
				s.insert(mp(dist[u], u));
			}
		}
	}
}

set< pair<int, int> > brs;
int now;
int fup[100000];
int tin[100000];
bool vis[100000];

void dfs(int v, int pr)
{
	fup[v] = tin[v] = now++;
	vis[v] = true;
	
	for (auto x: gr[v])
	{
		int u = x.first;
		
		if (u == pr)
			continue;
		
		if (vis[u])
			fup[v] = min(fup[v], tin[u]);
		else
		{
			dfs(u, v);
			fup[v] = min(fup[v], fup[u]);
			if (tin[v] < fup[u])
				brs.insert(mp(v,u));
		}
	}
}

void fndbrs()
{
	now = 0;
	fill(vis, vis+n, 0);
	dfs(0, -1);
}

int main()
{
	ifstream fin("robots.in");
	ofstream fout("robots.out");
	
	fin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		fin >> a;
		fin >> b;
		fin >> c;
		a--;
		b--;
		gr[a].pb(mp(b, c));
		gr[b].pb(mp(a, c));
	}
	
	fin >> r1;
	fin >> r2;
	r1--;
	r2--;
	
	dijka(r1, dist1);
	dijka(r2, dist2);
	
	//~ cerr << "dist1 --> ";
	//~ for (int i = 0; i < n; i++)
		//~ cerr << dist1[i] << " ";
	//~ cerr << "\n";
	//~ cerr << "dist2 --> ";
	//~ for (int i = 0; i < n; i++)
		//~ cerr << dist2[i] << " ";
	//~ cerr << "\n";
	
	fndbrs();
	
	int res = INF;
	for (int v = 0; v < n; v++)
	{
		for (auto x: gr[v])
		{
			int u = x.first;
			if (brs.find(mp(v,u)) != brs.end() || brs.find(mp(u,v)) != brs.end())
			{
				res = min(res, max(dist1[v], dist2[u]));
				res = min(res, max(dist1[u], dist2[v]));
			}
		}
	}
	
	fout << res;
	
	return 0;
}
