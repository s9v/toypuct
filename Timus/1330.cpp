# include <iostream>

using namespace std;

int n,q,a,b;
int k[10000];
int p[10000];
int out[100000];

int main()
{
	cin>>n;
	
	for (int i=0 ; i<n ; i++)
	cin>>k[i];
	
	p[0]=k[0];
	for (int i=1 ; i<n ; i++)
	p[i]=p[i-1]+k[i];
	
	cin>>q;
	
	for (int i=0 ; i<q ; i++)
	{
		cin>>a>>b;
		
		a--;
		b--;
		
		if( a==0 ) out[i]=p[b];
		else out[i]=p[b]-p[a-1];
	}
	
	for (int i=0 ; i<q ; i++)
	cout<<out[i]<<endl;
	
	return 0;
}
