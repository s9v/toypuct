/*
BISMILLAHIRAHIMANIRRAHIM
*/

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
# define  ppb			pop_back
# define  mp			make_pair
# define  bir			first
# define  iki			second
# define  rsz(A,X)		(A).resize(X)
# define  ln(A)			(int)(A).length()
# define  fill0(X, A)	memset((X), (A), sizeof(X))
# define  minof(X)		min_element(all(X))-X.begin()
# define  maxof(X)		max_element(all(X))-X.begin()
# define  square(X)		(X)*(X)
# define  cube(X)		(X)*(X)*(X)
# define  _n			'\n'

# define _nn  \
		cout << _n
# define _dbgn  \
		cerr << _n
# define _seperate  \
		cerr << "\n===============================================================\n"
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
	cerr<<"\tDEBUG:\n\t";
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

/* [+++] BASIC - BASIC - BASIC */
template <class T>
inline T max(T a, T b, T c)
{   return max(a, max(b, c));   }

template <class T>
inline T min(T a, T b, T c)
{   return min(a, min(b, c));   }
/* [---] BASIC - BASIC - BASIC */

/* [+++] MATH - MATH - MATH */
template <class T>
T gcd (T a, T b)
{    return ( b==(T)0 ?a :gcd(b,a%b) );    }

template <class T>
T lcm (T a , T b)
{    return a/gcd(a,b)*b;    }

template <class T>
T mathround (T x)
{    i64 i64x=(i64)x; if( x<i64x+0.5 ) return (T)i64x; return (T)i64x+1;    }

template <class T>
bool isprime(T x)
{
	int till = (T)sqrt(x+.0);
	if (x%2 == 0) return 0;
	for (int i=3; i<=till; i+=2) if (x%i == 0) return 0;
	return 1;
}
/* [---] MATH - MATH - MATH */


/* [+++] GEOMETRY - GEOMETRY - GEOMETRY */
template <class T>
double point_dist(T x1, T y1, T x2, T y2)
{   return sqrt( square(x1-x2) + square(y1-y2) + .0 );   }
/* [---] GEOMETRY - GEOMETRY - GEOMETRY */

const double Pi = 4.0 * atan(1.0);

//int di[]={1, -1, 0, 0, 1, 1, -1, -1};
//int dj[]={0, 0, 1, -1, 1, -1, 1, -1};
//int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int n,k;
int a[2000];
int b[2000];
int c[2000];
int d[2000];

int main()
{
	cin >> n >> k;
	
	a[0] = 0;
	b[0] = k-1;
	
	int r;
	for (int i=1; i<n; i++)
	{
		REP(j,2000)
		c[j] = b[j];
		
		r = 0;
		for (int j=0; j<2000; j++)
		{
			d[j]	=	( a[j]+b[j]+r   )%10;
			r		=	( a[j]+b[j]+r   )/10;
		}
		
		r = 0;
		for (int j=0; j<2000; j++)
		{
			int X = d[j];
			
			d[j]	=	(X*(k-1)+r)%10;
			r		=	(X*(k-1)+r)/10;
		}
		
		REP(j,2000)
		a[j] = c[j];
		REP(j,2000)
		c[j] = 0;
		
		REP(j,2000)
		b[j] = d[j];
		REP(j,2000)
		d[j] = 0;
	}
	
	r = 0;
	for (int j=0; j<2000; j++)
	{
		d[j]	=	(   ( a[j]+b[j] )+r   )%10;
		r		=	(   ( a[j]+b[j] )+r   )/10;
	}
	
	int  f  = 1999;
	bool st = false;
	while (f >= 0)
	{
		if(d[f] > 0)
		st = true;
		
		if(st)
		cout << d[f];
		
		f--;
	}
	
//	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);		// needs disabled ios_base::sync_with_stdio(false);
//	freopen("output.txt", "w", stdout);		// needs disabled ios_base::sync_with_stdio(false);
//	cin >> noskipws;
//	cin >> skipws;
	
	
	
	/*
	cout<<clock()-st;
	getchar();
	getchar();
	*/
	return EXIT_SUCCESS;
}
