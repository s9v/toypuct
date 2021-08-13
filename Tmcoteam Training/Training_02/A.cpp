#include <iostream>
#include <algorithm>
using namespace std;

int C, N;

int v[2000][2000];
int p[2001][2001];

int main() {
	for (int i = 0; i < 2000; i++)
		for (int j = 0; j < 2000; j++) {
			if (i == 0 && j == 0)
				continue;
			
			v[i][j] = (__gcd(i,j) == 1);
		}
	
	v[0][1] = 1;
	v[1][0] = 1;
	
	for (int i = 1; i <= 2000; i++)
		for (int j = 1; j <= 2000; j++)
			p[i][j] = v[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
	
	cin >> C;
	
	for (int T = 1; T <= C; T++) {
		cin >> N;
		cout << T << " " << N << " " << p[N+1][N+1] << "\n";
	}
	
	return 0;
}
