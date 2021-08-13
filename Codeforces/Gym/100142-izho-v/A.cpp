#include <fstream>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long llint;

ifstream fin("veryhard.in");
ofstream fout("veryhard.out");

int n;
llint a;
llint sa;

int main()
{
	fin >> n;
	
	for (int i = 0; i < n; i++)
	{
		fin >> a;
		sa = sqrt(a);
		fout << (sa*sa == a) << "\n";
	}
	
	return 0;
}
