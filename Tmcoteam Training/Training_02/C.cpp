#include <iostream>
using namespace std;

int T;
int A;
int B;
int X;
int Y;

bool ok () {
	return (A > X && B > Y) || (A > Y && B > X);
}

int main() {
	cin >> T;
	
	while (T--) {
		cin >> A >> B >> X >> Y;
		cout << (ok() ?"Escape is possible." :"Box cannot be dropped.") << "\n";
	}
	
	return 0;
}
