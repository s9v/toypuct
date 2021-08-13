#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define  sz(A)			(int)(A).size()
#define  pb				push_back
using namespace std;

const int MAXN = 1000; // number of vertices
const int INF = 1e9; // infinity
struct Edge { int a, b, cap, flow; };

int n, s, t;
int dst[MAXN]; // distance from s
int ptr[MAXN]; // continue the search after finding some augpath
queue<int> q; // queue for bfs
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
	fill(dst, dst+n, -1);
	dst[s] = 0;
	
	q.push(s);
	while (!q.empty() && dst[t] == -1)
	{
		int v = q.front();
		q.pop();
		
		for (int i = 0; i < sz(graph[v]); ++i)
		{
			int id = graph[v][i];
			int to = edges[id].b;
			
			if (dst[to] == -1 && edges[id].cap - edges[id].flow > 0)
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
		
		if (dst[to] == dst[v] + 1 && (pushed = dfs(to, min(flow, edges[id].cap-edges[id].flow))) > 0)
		{
			edges[id].flow += pushed;
			edges[id^1].flow -= pushed;
			return pushed;
		}
	}
	
	return 0;
}

int dinic()
{
	int flow = 0;
	
	while (bfs())
	{
		fill(ptr, ptr+n, 0);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	
	return flow;
}

int main()
{
	// Wheehee :D
	
	return 0;
}
