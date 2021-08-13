# include <iostream>
# include <cmath>

using namespace std;

int n,a,p;
/*
int bs()
{
	int l=1 , r=n , m ;
	
	while( l<=r )
	{
		m= (l+r)/2 ;
		
		if( p*p+2*m*p-p==2*n )
		return m;
		
		else
		if( p*p+2*m*p-p<2*n )
		l=m+1;
		
		else
		if( p*p+2*m*p-p>2*n )
		r=m-1;
	}
	
	return -1;
}
*/
int main()
{
	cin>>n; p=int(sqrt(n*4.0));
	
	for ( ; p>=1 ; p--)
	if( a=(2*n+p-p*p)/(2*p) , 2*a*p+p*p-p==2*n && a>0 )
	{
		cout<<a<<' '<<p;
		break;
	}
	
	return 0;
}
