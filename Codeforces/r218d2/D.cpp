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

const int MAXST = 262144;

int n, m;
int a[200000];
int c[200000];
int st[2*MAXST];

void upd(int nd, int ndl, int ndr, int p, int val) {
	if (p < ndl || ndr < p)
		return;
	
	if (ndl == ndr) {
		c[p] += val;
		st[nd] = (a[p] == c[p] ?-1 :p);
	}
	else {
		upd(2*nd+1, ndl, (ndl+ndr)/2, p, val);
		upd(2*nd+2, (ndl+ndr)/2+1, ndr, p, val);
		
		if (st[2*nd+1] != -1)
			st[nd] = st[2*nd+1];
		else if (st[2*nd+2] != -1)
			st[nd] = st[2*nd+2];
		else
			st[nd] = -1;
	}
}
void upd(int p, int val) {
	upd(0, 0, MAXST-1, p, val);
}
int fnd(int nd, int ndl, int ndr, int pl, int pr) {
	if (pr < ndl || ndr < pl)
		return -1;
	
	if (pl <= ndl && ndr <= pr) {
		return st[nd];
	}
	else {
		int a = fnd(2*nd+1, ndl, (ndl+ndr)/2, pl, pr);
		int b = fnd(2*nd+2, (ndl+ndr)/2+1, ndr, pl, pr);
		
		if (a != -1)
			return a;
		else if (b != -1)
			return b;
		else
			return -1;
	}
}
int fnd(int p) {
	return fnd(0, 0, MAXST-1, p, n-1);
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	fill(st, st+2*MAXST, -1);
	for (int i = 0; i < n; i++)
		upd(i, 0);
	
	cin >> m;
	for (int asdf = 0; asdf < m; asdf++) {
		int cmd;
		cin >> cmd;
		
		if (cmd == 1) {
			int p, x;
			cin >> p >> x;
			p--;
			
			int cur = fnd(p);
			while (cur != -1) {
				if (x <= a[cur]-c[cur]) {
					upd(cur, x);
					break;
				}
				else {
					x -= a[cur]-c[cur];
					upd(cur, a[cur]-c[cur]);
					cur = fnd(cur);
				}
			}
		}
		else if (cmd == 2) {
			int k;
			cin >> k;
			k--;
			cout << c[k] << "\n";
		}
	}
	
	
//	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);		// needs disabled ios_base::sync_with_stdio(false);
//	freopen("output.txt", "w", stdout);		// needs disabled ios_base::sync_with_stdio(false);
//	cin >> noskipws;
//	cin >> skipws;
	
	
	
//	cout<<clock()-st;
	/*
	getchar();
	getchar();
	*/
	return EXIT_SUCCESS;
}
