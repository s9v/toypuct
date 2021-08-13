#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#define  sz(X)  (int)X.size()
using namespace std;
typedef long long llint;
const int LRG = 1e9;

int T;
int p;
int n;
vector<int> gr[100];

int matchL[100];
int matchR[300];
int dist[100];
bool vis[100];
int maxmatch;

void bfs()
{
	fill(dist, dist+100, LRG);
	queue<int> Q;
	for (int v = 0; v < p; v++)
		if (matchL[v] < 0)
		{
			dist[v] = 0;
			Q.push(v);
		}
	
	while ( ! Q.empty())
	{
		int v = Q.front();
		Q.pop();
//		cerr << v << " " << dist[v] << " <bfs\n";

		for (int i = 0; i < sz(gr[v]); i++)
		{
			int u = gr[v][i];
			int w = matchR[u];

			if (w >= 0 && dist[w] == LRG)
			{
				dist[w] = dist[v]+1;
				Q.push(w);
			}
		}
	}
}

bool dfs(int v)
{
	vis[v] = true;

	for (int i = 0; i < sz(gr[v]); i++)
	{
		int u = gr[v][i];
		int w = matchR[u];

		if (w < 0 || (!vis[w] && dist[w] == dist[v]+1 && dfs(w)))
		{
			matchL[v] = u;
			matchR[u] = v;
			return true;
		}
	}

	return false;
}

void bpm()
{
	maxmatch = 0;
	fill(matchL, matchL+100, -1);
	fill(matchR, matchR+300, -1);

	while (true)
	{
		bfs();
		fill(vis, vis+100, 0);

		int f = 0;
		for (int v = 0; v < p; v++)
			if (matchL[v] < 0 && dfs(v))
				f++;

		if (f == 0)
			break;

		maxmatch += f;

//		cerr << "================\n";
	}
}

int main()
{
	cin >> T;

	for (int test = 0; test < T; test++)
	{
		for (int i = 0; i < 100; i++)
			gr[i].clear();

		cin >> p >> n;
		for (int i = 0; i < p; i++)
		{
			int cnt;
			cin >> cnt;
			
			for (int j = 0; j < cnt; j++)
			{
				int x;
				cin >> x;
				x--;
				gr[i].push_back(x);
			}
		}

		bpm();

		/*
		cerr << maxmatch << "\n";
		for (int i = 0; i < p; i++)
			cerr << matchL[i] << " ";
		cerr << "\n";
		*/

		cout << (maxmatch == p ?"YES" :"NO") << "\n";
	}

	return 0;
}
