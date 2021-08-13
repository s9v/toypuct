// MarioYC's implementation of «Dinic's Algorithm»

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>
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

struct flow_graph {
    static const int MAX_V = 500;
    static const int MAX_E = 10000;
    
    int E,s,t,head,tail;
    int cap[2 * MAX_E],to[2 * MAX_E],next[2 * MAX_E],last[MAX_V],dist[MAX_V],q[MAX_V],now[MAX_V];
    
    flow_graph(){
        E = 0;
        memset(last,-1,sizeof last);
    }
    
    void clear(){
        E = 0;
        memset(last,-1,sizeof last);
    }
    
    void add_edge(int u, int v, int uv){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = 0, next[E] = last[v]; last[v] = E++;
    }
	
    bool bfs(){
        memset(dist,-1,sizeof dist);
        head = tail = 0;
		
        q[tail] = t; ++tail;
        dist[t] = 0;
		
        while(head < tail){
            int v = q[head]; ++head;
            
            for(int e = last[v];e != -1;e = next[e]){
                if(cap[e^1] > 0 && dist[to[e]] == -1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }
        
        return dist[s] != -1;
    }
	
    int dfs(int v, int f){
        if(v == t) return f;
		
        for(int &e = now[v];e != -1;e = next[e]){
            if(cap[e] > 0 && dist[to[e]] == dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]));
				
                if(ret > 0){
                    cap[e] -= ret;
                    cap[e^1] += ret;
                    return ret;
                }
            }
        }
		
        return 0;
    }
	
    llint max_flow(int source, int sink){
        s = source; t = sink;
        llint f = 0,df;
		
        while(bfs()){
            for(int i = 0;i <= sink;++i) now[i] = last[i];
			
            while(true){
                df = dfs(s,INT_MAX);
                if(df == 0) break;
                f += df;
            }
        }
		
        return f;
    }
};

flow_graph dinicus;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		dinicus.add_edge(a, b, c);
	}
	
	printf("%lld\n", dinicus.max_flow(0, n-1));
	
	return 0;
}
