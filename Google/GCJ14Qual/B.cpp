#include <iostream>
#include <fstream>
#define  dbg(vari) cerr << #vari << " = " << (vari) << endl
using namespace std;

int t;
double c, f, x;
double s;
double sum;

int main()
{
	time_t st = clock();
	
	ifstream fin("B.txt");
	ofstream fout("B.out");
	
	fin >> t;
	
	for (int tfoo = 0; tfoo < t; tfoo++)
	{
		fin >> c >> f >> x;
		s = 2.0;
		sum = 0.0;
		
		while (x/s > c/s + x/(s+f))
		{
			sum += c/s;
			s += f;
		}
		
		fout << "Case #" << tfoo+1 << ": ";
		fout.precision(9);
		fout << fixed << sum + x/s;
		fout << "\n";
	}
	
	cerr << clock()-st;
	
	return 0;
}
