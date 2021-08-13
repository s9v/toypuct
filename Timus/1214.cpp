# include <iostream>

using namespace std;

int x,y;

int main()
{
	cin>>x>>y;
	
	if( x>0 && y>0 )
	cout<<( (x+y)%2==0 ? x : y )<<' '<<( (x+y)%2==0 ? y : x );
	else
	cout<<x<<' '<<y;
	
	return 0;
}
