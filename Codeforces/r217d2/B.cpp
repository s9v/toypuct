#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define  sz(X) (int)X.size()
using namespace std;
typedef vector<int> vi;

int n;
vi m[100];

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		m[i].resize(x);
		
		for (int j = 0; j < x; j++)
			cin >> m[i][j];
		
		sort(m[i].begin(), m[i].end());
	}
	
	for (int i = 0; i < n; i++)
	{
		bool ok = true;
		
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			
			if (sz(m[i]) < sz(m[j]))
				continue;
			
			int l = 0;
			int r = 0;
			
			while (l < sz(m[i]) && r < sz(m[j])) {
				if (m[i][l] == m[j][r]) {
					l++;
					r++;
				}
				else {
					l++;
				}
			}
			
			if (r == sz(m[j])) {
				ok = false;
				break;
			}
		}
		
		cout << (ok ?"YES" :"NO") << "\n";
	}
	
	return 0;
}
