# include <iostream>
# include <string>

using namespace std;

int n,tmp;
int mxhungry=2;
int mnsatisf=10;
string s;

int main()
{
	cin>>n;
	
	for (int i=0 ; i<n ; i++)
	{
		cin>>tmp>>s;
		
		if( s=="hungry" )
		{
			if( mxhungry<tmp )
			mxhungry=tmp;
		}
		
		else
		{
			if( mnsatisf>tmp )
			mnsatisf=tmp;
		}
	}
	
	if( mxhungry<mnsatisf )
	cout<<mnsatisf;
	
	else
	cout<<"Inconsistent";
	
	return 0;
}
