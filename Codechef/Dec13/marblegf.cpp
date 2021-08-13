#include <iostream>
using namespace std;
typedef long long llint;

int n, q;
llint bit[1000000];

llint fnd(int nd) {
	llint ret = 0;
	for (; nd >= 0; nd = (nd&(nd+1))-1)
		ret += bit[nd];
	return ret;
}

void upd(int nd, llint val) {
	for (; nd < n; nd = (nd|(nd+1)))
		bit[nd] += val;
}

int main() {
	cin >> n;
	cin >> q;
	
	for (int i = 0; i < n; i++) {
		llint val;
		cin >> val;
		upd(i, val);
	}
	
	for (int i = 0; i < q; i++) {
		char cmd;
		cin >> cmd;
		
		if (cmd == 'S') {
			int l, r;
			cin >> l >> r;
			cout << fnd(r) - fnd(l-1) << "\n";
		}
		else if (cmd == 'G') {
			int x;
			llint val;
			cin >> x >> val;
			upd(x, val);
		}
		else if (cmd == 'T') {
			int x;
			llint val;
			cin >> x >> val;
			upd(x, -val);
		}
	}
	
	return 0;
}
