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

int N, M, Q;
int swp[100001];
int org[2][100001]; // .org?

int main() {
	ifstream fin("shufflegold.in");
	ofstream fout("shufflegold.out");
	
	fin >> N >> M >> Q;
	
	for (int i = 1; i <= M; i++)
		fin >> swp[i];
	
	for (int i = 1; i <= N; i++)
		org[0][i] = i;
	
	for (int i = 1; i <= N-M+1; i++) {
		int old = (i+1)%2;
		int cur = (i+2)%2;
		
		for (int j = 1; j < i; j++)
			org[cur][j] = org[old][j];
		
		for (int j = i; j < i+M; j++)
			org[cur][ i + swp[j-i+1] - 1 ] = org[old][j];
		
		for (int j = i+M; j <= N; j++)
			org[cur][j] = org[old][j];
	}
	
	int lst = (N-M+1)%2;
	for (int i = 0; i < Q; i++) {
		int x;
		fin >> x;
		fout << org[lst][N-x+1] << "\n";
	}
	
	return 0;
}
