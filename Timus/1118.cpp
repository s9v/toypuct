# include <stdio.h>
# include <limits.h>
# include <math.h>

int		x,y,mni;
double	mn=LLONG_MAX;
double	trv;
int		p[200],ps;

double triviality(int p)
{
	int sum=1;
	int tll=int(sqrt(1.0*p));
	
	for (int i=2 ; i<=tll ; i++)
	if ( p%i==0 )
	{
		sum+=p;
		if( p/i>tll ) sum+=p/i;
	}
	return sum*1.0/p;
}

bool isprime(int p)
{
	int tll=(int)sqrt(double(p));
	
	for (int i=2 ; i<=tll ; i++)
	if ( p%i==0 )
	return 0;
	
	return 1;
}

int main()
{
	for (int i=2 ; i<=1000 ; i++)
	if ( isprime() )
	{
		p[ps++]=i;
	}
	
	
	scanf("%d %d",&x,&y);
	
	for (int i=x ; i<=y ; i++)
	{
		trv=triviality(i);
		if( mn>trv )
		mn=trv , mni=i;
	}
	
	printf("%d",mni);
	
	return 0;
}
