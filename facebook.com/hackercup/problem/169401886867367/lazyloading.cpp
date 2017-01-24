#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	
	scanf("%d", &T);
	
	for (int _case = 1; _case <= T; _case++) {
		int n;
		int w[110];
		
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++)
			scanf("%d", &w[i]);
		
		sort(w, w+n);
		
		int l = 0;
		int r = n-1;
		int ans = 0;
		int x;
		
		while (( x = (50+w[r]-1)/w[r] ) <= r-l+1) {
			l += x-1;
			r--;
			ans++;
		}
		
		printf("Case #%d: %d\n", _case, ans);
	}
	
	return 0;
}
