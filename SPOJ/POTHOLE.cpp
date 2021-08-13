#include <iostream>
#include <vector>
#include <queue>
#define  sz(A)			(int)(A).size()
#define  pb				push_back
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)	for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define  dbg(vari) cerr << #vari << " = " << (vari) << endl;
using namespace std;

const int LRG = 1e9;
struct Edge { int a, b, cap, flow; };

int n, m;
int s, t;

vector<Edge> edges;
vector<int> gr[200];
int dst[200];
int lst[200];

void add_edge(int a, int b, int cap)
{
	Edge e1 = {a, b, cap, 0};
	Edge e2 = {b, a, 0, 0};
	gr[a].pb(sz(edges));
	edges.pb(e1);
	gr[b].pb(sz(edges));
	edges.pb(e2);
}

bool bfs()
{
	fill(lst, lst+n, 0);
	fill(dst, dst+n, -1);
	queue<int> q;
	q.push(s);
	dst[s] = 0;
	
	while (!q.empty() && dst[t] == -1)
	{
		int v = q.front();
		q.pop();
		
		for (int i = 0; i < sz(gr[v]); i++)
		{
			int id = gr[v][i];
			int to = edges[id].b;
			
			if (dst[to] == -1 && edges[id].flow < edges[id].cap)
			{
				q.push(to);
				dst[to] = dst[v]+1;
			}
		}
	}
	
	return dst[t] != -1;
}

int dfs(int v, int flow)
{
	if (v == t)
		return flow;
	
	for (int pushed; lst[v] < sz(gr[v]); lst[v]++)
	{
		int id = gr[v][lst[v]];
		int to = edges[id].b;
		
		if (dst[to] == dst[v]+1 && edges[id].flow < edges[id].cap &&
			(pushed = dfs(to, min(flow, edges[id].cap-edges[id].flow))))
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
	int flow = 0, pushed;
	
	while (bfs())
	{
		while ((pushed = dfs(s, LRG)))
		{
			flow += pushed;
		}
	}
	
	return flow;
}

int tests;

int main()
{
	cin >> tests;
	
	for (int footests = 0; footests < tests; footests++)
	{
		edges.clear();
		for (int i = 0; i < 200; i++)
			gr[i].clear();
		
		cin >> n;
		m = n-1;
		s = 0;
		t = n-1;
		
		int niggas;
		
		cin >> niggas;
		for (int i = 0; i < niggas; i++)
		{
			int a = 1, b;
			cin >> b;
			a--;
			b--;
			add_edge(a, b, (a == 0 || b == n-1 ?1 :n));
		}
		
		for (int i = 1; i < m; i++)
		{
			cin >> niggas;
			for (int j = 0; j < niggas; j++)
			{
				int a = i+1, b;
				cin >> b;
				a--;
				b--;
				add_edge(a, b, (a == 0 || b == n-1 ?1 :n));
			}
		}
		
		cout << dinic() << "\n";
	}
	
	return 0;
}
