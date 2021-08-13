/*
 * Andrew's Monotone Chain Algorithm
 * Finding Convex Hull
 * 
 * (c) 2013 Sylap Aliyev <sylapaliyev@gmail.com>
 * 17/12/2013
 * */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long llint;

struct Point {
	llint x, y;
	bool f;
	void read() {
		//cin >> x >> y;
		scanf("%I64d %I64d", &x, &y);
		
	};
	bool operator<(Point other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
};

llint cross(Point a, Point b, Point c) {
	return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

int n, m;
Point p[200000];
Point s[200000]; int top;

void andrewchain() {
	sort(p, p+n);
	
	for (int i = 0; i < n; i++) {
		while (top >= 2 && cross(s[top-2], s[top-1], p[i]) < 0) top--;
		s[top++] = p[i];
	}
	top--;
	
	for (int i = n-1, tmp = top; i >= 0; i--) {
		while (top >= tmp+2 && cross(s[top-2], s[top-1], p[i]) < 0) top--;
		s[top++] = p[i];
	}
	top--;
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++)
		p[i].read();
	
	cin >> m;
	for (int i = n; i < n+m; i++)
		p[i].read(), p[i].f = 1;
	
	n += m;
	
	andrewchain();
	
	for (int i = 0; i < top; i++)
		if (s[i].f) {
			cout << "NO";
			return 0;
		}
	
	cout << "YES";
	return 0;
}
