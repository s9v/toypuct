# include <iostream>

using namespace std;

int n,k,tmp;
int a,b;
int sum;

int main()
{
	cin>>n>>k;
	
	sum=0;
	
	for (int i=0 ; i<n ; i++)
	{
		cin>>a>>b;
		sum+=(a-b);
	}
	
	sum=k-((n+1)*2-sum);
	
	if( sum>0 )
	cout<<sum;
	else
	cout<<"Big Bang!";
	
	return 0;
}
