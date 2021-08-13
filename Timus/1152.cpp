# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <functional>
# include <vector>
# include <queue>
# include <list>
# include <map>
# include <set>
# include <ctime>
# include <cstring>
# include <cctype>
# include <climits> // LLONG_MAX , LLONG_MIN , INT_MAX , INT_MIN

# define  all(A)	A.begin() , A.end()
# define  rall(A)	A.rbegin() , A.rend()
# define  sz(A)		(int)A.size()
# define  rsz(A,X)	A.resize(X)
# define  ln(A)		A.length()
# define  rep(i,n)  \
		for( int i=0 ; i<n ; i++ )
# define  repd(i,n)  \
		for( int i=n-1 ; i>=0 ; i-- )
# define  tr(it,container)  \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
# define  present(container, element) (container.find(element) != container.end()) 
# define  cpresent(container, element) (find(all(container),element) != container.end()) 

time_t st=clock();
using namespace std;

typedef long long i64;
typedef vector<int> vi;
typedef vector<vi> vvi;

i64 gcd( i64 a , i64 b )
{    return ( b==0 ?a :gcd(b,a%b) );    }
i64 lcm( i64 a , i64 b )
{    return a/gcd(a,b)*b;    }

int n;
int p[30];
i64 min_cost=LLONG_MAX;
i64 q1[30];
i64 q2[30];
i64 s1[30],s2[30],s3[30];
i64 k,l,sm;

i64 res[30];
i64 szr;

void f( i64 th , i64 add , i64 sum )
{
	q1[th]=add;
	
	if( sum<n )
	{
		if( sum+1<=n ) f(th+1,1,sum+1);
		if( sum+2<=n ) f(th+1,2,sum+2);
		if( sum+3<=n ) f(th+1,3,sum+3);
	} else if( sum==n ) {
		rep(y,3)
		{
			k=0;
			
			for (int i=0 ; i<=th ; i++)
			{
				l=p[ (k+y)%n ];
				for (int j=1 ; j<q1[i] ; j++)
					l+=p[ (k+j+y)%n ];
				q2[i]=l;
				k+=q1[i];
			}
			
			sort( q2 , q2+th+1 , greater<int>() );
			
			sm=0;
			for (int i=0 ; i<=th ; i++)
				sm+=q2[i]*i;
			
			min_cost = min(min_cost,sm);
			
			if( min_cost==sm )
			{
				rep(i,th+1)
				res[i]=q1[i];
				
				szr=th+1;
			}
		}
	}
}

int main()
{
	cin>>n;
	
	rep(i,n)
	cin>>p[i];
	
	if( 1<=n ) f(0,1,1);
	if( 2<=n ) f(0,2,2);
	if( 3<=n ) f(0,3,3);
	
	cout<<min_cost;
	
/*	cout<<endl;
	
	rep(i,szr)
	cout<<res[i]<<' '; */
	/*
	cout<<clock()-st;
	getchar();
	*/
	return 0;
}
