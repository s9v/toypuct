# include <iostream>

using namespace std;

int  n,tmp,nmem;
int  adlst[100][100];
int  nadlst[100];
bool team[100];
bool vis[100];
bool nosolution=false;

void goandsurf(int ii,int teamx)
{
	team[ii]=teamx;
	vis[ii]=true;
	
	for (int i=0 ; i<nadlst[ii] ; i++)
	if ( !vis[ adlst[ii][i] ] )
	goandsurf(adlst[ii][i] , (teamx+1)%2);
}

int main()
{
	cin>>n;
	
	for (int i=0 ; i<n ; i++)
	{
		while ( cin>>tmp , tmp )
		adlst[i][ nadlst[i]++ ]=tmp-1;
		
		if( !nadlst[i] ) nosolution=true;
	}
	
	if( nosolution ) cout<<0;
	else
	{
		for (int i=0 ; i<n ; i++)
		if ( !vis[i] ) goandsurf(i,0);
		
		for (int i=0 ; i<n ; i++)
		nmem+=team[i];
		
		cout<<nmem<<endl;
		
		for (int i=0 ; i<n ; i++)
		if ( team[i] )
		cout<<i+1<<" ";
	}
	
	return 0;
}
