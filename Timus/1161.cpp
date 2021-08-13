# include <iostream>
# include <iomanip>
# include <algorithm>
# include <functional>
# include <cmath>

using namespace std;

int   n;
int   a[100];
float t;

int main()
{
	cin>>n;
	
	for (int i=0 ; i<n ; i++)
	cin>>a[i];
	
	sort(a,a+n,greater<int>()); t=(float)a[0];
	
	for (int i=1 ; i<n ; i++)
	t=2*sqrt((float)a[i]*t);
	
	cout.precision(2);
	cout<<fixed<<t;
	
	return 0;
}
