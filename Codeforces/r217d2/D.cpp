#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define  sz(X) (int)X.size()
#define  DBG(X) cerr << #X << " --> " << X << "\n";
using namespace std;
typedef vector<int> vi;

int n, m;
char mp[2001][2001];
int mni = 5000;
int mxi;
int mnj = 5000;
int mxj;
int cntw;
int inner_cntw;
int a, b, c, d;

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			
			if (mp[i][j] == 'w') {
				mni = min(mni, i);
				mxi = max(mxi, i);
				mnj = min(mnj, j);
				mxj = max(mxj, j);
				cntw++;
			}
		}
	
	DBG(mni);
	DBG(mxi);
	DBG(mnj);
	DBG(mxj);
	
	if (cntw == 1) {
		for (int i = 0; i < n; i++)
			cout << mp[i] << "\n";
		return 0;
	}
	
	for (int i = mnj+1; i < mxj; i++)
		if (mp[mni][i] == 'w')
			a++;
	
	for (int i = mnj+1; i < mxj; i++)
		if (mp[mxi][i] == 'w')
			b++;
	
	for (int i = mni+1; i < mxi; i++)
		if (mp[i][mnj] == 'w')
			c++;
	
	for (int i = mni+1; i < mxi; i++)
		if (mp[i][mxj] == 'w')
			d++;
	
	for (int i = mni+1; i < mxi; i++)
		for (int j = mnj+1; j < mxj; j++)
			if (mp[i][j] == 'w')
				inner_cntw++;
	
	if (inner_cntw > 0) {
		cout << -1;
		return 0;
	}
	
	int w = mxj-mnj;
	int h = mxi-mni;
	int diff = abs(w-h);
	DBG(w);
	DBG(h);
	DBG(diff);
	
	if (w < h) {
		if (c == 0) {
			int chng = min(mnj, diff);
			mnj -= chng;
			diff -= chng;
		}
		
		if (d == 0) {
			int chng = min(m-1-mxj, diff);
			mxj += chng;
			diff -= chng;
		}
	}
	else if (w > h) {
		if (a == 0) {
			int chng = min(mni, diff);
			mni -= chng;
			diff -= chng;
		}
		
		if (b == 0) {
			int chng = min(n-1-mxi, diff);
			mxi += chng;
			diff -= chng;
		}
	}
	
	DBG(mni);
	DBG(mxi);
	DBG(mnj);
	DBG(mxj);
	DBG(a);
	DBG(b);
	DBG(c);
	DBG(d);
	DBG(diff);
	
	if (diff > 0) {
		cout << -1;
		return 0;
	}
	
	for (int i = mnj; i <= mxj; i++)
		if (mp[mni][i] != 'w')
			mp[mni][i] = '+';
	
	for (int i = mnj; i <= mxj; i++)
		if (mp[mxi][i] != 'w')
			mp[mxi][i] = '+';
	
	for (int i = mni; i <= mxi; i++)
		if (mp[i][mnj] != 'w')
			mp[i][mnj] = '+';
	
	for (int i = mni; i <= mxi; i++)
		if (mp[i][mxj] != 'w')
			mp[i][mxj] = '+';
	
	for (int i = 0; i < n; i++)
		cout << mp[i] << "\n";
	
	return 0;
}
