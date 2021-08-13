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
bool rdn[MAXN];
bool rds[MAXN];
vi brn[MAXN];
vi brs[MAXN];

string res;

int main()
{
	cin >> n;
	
	fill(rdn, rdn+MAXN, 1);
	fill(rds, rds+MAXN, 1);
	
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
		g1--;
		g2--;
		
		if (cmd == 'A')
		{
			if (g1 > g2) // g1 from **south**, g2 from **north**
			{
				g1 -= n;
				swap(g1, g2);
			}
			else // g1 from **north**, g2 from **south**
				g2 -= n;
			
			brn[g1].pb(g2);
			brs[g2].pb(g1);
		}
		else if (cmd == 'B')
		{
			if (g1 < n) // g1 and g2 are from **north** side
			{
				if (g1 > g2)
					swap(g1, g2);
				
				rdn[g1] = 0;
			}
			else // g1 and g2 are from **south** side
			{
				if (g1 > g2)
					swap(g1, g2);
				
				g1 -= n;
				g2 -= n;
				
				rds[g1] = 0;
			}
		}
		else if (cmd == 'Q')
		{
			if (g1 > g2) // g1 from **south**, g2 from **north**
			{
				g1 -= n;
				
				res = "NE";
				
				for (int g3 = g1; g3 >= 0; g3--)
				{
					int g4 = -1;
					
					for (auto v: brs[g3])
						if (v <= g2)
							g4 = max(g4, v);
					
					if (g4 != -1)
					{
						res = "DA";
						
						while (rdn[g4] == 1 && g4 < g2) g4++;
						
						if (g4 != g2)
							res = "NE";
						
						break;
					}
					
					if (g3 > 0 && rdn[g3-1] == 0)
						break;
				}
				
				cout << res << "\n";
			}
			else // g1 from **north**, g2 from **south**
			{
				g2 -= n;
				res = "NE";
				
				for (int g3 = g1; g3 < n; g3++)
				{
					int g4 = LRG;
					
					for (auto v: brn[g3])
						if (v >= g2)
							g4 = min(g4, v);
					
					if (g4 != LRG)
					{
						res = "DA";
						g4--;
						
						while (rds[g4] == 1 && g4 > g2) g4--;
						
						if (g4 != g2)
							res = "NE";
						
						break;
					}
					
					if (rdn[g3] == 0)
						break;
				}
				
				cout << res << "\n";
			}
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
