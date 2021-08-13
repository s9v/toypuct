#include <iostream>
#include <ctime>
using namespace std;

const int LRG = 1e9;

int n, m;
int q;
int arr[500][500];

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	
	cin >> q;
	
	char cmd;
	for (int i = 0; i < q; i++)
	{
		cin >> cmd;
		
		if (cmd == 'q')
		{
			int qa, qb, qc, qd;
			cin >> qa >> qb >> qc >> qd;
			qa--;
			qb--;
			qc--;
			qd--;
			
			int mn = LRG, mx = -LRG;
			
			for (int i1 = qa; i1 <= qc; i1++)
			for (int i2 = qb; i2 <= qd; i2++)
			{
				mn = min(mn, arr[i1][i2]);
				mx = max(mx, arr[i1][i2]);
			}
			
			cout << mx << " " << mn << "\n";
		}
		else
		{
			int x, y, v;
			cin >> x >> y >> v;
			x--;
			y--;
			arr[x][y] = v;
		}
	}
	
	
	return 0;
}
