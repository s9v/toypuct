# include <iostream>

using namespace std;

const int INF  = (int)1e9;
const int MAXN = 60000;

int n;
int best[MAXN+1];

int main() {
	cin >> n;
	
	fill(best, best+MAXN+1, INF);
	
	best[0] = 0;
	
	for (int k = 1; k <= 300; k++) {
		for (int i = 0; i+k*k <= MAXN; i++) {
			best[i+k*k] = min(best[i+k*k], best[i]+1);
		}
	}
	
	cout << best[n];
	
	return 0;
}
