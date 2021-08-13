#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1e9;

int T;
int n;
int x[1000];
int nx;
int y[1000];
int ny;
int demonx[1000];
int demony[1000];
vector<int> gr[1000];

int maxmatch;
int matchL[1000];
int matchR[1000];
int dist[1000];
bool vis[1000];

void bfs()
{
	fill(dist, dist+1000, INF);
	queue<int> Q;
	for (int v = 0; v < nx; v++)
		if (matchL[v] < 0)
		{
			dist[v] = 0;
			Q.push(v);
		}

	while ( ! Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for (auto u: gr[v])
		{
			int w = matchR[u];

			if (w >= 0 && dist[w] == INF)
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
	for (auto u: gr[v])
	{
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
	fill(matchL, matchL+1000, -1);
	fill(matchR, matchR+1000, -1);

	while (true)
	{
		bfs();

		fill(vis, vis+1000, 0);

		int f = 0;
		for (int v = 0; v < nx; v++)
			if (matchL[v] < 0 && dfs(v))
				f++;

		if (f == 0)
			break;

		maxmatch += f;
	}
}

inline int pressd(int *arr, int arrn, int tgt)
{
	return lower_bound(arr, arr+arrn, tgt)-arr;
}

int main()
{
	for (cin >> T; T; T--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
			demonx[i] = x[i];
			demony[i] = y[i];
		}

		sort(x, x+n);
		nx = unique(x, x+n)-x;

		sort(y, y+n);
		ny = unique(y, y+n)-y;

		for (int i = 0; i < 1000; i++)
			gr[i].clear();

		for (int i = 0; i < n; i++)
		{
			int xid = pressd(x, nx, demonx[i]);
			int yid = pressd(y, ny, demony[i]);

//			cerr << xid << " " << yid << " <pressd\n";

			gr[xid].push_back(yid);
		}

		bpm();

		cout << maxmatch << "\n";
	}

	return 0;
}
