#include<cstdio>
#include<cstring>
#include<climits>
#include<string>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<stdlib.h>
#include<ctime>
using namespace std;
typedef long long ll;

void io_in_data() { freopen("data.in", "r", stdin);freopen("data1.out", "w", stdout); }

const int MAXN = 57;
const int MOD = 1000000000+7;
int d[MAXN][MAXN][2], tmx[MAXN][MAXN][2];
int C[MAXN][MAXN];

int main() {
	//io_in_data();
	for(int i = 0; i < MAXN; i++) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	}
	int n, A, B, K;
	while(~scanf("%d%d", &n, &K)) {
		for(int i = A = B = 0; i < n; i++) {
			int  v;
			scanf("%d", &v);
			v == 50 ? A++ : B++;
		}
		memset(d, -1, sizeof(d));
		memset(tmx, 0, sizeof(tmx));
		d[A][B][0] = 0;
		tmx[A][B][0] = 1;
		queue<int> q;
		q.push(A); q.push(B); q.push(0);
		while(!q.empty()) {
			int a = q.front(); q.pop();
			int b = q.front(); q.pop();
			int p = q.front(); q.pop();
			
			if(a == A && b == B && p == 1) break;
			
			for(int i = 0; i <= a; i++)
				for(int j = 0; j <= b && i*50+j*100 <= K; j++)
					if(i+j > 0) {
						int ta = A-a+i, tb = B-b+j, tp = 1-p;
						int td = d[a][b][p] + 1;
						int ttm = 1LL*tmx[a][b][p] * C[a][i]%MOD * C[b][j]%MOD;
						
						if(d[ta][tb][tp] == -1 || d[ta][tb][tp] > td) {
							d[ta][tb][tp] = td;
							tmx[ta][tb][tp] = ttm;
							q.push(ta); q.push(tb); q.push(tp);
						}
						else if(d[ta][tb][tp] == td)
							tmx[ta][tb][tp] = (tmx[ta][tb][tp] + ttm) % MOD;
					}
		}
		printf("%d\n%d\n", d[A][B][1], tmx[A][B][1]);
	}
	return 0;
}
