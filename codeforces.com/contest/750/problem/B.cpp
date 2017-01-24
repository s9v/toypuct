#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
bool eq(double a, double b) { return fabs(a-b) < EPS; }

int n;

int main() {
	cin >> n;
	
	bool answer = true;
	int dist = 0;
	
	//~ cerr << "-> " << dist << "\n";
	for (int i = 0; i < n; i++) {
		int l;
		string dir;
		cin >> l >> dir;
		
		if ((dist == 0 and dir != "South") or (dist == 20000 and dir != "North")) {
			answer = false;
			break;
		}
		
		//~ l -= l/40000*40000;
		
		if (dir == "North")
			dist -= l;
		else if (dir == "South")
			dist += l;
		
		/*
		dist = abs(dist);
		dist -= dist/40000*40000;
		
		if (dist > 20000)
			dist = 40000 - dist;
		*/
		
		if (dist < 0 or dist > 20000) {
			answer = false;
			break;
		}
		
		//~ cerr << "-> " << dist << "\n";
	}
	
	if (dist != 0)
		answer = false;
	
	cout << (answer ?"YES" :"NO") << "\n";
	
	return 0;
}
