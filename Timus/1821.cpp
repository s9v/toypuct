# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
# include <string>
# include <vector>
# include <climits>
# include <cassert>

using namespace std;

struct mstruct
{
	char name[21];
	double t;
	double r;
};

struct nstruct
{
	char name[21];
};

int n,m;
mstruct p[100];
nstruct o[100];
double a,b;

bool mcomp(mstruct a,mstruct b)
{ return a.t<b.t; }

bool ncomp(nstruct a,nstruct b)
{
	if(strcmp(a.name,b.name)>0)
	return 0;
	return 1;
}

int main()
{
	scanf("%d",&n);
	
	for (int i=0 ; i<n ; i++)
	{
		scanf("\n%s %lf:%lf",p[i].name,&a,&b);
		p[i].r=a*60+b;
		p[i].t=a*60+b+i*30;
	}
	
	sort(p,p+n,mcomp);
	
	double mn=0;
	
	for (int i=0 ; i<n ; i++)
	if( mn>p[i].r )
	{
		mn=p[i].r;
		strcpy(o[m].name,p[i].name);
		m++;
	}
	
	sort(o,o+m,ncomp);
	
	cout<<m<<endl;
	
	for (int i=0 ; i<m ; i++)
	cout<<o[i].name<<endl;
	
	return 0;
}
