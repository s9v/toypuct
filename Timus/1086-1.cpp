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
# define  frt			first
# define  scd			second
# define  rsz(A,X)		(A).resize(X)
# define  ln(A)			(int)(A).length()
# define  mmmset(X, A)	memset((x), (a), sizeof(x))

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

#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;

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
typedef		pair<int,int>	pii;
typedef		vector<pii>		vpii;
typedef		vector<vpii>	vvpii;
typedef		vector<i64>		vll;
typedef		vector<vll>		vvll;
typedef		pair<i64,i64>	pll;
typedef		vector<pll> 	vpll;
typedef		vector<vpll>	vvpll;
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

//                   up       down      left     right                              up_l     down_r     up_r      down_l
//int dir[8][2]={ {-1,+0} , {+1,+0} , {+0,-1} , {+0,+1} /* add diagonals --> */ , {-1,-1} , {+1,+1} , {-1,+1} , {+1,-1} };

int  k,n;
bool p1[10000000];
int  p2[15010],np2;

int main()
{
	p1[0]=p1[1]=1;
	
	for (int i=4 ; i<10000000 ; i+=2)
	p1[i]=1;
	
	for (int i=3 ; i*i<10000000 ; i+=2)
	if( !p1[i] )
	{
		for (int j=i*i ; j<10000000 ; j+=i)
		p1[j]=1;
	}
	
	REP(i,10000000)
	if( !p1[i] )
	{
		if( np2>15000 )
		break;
		
		p2[ np2++ ]=i;
	}
	
	cin>>k;
	
	REP(i,k)
	{
		cin>>n;
		cout<<p2[n-1]<<endl;
	}
	
	/*
	cout<<clock()-st;
	getchar();
	getchar();
	*/
	return 0;
}
