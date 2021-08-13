#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
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
int inv[100001];
int gzk[100001];
int lst[100001];
bool vis[100001];

int main() {
	ifstream fin("shufflegold.in");
	ofstream fout("shufflegold.out");
	
	fin >> N >> M >> Q;
	
	for (int i = 1; i <= M; i++) {
		fin >> swp[i];
		inv[ swp[i] ] = i;
	}
	
	for (int i = 1; i <= N-M+1; i++) {
		stack<int> stk;
		int cnt = 0;
		bool cycle = 0;
		
		int cur = i;
		while (cur != 1 && cnt < N-M+1) {
			stk.push(cur);
			cnt++;
			if (vis[cur]) {
				cycle = 1;
				break;
			}
			
			cur = swp[cur];
		}
		
		while ( ! stk2.empty()) {
			cur = stk2.top();
			gzk[cur] = cnt;
			lst[cur] = cnt;
			cnt--;
			stk2.pop();
		}
	}
	
	for (int i = 0; i < Q; i++)
	{
		int x;
		fin >> x;
		fout << lst[x];
	}
	
	
	return 0;
}
