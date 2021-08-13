// Solution using : RMQ and Binary Search

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<string, int> psi;

int n, q;
int ord[1000];
psi rcp[1000];
int rmq[1000][10];

void rmq_init() {
	for (int i = 0; i < n; i++)
		rmq[i][0] = i;
	
	for (int j = 1; (1<<j) <= n; j++)
		for (int i = 0; i+(1<<j)-1 < n; i++)
		if (rcp[ rmq[i][j-1] ].second > rcp[ rmq[i+(1<<(j-1))][j-1] ].second)
			rmq[i][j] = rmq[i][j-1];
		else
			rmq[i][j] = rmq[i+(1<<(j-1))][j-1];
}

void rmq_printmax(int l, int r) {
	int j;
	for (j = 0; (1<<j) <= (r-l+1); j++); // ;
	j--;
	
	if (rcp[ rmq[l][j] ].second > rcp[ rmq[r-(1<<j)+1][j] ].second)
		cout << rcp[ rmq[l][j] ].first;
	else
		cout << rcp[ rmq[r-(1<<j)+1][j] ].first << "-+-";
	cout << "\n";
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> rcp[i].first >> rcp[i].first;
	
	sort(rcp, rcp+n);
	
	rmq_init();
	
	cin >> q;
	psi tmp;
	
	for (int qry = 0; qry < q; qry++) {
		cin >> tmp.first;
		tmp.second = -1000000000;
		int l = lower_bound(rcp, rcp+n, tmp) - rcp;
		tmp.second = +1000000000;
		int r = upper_bound(rcp, rcp+n, tmp) - rcp;
		printf("%d -- %d\n", l, r);
		rmq_printmax(l,r);
	}
	
	return 0;
}
