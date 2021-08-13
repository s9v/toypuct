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

//                   up       down      left     right                              up_l     down_r     up_r      down_l
//int dir[8][2]={ {-1,+0} , {+1,+0} , {+0,-1} , {+0,+1} /* add diagonals --> */ , {-1,-1} , {+1,+1} , {-1,+1} , {+1,-1} };

struct mstruct
{
	i64 x;
	i64 y;
	i64 d;
	string s;
};

i64 n,m;
i64 x,y;
vector<mstruct> p;
vpll dp;
bool b1,b2;

bool mcomp(mstruct a,mstruct b)
{
	if( a.x==b.x )
	return a.y<b.y;
	
	return a.x<b.x;
}

int main()
{
	cin>>n>>m;
	
	rsz(p,m);
	rsz(dp,n);
	
	REP(i,n)
	dp[i].frt=LLONG_MAX , dp[i].scd=LLONG_MAX;
	
	REP(i,m)
	cin>>p[i].x>>p[i].y>>p[i].d>>p[i].s;
	
	sort(all(p),mcomp);
	
	dp[0].frt=0;
	dp[0].scd=0;
	
	for (int i=0 ; i<m ; i++)
	{
		x=p[i].x-1;
		y=p[i].y-1;
		
		b1=(dp[x].frt!=LLONG_MAX);
		b2=(dp[x].scd!=LLONG_MAX);
		
		if( p[i].s=="Pirated" )
		{
			if( b1 ) dp[y].scd=min(dp[y].scd, dp[x].frt+p[i].d );
			if( b2 ) dp[y].scd=min(dp[y].scd, dp[x].scd+p[i].d );
		}
		else
		{
			if( b1 ) dp[y].frt=min(dp[y].frt, dp[x].frt+p[i].d );
			
			if( b2   &&   dp[x].scd!=0   &&   p[i].s=="Cracked" )
			dp[y].scd=min(dp[y].scd, dp[x].scd+p[i].d );
		}
	}
	
	if( dp[n-1].frt==LLONG_MAX && dp[n-1].scd==LLONG_MAX )
	cout<<"Offline";
	
	else
	{
		cout<<"Online\n";
		cout<<min(dp[n-1].frt,dp[n-1].scd);
	}
	
	/*
	cout<<clock()-st;
	getchar();
	getchar();
	*/
	return 0;
}
