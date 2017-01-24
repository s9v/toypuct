#include <bits/stdc++.h>
#define sqr(X) (X)*(X)
using namespace std;

const double EPS = 1e-9;

int main() {
	int T;
	cin >> T;

	for (int _case = 1; _case <= T; _case++) {
		int p, x, y;
		
		scanf("%d %d %d", &p, &x, &y);
		
		x -= 50;
		y -= 50;
		
		if (x*x + y*y == 0) {
			printf("Case #%d: black\n", _case);
		}
		else {
			double d = sqrt(x*x + y*y);
			double ang = acos( d*y / (x*x + y*y));
			double angle = ang;
			ang = ang / M_PI * 180;
			
			// if (d <= 50.0 && ang <= 360.0*p/100)
			
			if (d < 50.0 + EPS && ang < 360.0*p/100 + EPS)
				printf("Case #%d: black\n", _case);
			else
				printf("Case #%d: white\n", _case);
			
			printf("angle = %lf\n\n", angle);
		}
	}
	
	return 0;
}
