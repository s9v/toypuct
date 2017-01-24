#include <bits/stdc++.h>
#define sz(X) (int)(X).size()
#define ln(X) (int)(X).length()
using namespace std;

int main() {
	int x1, y1;
	int x2, y2;

	int vx1, vy1;
	int vx2, vy2;

	int x, y;
	int vx, vy;

	int a, b, c;

	cin >> x1 >> y1;
	cin >> x2 >> y2;

	x = x1 - x2;
	y = y1 - y2;

	cin >> vx1 >> vy1;
	cin >> vx2 >> vy2;

	vx = vx1 - vx2;
	vy = vy1 - vy2;

	c = x*x + y*y;
	b = 2*(x*vx + y*vy);
	a = vx*vx + vy*vy;

	double t = b < 0 ? -1.0 * b / 2 / a : 0;
	double mindist = sqrt( 1.0*a*t*t + 1.0*b*t + 1.0*c );

	cout.precision(15);
	cout << fixed << mindist;

	return 0;
}