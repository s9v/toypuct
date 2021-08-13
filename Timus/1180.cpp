# include <iostream>
# include <cstring>

using namespace std;

int  ln,sum;
char s[300];

int main()
{
	cin>>s;
	
	ln=strlen(s);
	
	for (int i=0 ; i<ln ; i++)
	{
		sum+=s[i]-48;
	}
	
	switch(sum%3)
	{
		case 0: cout<<"2"; break;
		case 1: cout<<"1\n1"; break;
		case 2: cout<<"1\n2"; break;
	}
	
	return 0;
}
