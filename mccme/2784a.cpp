// sylap97's implementation of «Dinic's Max-flow Algorithm»

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#define  sz(A)			(int)(A).size()
#define  pb				push_back
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)	for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define  dbg(vari) cerr << #vari << " = " << (vari) << endl;
using namespace std;

typedef long long llint;

// solution starts ...

const int MAXN = 1000; // number of vertices
const int INF = 1e9; // infinity
struct Edge { int a, b, cap, flow; };

int n, m, s, t;
int dst[MAXN]; // distance from s
int ptr[MAXN]; // continue the search after finding some augpath
vector<Edge> edges; // all edges
vector<int> graph[MAXN]; // graph

void add_edge (int a, int b, int cap)
{
	Edge e1 = {a, b, cap, 0};
	Edge e2 = {b, a, 0, 0};
	graph[a].pb(sz(edges));
	edges.pb(e1);
	graph[b].pb(sz(edges));
	edges.pb(e2);
}

bool bfs()
{
	fill(ptr, ptr+n, 0);
	fill(dst, dst+n, -1);
	queue<int> q; // queue for bfs
	
	q.push(s);
	dst[s] = 0;
	while (!q.empty() && dst[t] == -1)
	{
		int v = q.front();
		q.pop();
		
		for (int i = 0; i < sz(graph[v]); ++i)
		{
			int id = graph[v][i];
			int to = edges[id].b;
			
			if (dst[to] == -1 && edges[id].flow < edges[id].cap)
			{
				q.push(to);
				dst[to] = dst[v] + 1;
			}
		}
	}
	
	return dst[t] != -1;
}

int dfs (int v, int flow)
{
	if (v == t)
		return flow;
	
	for (int pushed; ptr[v] < sz(graph[v]); ptr[v]++)
	{
		int id = graph[v][ptr[v]];
		int to = edges[id].b;
		
		if (dst[to] == dst[v] + 1 && edges[id].flow < edges[id].cap &&
			(pushed = dfs(to, min(flow, edges[id].cap-edges[id].flow))) > 0)
		{
			edges[id].flow += pushed;
			edges[id^1].flow -= pushed;
			return pushed;
		}
	}
	
	return 0;
}

llint dinic()
{
	llint flow = 0;
	
	while (bfs())
		while (int pushed = dfs (s, INF))
			flow += pushed;
	
	return flow;
}

int main()
{
	scanf("%d %d", &n, &m);
	s = 0;
	t = n-1;
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		add_edge(a, b, c);
	}
	
	printf("%lld\n", dinic());
	
	return 0;
}
