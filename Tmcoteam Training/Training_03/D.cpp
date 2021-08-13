#include <iostream>
#include <cmath>
using namespace std;

int a, b;

int x() {
	return a = b++;
}

int main()
{
	b = 5;
	
	cout << x();
	cout << a;
	cout << b;
	
	return 0;
}
