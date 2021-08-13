# include <iostream>
# include <cstring>
# include <string>

using namespace std;

string s;
int a,b,ln,t;

int main()
{
	cin>>s;
	
	ln=s.length();
	
	a=0;
	b=ln-1;
	
	while( a<b )
	{
		if( s[a]>=s[b] )
		{
			s[b]=s[a];
		}
		else
		{
			t=b-1;
			while( s[t]=='9' )
			t--;
			
			if( a<t )
			{
				s[t]++;
				s[b]=s[a];
				
				for (int i=t+1 ; i<b ; i++)
				s[i]='0';
			}
			else
			{
				s[a]++;
				s[b]=s[a];
				
				for (int i=a+1 ; i<b ; i++)
				s[i]='0';
				
				break;
			}
		}
		a++;
		b--;
	}
	
	cout<<s;
	
	return 0;
}
