#include <iostream>
#define  DBG(X)  cerr << #X << " : " << X << "\n"
using namespace std;

int n, m;
int a, b;
int p[100000];
int x[100000];

int main()
{
	cin >> a >> b;
	m = b-a+1;
	
	for (int i = 0; i < m; i++)
		cin >> x[i];
	
	p[n++] = x[0];
	for (int i = 1; i < m; i++)
		if (x[i-1] != x[i])
			p[n++] = x[i];
	
	int res = 0;
	
	{
		int i = 0;
		while (i < n)
		{
			int j = i+2;
			
			while (j < n && ((p[i] < p[i+1]) == (p[j-1] < p[j])))
				j++;
			
			res++;
			i = j;
		}
	}
	
	cout << res;
	
	return 0;
}
