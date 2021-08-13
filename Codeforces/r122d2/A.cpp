#include <iostream>
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)	for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
using namespace std;

int n;
int k;

int main()
{
	cin >> n >> k;
	
	int mintwo = 1e9;
	
	fora (two, 0, n)
		fora (three, 0, n)
			fora (four, 0, n)
				fora (five, 0, n)
					if (two+three+four+five == n && 2*two+3*three+4*four+5*five == k)
					{
						//cerr << two << " " << three << " " << four << " " << five << "\n";
						mintwo = min(mintwo, two);
					}
	
	cout << mintwo;
	
	return 0;
}
