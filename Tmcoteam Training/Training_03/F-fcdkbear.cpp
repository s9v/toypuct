#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned
struct edge
{
	int v,cap;
};
int sz;
edge E[500100];
vector<vector<int> > g;
int d[1010];
int p[1010];
int ptr[1010];
const int N=10000010;
int f[N];

inline void addedge(int u, int v, int cap)
{
	g[u].push_back(sz);
	edge e={v,cap};
	E[sz++]=e;
	e.v=u; e.cap=0;
	g[v].push_back(sz);
	E[sz++]=e;
}
int dfs(int v, int cap)
{
	if (v==1)
		return cap;
	if (cap==0)
		return 0;
	for (int i=ptr[v]; i<g[v].size(); ++i,++ptr[v])
	{
		int to=E[g[v][i]].v;
		if (d[v]+1==d[to])
		{
			int k=dfs(to,min(cap,E[g[v][i]].cap));
			if (k)
			{
				E[g[v][i]].cap-=k;
				E[g[v][i]^1].cap+=k;
				return k;
			}
		}
	}
	return 0;
}
bool bfs(int s, int n)
{
	FOR(i,0,n)
		d[i]=-1;
	d[s]=0;
	p[0]=s;
	int l=0,r=0;
	while (l<=r)
	{
		int v=p[l++];
		if (v==1)
			return true;
		FOR(i,0,g[v].size())
		{
			if (E[g[v][i]].cap)
			{
				int to=E[g[v][i]].v;
				if (d[to]==-1)
				{
					p[++r]=to;
					d[to]=d[v]+1;
				}
			}
		}
	}
	return false;
}
int flow(int s, int t, int n)
{
	int res=0;
	while (1)
	{
		if (!bfs(s,n))
			break;
		
		FOR(i, 0, n)
			ptr[i]=0;
		
		while (1) {
			int v = dfs(s, 2000000000);
			if (v == 0)
				break;
			res+=v;
		}
	}
	return res;
}
inline int gcd(int a, int b)
{
	if (b==0)
		return a;
	return gcd(b,a%b);
}
inline int ngcd(int a, int b)
{
	while (1)
	{
		if (b==0)
			return a;
		int na=b;
		int nb=a%b;
		a=na,b=nb;
	}
}
int red[510];
int blue[510];
void gentest()
{
	freopen("out.txt","w",stdout);
	srand(time(NULL));
	FOR(it,0,100)
	{
		printf("500 500\n");
		FOR(i,0,500)
			printf("%d ",rand());
		FOR(i,0,500)
			printf("%d ",rand());
	}
	printf("0 0\n");
}
int main()
{
#ifdef Fcdkbear
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    double beg=clock();
#endif
	//gentest();
	//return 0;
	//MEMS(dp,-1);
	for (int i=2; i<N; ++i)
		if (f[i]==0)
		{
			f[i]=i;
			for (int j=i+i; j<N; j+=i)
				f[j]=i;
		}
	while (1)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if ((n==0) && (m==0))
			break;
		sz=0;
		g.clear();
		g.resize(n+m+2);
		FOR(i,0,n)
			scanf("%d",&red[i]);
		FOR(j,0,m)
			scanf("%d",&blue[j]);
		FOR(i,0,n)
			addedge(0,i+2,1);
		FOR(i,0,m)
			addedge(n+2+i,1,1);
		FOR(i,0,n)
			FOR(j,0,m)
			{
				int v=red[i];
				while (v>1)
				{
					if (blue[j]%f[v]==0)
					{
						addedge(i+2,n+2+j,1);
						break;
					}
					v/=f[v];
				}
			}
		int res=flow(0,1,n+m+2);
		cout<<res<<endl;
	}
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
	return 0;
}
