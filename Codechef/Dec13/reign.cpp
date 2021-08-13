#include <iostream>
#include <climits>
using namespace std;
typedef long long llint;

int t;
int n;
int k;
int a[100000];
llint f[100000];
llint l[100000];

int main() {
	cin >> t;
	
	while (t--) {
		cin >> n >> k;
		
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		llint sum = a[0];
		f[0] = a[0];
		for (int i = 1; i < n; i++) {
			sum = max(0LL, sum);
			sum += a[i];
			
			f[i] = max(f[i-1], sum);
		}
		
		sum = a[n-1];
		l[n-1] = a[n-1];
		for (int i = n-2; i >= 0; i--) {
			sum = max(0LL, sum);
			sum += a[i];
			
			l[i] = max(l[i+1], sum);
		}
		
		llint res = LLONG_MIN;
		for (int i = 1; i+k < n; i++)
			res = max(res, f[i-1]+l[i+k]);
		
		cout << res << "\n";
	}
	
	
	return 0;
}
