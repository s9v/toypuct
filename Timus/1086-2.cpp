# include <iostream>

using namespace std;

int prost[16000];

int i,j,k,x,n;
bool flag;

void look(int x)
{
	int i;
	
	i=prost[k];
	
	while( k!=x )
	{
		i=i+2;
		flag=true;
		
		for ( int j=1 ; j<=k ; j++ )
		{
			if( i%prost[j]==0 )
			{
				flag=false;
				break;
			}
			
			if( prost[j]*prost[j]>i )
			break; // This is very important
		}
		
		if( flag )
		{
			k=k+1;
			prost[k]=i;
		}
	}
	
	cout<<prost[k]<<endl;
}

int main()
{
	prost[1]=2;
	prost[2]=3;
	prost[3]=5;
	
	k=3;
	
	cin>>n;
	
	for ( int i=1 ; i<=n ; i++ )
	{
		cin>>x;
		
		if(x>k)
		look(x);
		
		else
		cout<<prost[x]<<endl;
	}
}
