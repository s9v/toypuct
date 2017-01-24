#include <bits/stdc++.h>
#define sz(X) (int)(X).size()
#define ln(X) (int)(X).length()
using namespace std;

set<int> s;

int arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int main() {
	s.insert(1);
	s.insert(2);
	s.insert(8);
	s.insert(5);

	auto it = s.begin();


	it++;
	it++;
	it++;

	(*it)++;



	// cout << *it;

	int *pt = &arr[0];

	pt++;
	pt++;
	pt++;

	(*pt)++;

	cout << *pt;
	

	return 0;
}