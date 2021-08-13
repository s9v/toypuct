#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double pee = acos(-1);

struct Point
{
	double x, y;
	
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	double dist(Point p)
	{
		return sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));
	}
};

struct Line
{
	double A, B, C; // Ax+By=C
	
	Line(Point p1 = Point(), Point p2 = Point())
	{
		A = p2.y-p1.y;
		B = p1.x-p2.x;
		C = A*p1.x + B*p1.y;
	}

	Line orthagonal(Point p)
	{
		Line r;

		r.A = -B;
		r.B = A;
		r.C = r.A*p.x + r.B*p.y;

		return r;
	}

	Point intr(Line l)
	{
		Point r;

		double det = A*l.B - l.A*B;
		r.x = (l.B*C-B*l.C) / det;
		r.y = (A*l.C - l.A*C) / det;

		return r;
	}
};

int main()
{
	double x1, y1;
	double x2, y2;
	double x3, y3;

	cout.precision(2);

	while (cin >> x1 >> y1) {
		cin >> x2 >> y2;
		cin >> x3 >> y3;

		Line l1 = Line(Point(x1, y1), Point(x2, y2)).orthagonal(Point((x1+x2)/2.0, (y1+y2)/2.0));
		Line l2 = Line(Point(x2, y2), Point(x3, y3)).orthagonal(Point((x2+x3)/2.0, (y2+y3)/2.0));
		double rad = l1.intr(l2).dist(Point(x1, y1));

		printf("%.2lf\n", 2.0*pee*rad);
	}
}
