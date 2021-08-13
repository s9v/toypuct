# include <iostream>
# include <cstring>
# include <climits>

using namespace std;

int  mx=INT_MIN,ln,r,k;
char s[1000010];

int get(char c)
{
	if( isalpha(c) ) return c-55;
	return c-48;
}

int main()
{
	cin>>s;
	
	ln=strlen(s);
	for (int i=0 ; i<ln ; i++)
	mx=max( get(s[i]) , mx );
	
	for (k=2 ; k<=36 ; k++)
	{
		r=0;
		
		for (int i=0 ; i<ln ; i++)
		r=( r*k+get(s[i]) )%(k-1);
		
		if( r==0 && mx<k ) break;
	}
	
	( k==37 ? cout<<"No solution." : cout<<k );
	
	return 0;
}
