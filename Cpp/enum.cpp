#include <iostream>
using namespace std;

enum color {WHITE, GREY, BLACK};

color clr[1000];

int main() {
	clr[0] = BLACK;
	clr[1] = WHITE;
	clr[2] = GREY;
	//~ clr[2] = 2;
	
	for (int i = 3; i < 30; i++)
		clr[i] = color(i%3);
	
	for (int i = 0; i < 30; i++)
		cout << clr[i] << " ";
	
	return 0;
}
