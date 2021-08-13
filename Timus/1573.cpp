# include <iostream>

using namespace std;

int  B,R,Y;
int  b,r,y;
int  bb=1,rr=1,yy=1;
int  k;
char s[10];

int main()
{
	cin>>B>>R>>Y;
	
	cin>>k;
	
	for (int i=0 ; i<k ; i++)
	{
		cin>>s;
		
		switch(s[0])
		{
			case 'B':
				b++ , bb=bb*B/b , B-- ;
				break;
			
			case 'R':
				r++ , rr=rr*R/r , R-- ;
				break;
				
			case 'Y':
				y++ , yy=yy*Y/y , Y-- ;
				break;
		}
	}
	
	cout<<bb*rr*yy;
	
	return 0;
}
