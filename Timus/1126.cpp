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

# define  all(A)		(A).begin() , (A).end()
# define  rall(A)		(A).rbegin() , (A).rend()
# define  sz(A)			(int)(A).size()
# define  pb			push_back
# define  mp			make_pair
# define  fst			first
# define  snd			second
# define  rsz(A,X)		(A).resize(X)
# define  ln(A)			(int)(A).length()
# define  fill0(X, A)	memset((x), (a), sizeof(x))
# define  minof(X)		min_element(all(X))-X.begin()
# define  maxof(X)		max_element(all(X))-X.begin()

# define _n  \
		cout << endl
# define FOR(i, a, b)  \
		for (int i=a; i<b; i++)
# define FORD(i, a, b)  \
		for (int i=a-1; i>=b; i--)
# define  REP(i,n)  \
		for( int i=0 ; i<n ; i++ )
# define  REPD(i,n)  \
		for( int i=n-1 ; i>=0 ; i-- )
# define  REK(IDFR,EXPRESSION,CHANGE)  \
		for( int IDFR ; EXPRESSION ; CHANGE )
# define  TR(it,container)  \
		for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
# define  present(container, element) (container.find(element) != container.end()) 
# define  cpresent(container, element) (find(all(container),element) != container.end()) 

#define DBG(vari) cerr<<endl<<#vari<<" = "<<(vari)<<endl;

time_t st=clock();
using namespace std;

template <class stl>
void DBGSTL (stl a) { // for deque, vector , set
	cout<<"\tDEBUG:\n\t";
	TR(i,a){
		cerr<<*i<<" ";
	}
	cerr<<"\n";
	return;
}

typedef long long i64;

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

i64 gcd( i64 a , i64 b )
{    return ( b==0 ?a :gcd(b,a%b) );    }
i64 lcm( i64 a , i64 b )
{    return a/gcd(a,b)*b;    }
double mathround( double x )
{    int intx=(int)x; if( x<intx+0.5 ) return intx; return intx+1;    }

//int di[]={1, -1, 0, 0, 1, 1, -1, -1};
//int dj[]={0, 0, 1, -1, 1, -1, 1, -1};

int m, n;
int p[25000] , tmp;
int segtree[66000];

int query(int id, int l, int r, int ql, int qr)
{
	if( qr<ql )
	return 0;
	
	//cout << "[QUERY][ id="<<id<<" ][ l="<<l<<" ][ r="<<r<<" ][ ql="<<ql<<" ][ qr="<<qr<<" ]"; getchar();
	
	int ret = 0;
	
	int m = (l+r) / 2;
	
	if(ql <= l   &&   m <= qr)
	ret = max(ret, segtree[2*id]);
	
	else
	ret = max(ret, query(2*id, l, m, max(l,ql), min(m,qr)));
	
	if(ql <= m+1   &&   r <= qr)
	ret = max(ret, segtree[2*id+1]);
	
	else
	ret = max(ret, query(2*id+1, m+1, r, max(m+1,ql), min(r,qr)));
	
	return ret;
}

void init_segtree(int id, int l, int r)
{
	if(l == r)
	segtree[id] = p[l-1];
	
	else
	{
		int m = (l+r) / 2;
		
		init_segtree(2*id, l, m);
		init_segtree(2*id+1, m+1, r);
		
		segtree[id] = max(segtree[2*id], segtree[2*id+1]);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin >> m;
	
	while (cin >> tmp , tmp != -1)
	p[ n++ ] = tmp;
	
	init_segtree (1, 1, 32768);
	
	REP (i, n-m+1)
	cout << /*"*"<<i+1<<" *"<<i+m<<"   "<<*/ query (1, 1, 32768, i+1, i+m) << endl;
	
	/*
	cout<<clock()-st;
	getchar();
	getchar();
	*/
	return 0;
}
