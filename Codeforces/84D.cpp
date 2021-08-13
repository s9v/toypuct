#include <iostream>
#include <cstdio>
using namespace std;
typedef long long llint;

int n;
llint k;
int a[100000];

int main() {
	cin >> n;
	cin >> k;
	
	llint tmpsum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tmpsum += a[i];
	}
	
	if (tmpsum < k) {
		cout << -1;
		return 0;
	}
	
	int l = 0, r = 1000000000;
	int times = 0;
	while (l <= r) {
		int mid = (l+r)/2;
		llint cnt = 0LL;
		
		for (int i = 0; i < n; i++) {
			cnt += min(mid, a[i]);
		}
		
		if (cnt <= k) {
			times = max(times, mid);
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	
	llint cnt = 0LL;
	for (int i = 0; i < n; i++) {
		cnt += min(times, a[i]);
		a[i] = max(0, a[i]-times);
	}
	
	int id;
	for (id = 0; id < n && cnt < k; id++) {
		if (a[id] > 0) {
			cnt++;
			a[id]--;
		}
	}
	
	for (int i = id; i < n; i++)
		if (a[i] > 0)
			cout << i+1 << " ";
	
	for (int i = 0; i < id; i++)
		if (a[i] > 0)
			cout << i+1 << " ";
	
	return 0;
}
