#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
typedef pair<int, pair<int,int> > abc;

int n, w, h;
int mxi;
abc a[5000];
int dp[5000];
int pr[5000];

int main() {
	cin >> n;
	cin >> w;
	cin >> h;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		cin >> a[i].second.first;
		a[i].second.second = i;
	}
	
	sort(a, a+n);
	
	for (int i = 0; i < n; i++) {
		dp[i] = (a[i].first > w && a[i].second.first > h);
		pr[i] = -1;
	}
	
	for (int i = 0; i < n; i++) {
		if (!(a[i].first > w && a[i].second.first > h)) continue;
		
		for (int j = 0; j < n; j++) {
			if (a[i].first > a[j].first && a[i].second.first > a[j].second.first && dp[i] < dp[j]+1) {
				dp[i] = dp[j]+1;
				pr[i] = j;
			}
		}
		
		if (dp[mxi] < dp[i]) {
			mxi = i;
		}
	}
	
	cout << dp[mxi] << "\n";
	
	stack<int> st;
	
	int cur = mxi;
	for (int i = 0; i < dp[mxi]; i++) {
		st.push(a[cur].second.second+1);
		cur = pr[cur];
	}
	
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	
	return 0;
}
