# include <iostream>

using namespace std;

const int maxn=101;
long long f[maxn][maxn];
long long a[maxn][maxn];

int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	cin>>a[i][j];
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	a[i][j]+=a[i][j-1];
	
	long long maxx=-1<<30;
	
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	{
		long long sum=0;
		
		for(int k=1;k<=n;k++)
		{
			sum+=a[k][j]-a[k][i-1];
			maxx=max(maxx,sum);
			
			if(sum<0)sum=0;
		}
	}
	
	cout<<maxx<<endl;
	
	return 0;
}
