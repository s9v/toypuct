# include <iostream>

using namespace std;

int n;

int main()
{
	cin>>n;
	
	cout<<( (n*(n+1)/2)%2==1 ?"grimy" :"black" );
	
	return 0;
}
