#include <bits/stdc++.h>
#include <set>
#define sz(X) (int)(X).size()
#define ln(X) (int)(X).length()
using namespace std;

const int DUMMY = -505404;

struct Node {
	int key;

	bool operator<(const Node &x) const {
		return key < x.key;
	}
};

int n;
set<pair<int, pair<int, int>>> pxi;
set<pair<int, pair<int, int>>> xpi;
int par[200100];

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x, p;
		cin >> x >> p;

		pxi.insert(make_pair(p, make_pair(x, i)));
	}

	for (auto pxi2 = pxi.rbegin(); pxi2 != pxi.rend(); pxi2++)
	{
		int p = pxi2->first;
		int x = pxi2->second.first;
		int i = pxi2->second.second;

		if (xpi.empty()) {
			par[i] = -2;
		}
		else {
			auto xpi1 = xpi.lower_bound(make_pair(x, make_pair(DUMMY, DUMMY)));
			auto xpi2 = xpi.upper_bound(make_pair(x, make_pair(DUMMY, DUMMY)));

			if (xpi2 == xpi.begin())
				par[i] = xpi1->second.second;
			else {
				xpi2--;

				if (abs(xpi1->first - x) == abs(xpi2->first - x)) {
					par[i] = (xpi1->second.first > xpi2->second.first ?xpi1 :xpi2)->second.second;
				}
				else {
					par[i] = (abs(xpi1->first - x) < abs(xpi2->first - x) ?xpi1 :xpi2)->second.second;
				}
			}
		}

		xpi.insert(make_pair(x, make_pair(p, i)));
	}

	for (int i = 0; i < n; ++i) {
		cout << par[i] + (1) << " ";
	}

	return 0;
}