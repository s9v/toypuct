# include <iostream>
# include <cstdio>
# include <string>

using namespace std;

int  n;
string tmp1;
string tmp2;
string s[1000]; int ns;
string h[1000]; int nh;
string g[1000]; int ng;
string r[1000]; int nr;

int main()
{
	cin>>n;
	getline(cin,tmp1);
	cout<<tmp1;
	
	for (int i=0 ; i<n ; i++)
	{
		getline(cin,tmp1);
		getline(cin,tmp2);
		
		switch(tmp2[0])
		{
			case 'S': s[ns++]=tmp1; break;
			case 'H': h[nh++]=tmp1; break;
			case 'G': g[ng++]=tmp1; break;
			case 'R': r[nr++]=tmp1; break;
		}
	}
	
	cout<<"Slytherin:\n";
	for (int i=0 ; i<ns ; i++)
	cout<<s[i]<<endl;
	
	cout<<"\nHufflepuff:\n";
	for (int i=0 ; i<nh ; i++)
	cout<<h[i]<<endl;
	
	cout<<"\nGryffindor:\n";
	for (int i=0 ; i<ng ; i++)
	cout<<g[i]<<endl;
	
	cout<<"\nRavenclaw:\n";
	for (int i=0 ; i<nr ; i++)
	cout<<r[i]<<endl;
	
	return 0;
}
