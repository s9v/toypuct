#include <iostream>
using namespace std;

int N;
int n;

int main() {
	cin >> N;
	
	for (int t = 1; t <= N; t++) {
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += (i*(i+1)*(i+2))/2;
		
		cout << t << " " << n << " " << sum << "\n";
	}
	
	
	return 0;
}
