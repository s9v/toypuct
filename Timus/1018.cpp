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

struct node
{
	int cld[4],clw[4];
	int nbr[4],nbw[4];
	int num;
	int cnt;
};

int  n,q;
int  a,b,app;
int  dp[100][101];
node p[100];

void f(int x,int parent)
{
	REP(i,p[x].num)
	if( p[x].nbr[i]!=parent )
	{
		p[x].cld[ p[x].cnt ]=p[x].nbr[i];
		p[x].clw[ p[x].cnt ]=p[x].nbw[i];
		p[x].cnt++;
	}
	
	REP(i,p[x].cnt)
	f(p[x].cld[i],x);
	
	dp[x][0]=0;
	
	if( p[x].cnt==1 )
	dp[x][1]=max(dp[x][1],p[x].clw[0]);
	
	else
	if( p[x].cnt==2 )
	dp[x][1]=max(p[x].clw[0],p[x].clw[1]);
	
	FOR(i,2,n)
	{
		if( p[x].cnt==0 )
		break;
		
		if( p[x].cnt==1 )
		{
			dp[x][i]=max(dp[x][i],dp[ p[x].cld[0] ][i-1]+p[x].clw[0]);
		}
		else
		if( p[x].cnt==2 )
		{
			dp[x][i]=max(dp[x][i],dp[ p[x].cld[0] ][i-1]+p[x].clw[0]);
			dp[x][i]=max(dp[x][i],dp[ p[x].cld[1] ][i-1]+p[x].clw[1]);
			
			REP(k,i-1)
			dp[x][i]=max(dp[x][i], dp[ p[x].cld[0] ][k]+dp[ p[x].cld[1] ][i-2-k]   +   p[x].clw[0]+p[x].clw[1]);
		}
		else { cout<<"THERE MUST NOT BE ANYTHING LIKE THIS !"; getchar(); }
	}
	
}

int main()
{
	cin>>n>>q;
	
	REP(i,n-1)
	{
		cin>>a>>b>>app;
		
		a--;
		b--;
		
		p[a].nbr[ p[a].num ]=b;
		p[a].nbw[ p[a].num ]=app;
		p[a].num++;
		
		p[b].nbr[ p[b].num ]=a;
		p[b].nbw[ p[b].num ]=app;
		p[b].num++;
	}
	
	f(0,0);
	
	cout<<dp[0][q];
	
	/*
	cout<<clock()-st;
	getchar();
	getchar();
	*/
	return 0;
}
