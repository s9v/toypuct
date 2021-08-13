/*
* METU-Upem, Training Contest #3
* Problem C - Sistem Muhendisi
* Maximum Bipartite Matching, Hopcroft-Karp algorithm
* 
* (Original)
* https://gist.github.com/moogod/8036667
* 
* (Modified)
* https://github.com/sylap/YAYAPS/Algorithms/Matching/hopcroftkarp.cpp
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXM = 200000;
const int MAXN = 10001;

int N, E;
int adj[MAXM], nxt[MAXM], lst[MAXN];
int Mx[MAXN], My[MAXN];

int Q[MAXM], dist[MAXM];

inline void init()
{
	E = 0;
	for (int i = 0; i < N; i++) {
		lst[i] = -1;
		Mx[i] = My[i] = -1;
	}
}

inline void addedge(int u, int v)
{
	adj[E] = v;
	nxt[E] = lst[u];
	lst[u] = E++;
}

int bfs()
{
	int st, en, i, u, v, e, flag = 0;
	st = en = 0;
	
	for (i = 0; i < N+N; i++)
		dist[i] = 0;
	
	for (i = 0; i < N; i++)
		if (Mx[i] == -1)
			Q[en++] = i;
	
	while (st < en) {
		u = Q[st++];
		
		for (e = lst[u]; e != -1; e = nxt[e]) {
			v = adj[e];
			
			if (dist[v+N])
				continue;
			 
			dist[v+N] = dist[u] + 1;
			
			if (My[v] != -1) {
				dist[My[v]] = dist[v+N] + 1;
				Q[en++] = My[v];
			}
			else
				flag = 1;
		}
	}
	
	return flag;
}
 
int dfs(int u)
{
	int e, v;
	for (e = lst[u]; e != -1; e = nxt[e]) {
		v = adj[e];
		
		if (dist[v+N] != dist[u]+1)
			continue;
		
		dist[v+N] = 0;
		
		if (My[v] == -1 || dfs(My[v])) {
			Mx[u] = v;
			My[v] = u;
			return 1;
		}
	}
	
	return 0;
}
 
void matching()
{
	int res = 0;
	 
	while (bfs()) {
		for (int i = 0; i < N; i++)
			if (Mx[i] == -1 && dfs(i))
				++res;
	}
	
	printf("%d\n", res);
}
 
int main()
{
	int n, m, cnt;
	char c1, c2, c3;
	
	while (1) {
		cin >> N;
		
		if (N == 0)
			break;
		
		init();
		
		for (int i = 0; i < N; i++) {
			cin >> n >> c1 >> c2 >> cnt >> c3;
			
			for (int j = 0; j < cnt; j++) {
				cin >> m;
				addedge(n, m-N);
			}
		}
		
		matching();
	}
	
	return 0;
}
