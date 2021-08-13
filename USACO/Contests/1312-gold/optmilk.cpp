#include <iostream>
#include <fstream>
#include <vector>
#define  pb(X)		push_back(X)
#define  mp(X,Y)		make_pair(X,Y)
#define  sz(X)			(int)X.size()
#define  DBG(X)			cerr << #X << " : " << X << "\n"
using namespace std;
typedef long long llint;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
const int LRG = (int)1e9;

int N, D;
llint res;
int m[40000];
int dp[40000][2];

int main() {
	ifstream fin("optmilk.in");
	ofstream fout("optmilk.out");
	
	fin >> N >> D;
	
	for (int i = 0; i < N; i++)
		fin >> m[i];
	
	dp[0][0] = 0;
	dp[0][1] = m[0];
	for (int i = 0; i < N; i++) {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = dp[i-1][0] + m[i];
	}
	
	for (int i = 0; i < D; i++) {
		int id, val;
		fin >> id >> val;
		id--;
		
		m[id] = val;
		
		for (int i = id; i < N; i++) {
			dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
			dp[i][1] = dp[i-1][0] + m[i];
		}
		
		res += max(dp[N-1][0], dp[N-1][1]);
	}
	
	fout << res;
	
	return 0;
}
