# include <iostream>
# include <algorithm>

using namespace std;

int n,mx,mxpi;
int p[500000];

int main()
{
	cin>>n;
	
	for (int i=0 ; i<n ; i++)
	{
		cin>>p[i];
	}
	
	sort(p,p+n);
	
	int c=1;
	
	for (int i=1 ; i<n ; i++)
	{
		if(p[i]==p[i-1])
		c++;
		
		else
		{
			if(mx<c) mx=c , mxpi=p[i-1];
			c=1;
		}
	}
	
	if(mx<c) mx=c , mxpi=p[n-1];
	
	cout<<mxpi;
	
	return 0;
}
