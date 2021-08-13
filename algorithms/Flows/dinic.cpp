/*
 *
 *
 *
 */
#define _CRT_SECURE_NO_DEPRECATE 1
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define FORD(i, a, b) for (i = (a); i >= (b); i--)
#define REP(i, n) for (i = 0; i < (n); i++)
#define REPD(i, n) for (i = ((n)-1); i >= 0; i--)
#define CLR(x, with) memset((x), with, sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define PB push_back
#define INF 2000000000

#ifndef ONLINE_JUDGE
	FILE* fi = freopen("input.txt", "r", stdin);
	//FILE* fo = freopen("out.txt", "w", stdout);
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template <class T> int SZ(T x) { return x.size(); }
template <class T> void getMax(T& a, T b) { if (b > a) a = b; }

#define MAXN 5003
#define MAXE 60003

int adj[MAXE], next[MAXE];
int last[MAXN];
int cap[MAXE], flow[MAXE];

int source, sink;
int N, E;

int level[MAXN], Q[MAXN];

inline void Init(int _V, int _src, int _sink)
{
	source = _src;
	sink = _sink;
	N = _V;
	E = 0;
	for (int i = 0; i < N; i++) last[i] = -1;
}

inline void addEdge(int u, int v, int d)
{
	adj[E] = v; cap[E] = d; flow[E] = 0; next[E] = last[u]; last[u] = E++;
	adj[E] = u; cap[E] = d; flow[E] = 0; next[E] = last[v]; last[v] = E++;
}

bool bfs(int s, int t)
{
	int i, u, v, st, en;

	for (i = 0; i < N; i++) level[i] = -1;
	st = en = 0;
	Q[en++] = s;
	level[s] = 0;

	while (st < en)
	{
		u = Q[st++];
		for (int e = last[u]; e != -1; e = next[e])
		{
			v = adj[e];
			if (level[v] == -1 && flow[e] < cap[e])
			{
				Q[en++] = v;
				level[v] = level[u]+1;
			}
		}
	}
	return level[t] != -1;
}

int now[MAXN];

int dfs(int s, int t, int f)
{
	if (s == t)
		return f;

	int e, d;
	for (e = now[s]; e != -1; now[s]=e=next[e])
		if (level[adj[e]] > level[s] && cap[e] > flow[e])
		{
			d = dfs(adj[e], t, min(f, cap[e]-flow[e]));
			if (d > 0)
			{
				flow[e] += d;
				flow[e^1] -= d;
				return d;
			}
		}
	return 0;
}

LL maxflow(int s, int t)
{
	int i;
	while (bfs(s, t))
	{
		for (i = 0; i < N; i++)
			now[i] = last[i];
		while (dfs(s, t, INF) > 0);
	}
	LL res = 0;
	for (i = last[s]; i != -1; i = next[i]) res += flow[i];
	return res;
}

int main()
{	
	int M, i, u, v, d;

	scanf("%d%d", &N, &M);	
	Init(N, 0, N-1);
	
	REP(i, M)
	{
		scanf("%d%d%d", &u, &v, &d);
		--u; --v;
		addEdge(u, v, d);
	}
	
	LL res = maxflow(source, sink);
	printf("%lld\n", res);
	
	return 0;
}
