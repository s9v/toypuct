#include <iostream>
using namespace std;

int n, m;
int a[1<<17];
int t[1<<18];

void init(int nd, int d) {
	if (nd < ((1<<n)-1)) {
		init(2*nd+1, d+1);
		init(2*nd+2, d+1);
		
		if ((n-d)%2 == 1)
			t[nd] = (t[2*nd+1] | t[2*nd+2]);
		else
			t[nd] = (t[2*nd+1] ^ t[2*nd+2]);
	}
	else {
		t[nd] = a[nd - ((1<<n)-1)];
	}
}

void recalc(int nd) {
	int d = n-1;
	
	while (true) {
		if ((n-d)%2 == 1)
			t[nd] = (t[2*nd+1] | t[2*nd+2]);
		else
			t[nd] = (t[2*nd+1] ^ t[2*nd+2]);
		
		if (nd == 0)
			break;
		
		nd = (nd-1)/2;
		d--;
	}
}

int get(int p, int b) {
	int id = ((1<<n)-1) + p;
	
	t[id] = b;
	recalc((id-1)/2);
	
	return t[0];
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < (1<<n); i++)
		cin >> a[i];
	
	init(0, 0);
	
	for (int i = 0; i < m; i++) {
		int p, b;
		cin >> p >> b;
		
		cout << get(p-1, b) << "\n";
	}
	
	
	return 0;
}
