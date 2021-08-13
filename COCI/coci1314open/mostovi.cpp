#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional> // greater<int>()
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <climits> // LLONG_MAX , LLONG_MIN , INT_MAX , INT_MIN

/* MACROS */

#define  all(A)			(A).begin() , (A).end()
#define  rall(A)		(A).rbegin() , (A).rend()
#define  sz(A)			(int)(A).size()
#define  pb				push_back
#define  ppb			pop_back
#define  mp				make_pair
#define  ln(X)			(int)(X).length()
#define  square(X)		((X)*(X))
#define  cube(X)		((X)*(X)*(X))
#define  y1				thisisnotnonsenseasyoumaythinkaskmethenilltellyouwhatthisreallyis
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)	for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define  dbg(vari) cerr << #vari << " = " << (vari) << endl;

//time_t st = clock();

using namespace std;

/* TYPE DEFINITIONS */
typedef		long long		i64;
typedef		vector<int>		vi;
typedef		pair<int,int>	pi;

/* TOOLS */
template <class T> void debug(T a,T b){ for (; a != b; a++) cerr << *a << ' '; cerr << endl; }

/* ALGEBRA */
template <class T> bool isprime(T x) {
	int till = (T)sqrt(x+.0);
	if (x <= 1) return 0;
	if (x == 2) return 1;
	if (x%2 == 0) return 0;
	for (int i = 3; i <= till; i += 2) if (x%i == 0) return 0;
	return 1;
}

/* { CONST } */
// const double Pi = acos(-1.0);
// int dir[8][2] = {{+1, +0}, {-1, +0}, {+0, +1}, {+0, -1}, {-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}};
// int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* { END } */

const int MAXN = 1010;
const int LRG = 1e9;

int n, m;
bool rd[2*MAXN];
vi br[2*MAXN];
bool vis[2*MAXN];

string res;

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n-1; i++)
		rd[i] = 1;
	
	for (int i = n+1; i <= 2*n-1; i++)
		rd[i] = 1;
	
	cin >> m;
	
	if (n > MAXN)
	{
		for (int fooevent = 0; fooevent < m; fooevent++)
			cout << "DA\n";
		return 0;
	}
	
	char cmd;
	int g1, g2;
	for (int fooevent = 0; fooevent < m; fooevent++)
	{
		cin >> cmd;
		cin >> g1 >> g2;
		
		if (cmd == 'A')
		{
			br[g1].pb(g2);
			br[g2].pb(g1);
		}
		else if (cmd == 'B')
		{
			rd[min(g1, g2)] = 0;
		}
		else if (cmd == 'Q')
		{
			queue<int> Q;
			fill(vis+1, vis+1+2*n, 0);
			Q.push(g1);
			vis[g1] = 1;
			
			while (!Q.empty())
			{
				int nd = Q.front();
				Q.pop();
				
				// dbg(nd);
				
				if (1 <= nd && nd < n && rd[nd] == 1 && !vis[nd+1])
				{
					Q.push(nd+1);
					vis[nd+1] = 1;
				}
				if (n+1 < nd && nd <= 2*n && rd[nd-1] == 1 && !vis[nd-1])
				{
					Q.push(nd-1);
					vis[nd-1] = 1;
				}
				
				for (auto v: br[nd])
				if (!vis[v])
				{
					Q.push(v);
					vis[v] = 1;
				}
			}
			
			cout << (vis[g2] ?"DA" :"NE") << "\n";
		}
	}
	
//	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);		// needs disabled ios_base::sync_with_stdio(false);
//	freopen("output.txt", "w", stdout);		// needs disabled ios_base::sync_with_stdio(false);
//	cin >> noskipws;
//	cin >> skipws;
	
//	cout << clock() - st;
//	getchar();
//	getchar();
	
	return EXIT_SUCCESS;
}
