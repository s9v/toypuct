#include <iostream>
using namespace std;
typedef long long llint;

int n, q;
int ps[20][301][301];

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			
			for (int k = 1; k <= 10; k++)
				ps[k][i][j] = ps[k][i-1][j] + ps[k][i][j-1] - ps[k][i-1][j-1] + (k == x);
		}
	
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		int x1, x2;
		int y1, y2;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		
		int cnt = 0;
		for (int k = 1; k <= 10; k++)
			cnt += (ps[k][x2][y2] - ps[k][x1-1][y2] - ps[k][x2][y1-1] + ps[k][x1-1][y1-1] > 0);
		
		cout << cnt << "\n";
	}
	
	return 0;
}
