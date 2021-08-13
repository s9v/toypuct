/*
 * Timus - 1701. Ostap and Partners
 * Disjoint-set-like solution
 * */

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int n, m;
int fath[50000]; // parent
int diff[50000]; // wage difference with root
int size[50000]; // tree size
int minw[50000]; // minimum wage
int ord[50000];

int find_update(int nd) { // find root, also update diff
	if (fath[nd] == nd)
		return nd;
	
	int oldfath = fath[nd];
	int newfath = find_update(fath[nd]);
	
	diff[nd] += diff[oldfath];
	fath[nd] = newfath;
	
	return newfath;
}

bool union_set(int a, int b, int d) { // union two sets
	if (size[a] < size[b]) {
		swap(a, b);
		d *= -1;
	}
	
	size[a] += size[b];
	fath[b] = a;
	diff[b] = d;
	
	minw[a] = min(minw[a], minw[b]+d);
	
	int fath0 = find_update(0);
	
	if (a == fath0 && minw[a] < diff[0])
		return false;
	
	return true;
}

bool ordcmp(int i, int j) {
	return fath[i] < fath[j];
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		fath[i] = i;
		diff[i] = 0;
		size[i] = 1;
		minw[i] = 0;
	}
	
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		
		int root_a = find_update(a);
		int root_b = find_update(b);
		
		if (root_a != root_b) {
			if ( ! union_set(root_a, root_b, -(d-diff[a]+diff[b]))) {
				cout << "Impossible after " << i+1 << " statements";
				return 0;
			}
		}
		else if (d != diff[a] - diff[b]) {
			cout << "Impossible after " << i+1 << " statements";
			return 0;
		}
	}
	
	for (int i = 0; i < n; i++)
		find_update(i);
	
	for (int i = 0; i < n; i++)
		assert(fath[fath[i]] == fath[i]);
	
	for (int i = 0; i < n; i++)
		ord[i] = i;
	
	sort(ord, ord+n, ordcmp);
	
	int mnw = diff[0]; // minimum wage 
	int lst = 0;
	for (int i = 1; i <= n; i++)
		if (i == n || fath[ord[i-1]] != fath[ord[i]]) {
			for (int j = lst; j < i; j++)
				diff[ord[j]] += -mnw;
			
			if (i < n) {
				mnw = diff[i];
				lst = i;
			}
		}
		else {
			mnw = min(mnw, diff[i]);
		}
	
	cout << "Possible\n";
	for (int i = 0; i < n; i++) {
		cout << diff[i] << "\n";
		assert(diff[i]<=1000000000);
	}
	
	return 0;
}
