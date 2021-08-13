# include <iostream>
# include <cstring>
# include <climits>

using namespace std;

int  n,m;
char uni[12][31];
char puni[31];
char tmp;
char pmed[31];
int  mx=INT_MIN,mxc=0;
int  corr;

void calc()
{
	for (int i=0 ; i<12 ; i++)
	if ( strcmp(uni[i],puni)==0 )
	{
		switch( i/4 )
		{
			case 0: corr+=bool(pmed[0]=='g'); break;
			case 1: corr+=bool(pmed[0]=='s'); break;
			case 2: corr+=bool(pmed[0]=='b'); break;
		}
		break;
	}
}

int main()
{
	for (int i=0 ; i<12 ; i++)
	cin>>uni[i];
	
	cin>>n;
	
	for (int i=0 ; i<n ; i++)
	{
		cin>>m;
		
		corr=0;
		
		for (int j=0 ; j<m ; j++)
		{
			cin>>puni>>tmp>>pmed;
			calc();
		}
		
		if( mx==corr ) mxc++;
		if( mx<corr  ) mx=corr , mxc=1;
	}
	
	cout<<mxc*5;
	
	return 0;
}
