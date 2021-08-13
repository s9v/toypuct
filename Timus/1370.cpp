# include <iostream>

using namespace std;

int n,m,fr,to;
int p[2000];

int main()
{
	cin>>n>>m;
	
	for (int i=0 ; i<n ; i++)
	cin>>p[i] , p[i+n]=p[i];
	
	fr=m%n;
	to=m%n+10;
	
	for (int i=fr ; i<to ; i++)
	cout<<p[i];
	
	return 0;
}
