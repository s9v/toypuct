#include <iostream>

using namespace std;

const int INF = (int)1e8;

int n, k;
int hrs[510];
int pls[510];
int bst[510][510];

int uhc(int l, int r) { /// [L,R)
	int black = pls[r-1] - (l>0 ?pls[l-1] :0);
	int white = r-l-black;
	return black*white;
}

int main() {
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> hrs[i];
		pls[i] = hrs[i] + (i>0 ?pls[i-1] :0);
	}
	
	fill(&bst[0][0], &bst[510][0], INF);
	bst[0][0] = 0;
	
	for (int i = 1; i <= n; i++) {
		bst[i][1] = uhc(0, i);
		
		for (int j = 2; j <= i; j++) {
			for (int h = j-1; h < i; h++) {
				bst[i][j] = min(bst[i][j], bst[h][j-1] + uhc(h, i));
			}
		}
	}
	
	cout << bst[n][k];
	
	return 0;
}
