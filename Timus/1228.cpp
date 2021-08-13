# include <iostream>

using namespace std;

int n,s,extra1=0,extra2=1;
int d[20];
int k[20];

int main()
{
	cin>>n>>s;
	
	for (int i=0 ; i<n ; i++)
	cin>>d[i];
	
	for (int i=n-1 ; i>0 ; i--)
	{
		k[i]=(d[i-1]-extra1-1)/d[i];
		extra1+=k[i]*d[i];
		extra2*=k[i]+1;
	}
	
	k[0]=s/extra2-1;
	
	for (int i=0 ; i<n ; i++)
	cout<<k[i]<<' ';
	
	return 0;
}
