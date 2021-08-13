# include <iostream>
# include <cmath>

using namespace std;

int gcd(int a,int b){ return ( b==0 ? a : gcd(b,a%b) ); }

int tmpa,tmpb;
int a,b,gcdab;
int x,y,fxy=0;

int main()
{
	cin>>tmpa>>tmpb;
	
	tmpa--; tmpb--;
	
	a=max(tmpa,tmpb);
	b=min(tmpa,tmpb);
	
	gcdab=gcd(a,b);
	
	x=a/gcdab;
	y=b/gcdab;
	
	//cout<<"GCD="<<gcdab<<endl;
	
	for (double i=1 ; i<=y ; i++)
	{
		//cout<<(i-1)*x/y<<' ';
		//cout<<i*x/y<<endl;
		fxy+=int( ceil(i*x/y)-floor((i-1)*x/y) );
		//cout<<int( ceil(i*x/y)-floor((i-1)*x/y) )<<' ';
	}
	//cout<<endl;
	
	cout<<fxy*gcdab;
	
	return 0;
}
