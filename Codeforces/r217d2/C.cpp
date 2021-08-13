#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int res;
int c[10000];
int d[10000];
bool v[10000];

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> c[i];
	
	sort(c, c+n);
	
	/*
	for (int i = 0; i < n; i++)
		cout << c[i] << " ";
	cout << "\n";
	*/
	
	int l = 0;
	int r = -123;
	for (int i = 1; i <= n; i++) {
		if (i == n || c[i-1] != c[i]) {
			r = i;
			
			while (l < i) {
//				cout << l << " " << r << " #\n";
				l = l%n;
				r = r%n;
				
				if (v[r]) {
//					cout << r << " visd\n";
					r++;
					continue;
				}
				
				if (c[l] != c[r])
					res++;
				
				v[r] = true;
				d[l] = c[r];
				
				l++;
				r++;
			}
			
//			cout << "=====\nl = " << i << "\n=====\n";
			l = i;
		}
	}
	
	cout << res << "\n";
	
	for (int i = 0; i < n; i++)
		cout << c[i] << " " << d[i] << "\n";
	
	return 0;
}
