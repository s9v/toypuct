#include <iostream>
using namespace std;

int n;
int m;
int x[1000000];
int ps[10000001];
int v[10000001];
bool p[10000001];

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		v[x[i]]++;
	}
	
	p[0] = p[1] = 1;
	
	for (int i = 2; i <= 10000000; i++)
	{
		if (p[i])
			continue;
		
		for (int j = i; j <= 10000000; j += i)
		{
			ps[i] += v[j];
			p[j] = 1;
		}
	}
	
	for (int i = 1; i <= 10000000; i++)
		ps[i] += ps[i-1];
	
	cin >> m;
	
	for (int i = 0; i < m; i++)
	{
		int qleft, qright;
		cin >> qleft >> qright;
		
		qleft = min(qleft, 10000000);
		qright = min(qright, 10000000);
		
		cout << ps[qright] - ps[qleft-1] << "\n";
	}
	
	return 0;
}
