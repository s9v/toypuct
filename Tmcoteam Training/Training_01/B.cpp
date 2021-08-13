#include <iostream>
using namespace std;

int n, t, c;

int main() {
	cin >> n;
	
	while (n--) {
		cin >> c;
		t++;
		cout << t << " ";
		cout << c/25 << " QUARTER(S), ";
		c = c%25;
		cout << c/10 << " DIME(S), ";
		c = c%10;
		cout << c/5 << " NICKEL(S), ";
		c = c%5;
		cout << c << " PENNY(S)\n";
	}
	
	return 0;
}
