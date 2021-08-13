# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <functional> // greater<int>()
# include <vector>
# include <string>
# include <queue>
# include <stack>
# include <list>
# include <map>
# include <set>
# include <cstdio>
# include <cstdlib>
# include <cmath>
# include <ctime>
# include <cstring>
# include <cctype>
# include <climits> // LLONG_MAX , LLONG_MIN , INT_MAX , INT_MIN

/* MACROS */

# define  all(A)		(A).begin() , (A).end()
# define  rall(A)		(A).rbegin() , (A).rend()
# define  sz(A)			(int)(A).size()
# define  pb			push_back
# define  ppb			pop_back
# define  mp			make_pair
# define  bir			first
# define  iki			second
# define  rsz(A,X)		(A).resize(X)
# define  ln(A)			(int)(A).length()
# define  FILL(X, A)	memset((X), (A), sizeof(X))
# define  minof(X)		min_element(all(X))-X.begin()
# define  maxof(X)		max_element(all(X))-X.begin()
# define  square(X)		((X)*(X))
# define  cube(X)		((X)*(X)*(X))

# define  FOR(i, a, b)	for (int i=a; i<b; i++)
# define  FORD(i, a, b)	for (int i=a-1; i>=b; i--)
# define  REP(i,n)		for( int i=0 ; i<n ; i++ )
# define  REPD(i,n)		for( int i=n-1 ; i>=0 ; i-- )
# define  TR(it,container)  \
		for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
# define  setmap_found(container, element) (container.find(element) != container.end())
# define  vector_found(container, element) (find(all(container),element) != container.end())
# define  DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;

//time_t st=clock();

using namespace std;

/* TYPE DEFINITIONS */
typedef		long long		i64;
typedef		vector<int>		vi;
typedef		vector<vi>		vvi;
typedef		pair<int,int>	pi;
typedef		vector<pi>		vpi;
typedef		vector<vpi>		vvpi;
typedef		vector<i64>		v64;
typedef		vector<v64>		vv64;
typedef		pair<i64,i64>	p64;
typedef		vector<p64> 	vp64;
typedef		vector<vp64>	vvp64;
typedef		vector<string>	vs;
typedef		vector<vs>		vvs;
typedef		vector<bool>	vb;
typedef		vector<vb>		vvb;
typedef		vector<char>	vc;
typedef		vector<vc>		vvc;

/* TOOLS */
template <class T> inline T max(T a, T b, T c){   return max(a, max(b, c));   }
template <class T> inline T min(T a, T b, T c){   return min(a, min(b, c));   }
template <class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' '; cerr<<endl;}

/* ALGEBRA */
template <class T> T gcd (T a, T b){    return ( b==(T)0 ?a :gcd(b,a%b) );    }
template <class T> T lcm (T a , T b){    return a/gcd(a,b)*b;    }
template <class T> T mathround (T x){    i64 i64x=(i64)x; if( x<i64x+0.5 ) return (T)i64x; return (T)i64x+1;    }
template <class T> bool isprime(T x)
{
	int till = (T)sqrt(x+.0);
	if (x <= 1) return 0;
	if (x == 2) return 1;
	if (x%2 == 0) return 0;
	for (int i=3; i<=till; i+=2) if (x%i == 0) return 0;
	return 1;
}

/* CONSTANTS */
//const double Pi = 4.0 * atan(1.0); // 4*atan(1)
//int dir[8][2] = {{+1,+0},{-1,+0},{+0,+1},{+0,-1},{-1,-1},{+1,+1},{+1,-1},{-1,+1}};
//int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/* {END} */
const int LRG = 1e9;

class MaxMinTreeGame
{
	public:
		vector<int> gr[100];
		bool vis[100];
		int nleft;
		vector <int> costs;
		
		int findend(vector <int> edges, vector <int> costs2)
		{
			costs = costs2;
			int n = sz(costs);
			
			for (int i = 0; i < sz(edges); i++)
			{
				int a = i+1;
				int b = edges[i];
				
				gr[a].push_back(b);
				gr[b].push_back(a);
			}
			
			nleft = n;
			bool turn = 0;
			while (nleft > 1)
			{
				if (turn == 0)
				{
					int maxmin = -1;
					int thea = -1;
					int theb = -1;
					for (int i = 0; i < sz(edges); i++)
					{
						int a = i+1;
						int b = edges[i];
						
						if (vis[a] || vis[b])
							continue;
						
						int mina = dfsmin(a, -1, b);
						int minb = dfsmin(b, -1, a);
						
						if (maxmin < max(mina, minb))
						{
							maxmin = max(mina, minb);
							thea = a;
							theb = b;
							
							if (mina < minb)
								swap(thea, theb);
						}
					}
					
					use(theb, -1, thea);
				}
				else
				{
					int minmax = LRG;
					int thea = -1;
					int theb = -1;
					for (int i = 0; i < sz(edges); i++)
					{
						int a = i+1;
						int b = edges[i];
						
						if (vis[a] || vis[b])
							continue;
						
						int maxa = dfsmax(a, -1, b);
						int maxb = dfsmax(b, -1, a);
						
						if (minmax > min(maxa, maxb))
						{
							minmax = min(maxa, maxb);
							thea = a;
							theb = b;
							
							if (maxa > maxb)
								swap(thea, theb);
						}
					}
					
					use(theb, -1, thea);
				}
				
				turn ^= 1;
			}
			
			int res = -1;
			for (int i = 0; i < n; i++)
				if (!vis[i])
				{
					res = costs[i];
					break;
				}
			
			return res;
		}
		
		int dfsmin(int v, int pr, int bad)
		{
			int ret = costs[v];
			
			for (int i = 0; i < sz(gr[v]); i++)
			{
				int u = gr[v][i];
				
				if (u != pr && u != bad && !vis[u])
					ret = min(ret, dfsmin(u, v, bad));
			}
			
			return ret;
		}
		
		int dfsmax(int v, int pr, int bad)
		{
			int ret = costs[v];
			
			for (int i = 0; i < sz(gr[v]); i++)
			{
				int u = gr[v][i];
				
				if (u != pr && u != bad && !vis[u])
					ret = max(ret, dfsmax(u, v, bad));
			}
			
			return ret;
		}
		
		void use(int v, int pr, int bad)
		{
			vis[v] = true;
			nleft--;
			
			for (int i = 0; i < sz(gr[v]); i++)
			{
				int u = gr[v][i];
				
				if (u != pr && u != bad && !vis[u])
					use(u, v, bad);
			}
		}
};

/*
int main()
{
	
	
//	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);		// needs disabled ios_base::sync_with_stdio(false);
//	freopen("output.txt", "w", stdout);		// needs disabled ios_base::sync_with_stdio(false);
//	cin >> noskipws;
//	cin >> skipws;
	
	
	
//	cout<<clock()-st;
	return EXIT_SUCCESS;
}
*/
