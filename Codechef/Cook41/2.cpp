#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int t;
double dist;
double t1;
double t2;

int main() {
	cin >> t;
	
	while (t--) {
		int hh;
		int mm;
		char tmp;
		
		cin >> hh >> tmp >> mm;
		t2 = hh*60+mm;
		
		cin >> hh >> tmp >> mm;
		t1 = hh*60+mm;
		
		cin >> dist;
		
		double p1 = t2-t1+dist;
		double p2 = 0;
		
		if (2*dist > (t2-t1))
			p2 = 2*dist - (2*dist-(t2-t1))/2;
		else
			p2 = t2-t1;
		
		printf("%.1lf %.1lf\n", p1, p2);
	}
	
	
	return 0;
}
