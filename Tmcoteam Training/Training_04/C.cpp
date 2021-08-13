#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long llint;

int n;
double m;
double exc[6][6];
int plc[50];

int main()
{
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			cin >> exc[i][j];

	while (true) {
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			cin >> plc[i];

		cin >> m;

		int lst = 1;
		int cur;
		for (int i = 0; i < n+1; i++)
		{
			if (i < n)
				cur = plc[i];
			else
				cur = 1;

			m *= exc[lst][cur];
			m = floor(m*100+0.5)/100.0;

			lst = cur;
		}

		printf("%.2lf\n", m);
	}

	return 0;
}
