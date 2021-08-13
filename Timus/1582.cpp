# include <iostream>
# include <cmath>
# include <cstdio>
# include <algorithm>

using namespace std;

double a,b,c;
double x;

int round_it(double x)
{
	int intx=int(x);
	
	if( x>=intx+0.5 )
	return intx+1;
	return intx;
}

int main()
{
	cin>>a>>b>>c;
	
	x=1000.0 / ( 1 + a/b + a/c );
	cout<<round_it(a*x);
	
	return 0;
}
