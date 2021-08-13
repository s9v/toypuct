# include <iostream>

using namespace std;

int dp[16][10];
int digit,base,res=0;

int main()
{
	cin>>digit>>base;
	
	if(k==1)
	{cout<<0;return 0;}
	if(n==1)
	{cout<<k-1;return 0;}
	
	for (int i=1 ; i<base ; i++)
	dp[0][i]=1;
	
	dp[0][0]=0;
	
	for (int i=1 ; i<digit ; i++)
	{
		int sum=0;
		
		for (int j=0 ; j<base ; j++)
		sum+=dp[i-1][j];
		
		for (int j=0 ; j<base ; j++)
		dp[i][j]=sum;
		
		dp[i][0]-=dp[i-1][0];
	}
	
	for (int i=0; i<digit; i++)
	{
		for (int j=0; j<base; j++)
		cout << "dp["<<i<<"]["<<j<<"] = " << dp[i][j] << endl;
		
		cout << endl;
	}
	
	for (int i=0 ; i<base ; i++)
	res+=dp[digit-1][i];
	
	cout << "\nRES : ";
	cout<<res;
	
	return 0;
}
