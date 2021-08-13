#include <iostream>
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
using namespace std;

//  wtf[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
int mup[] = {'2', '2', '2', '3', '3', '3', '4', '4', '1', '1', '5', '5', '6', '6', '0', '7', '0', '7', '7', '8', '8', '8', '9', '9', '9', '0'};

string s;
int n;
string dict[50000];
int dyn[200];

int main()
{
	while (cin >> s, s != "-1")
	{
		fill(dyn, dyn+ln(s), 1e8)
		
		cin >> n;
		
		forn (i, n)
			cin >> dict[i];
		
		forn (i, n)
        {
        }
	}
	
	return 0;
}
