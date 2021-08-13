# include <iostream>
# include <algorithm>
# include <string>

using namespace std;

int  n,k;
int  ans[16];
int  per[16];
bool IMP=false;
string set[16][3];

int main()
{
	cin>>n;
	
	for (int i=0 ; i<n ; i++)
	{
		cin>>set[i][0]>>set[i][1]>>set[i][2];
		sort(set[i],set[i]+3);
	}
	
	for (int i=0 ; i<n ; i++)
	cin>>per[i] , per[i]--;
	
	ans[0]=0;
	
	for (int i=1 ; i<n ; i++)
	{
		for (k=0 ; k<3 ; k++)
		if( set[ per[i] ][ k ] > set[ per[i-1] ][ ans[i-1] ] )
		break;
		
		if( k==3 ) { IMP=true; break; }
		else ans[i]=k;
	}
	
	if( IMP ) cout<<"IMPOSSIBLE";
	else
	for (int i=0 ; i<n ; i++)
	cout<<set[ per[i] ][ ans[i] ]<<endl;
	
	return 0;
}
