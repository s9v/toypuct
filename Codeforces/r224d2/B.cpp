#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double a, b;
double w, x;
double c;

bool vis[1001];

int main()
{
	cin >> a >> b;
	cin >> w >> x;
	cin >> c;
	
	if (c <= a)
		cout << "0";
	else
		printf("%.0lf", c-a+ceil( (x*(c-a)-b) / (w-x) ));
	
	return 0;
}
