#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long llint;

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		llint l, d, s, c, r;
		cin >> l;
		cin >> d;
		cin >> s;
		cin >> c;
		
		r = s;
		for (int i = 0; i < d-1; i++)
		{
			if (r >= l)
				break;
			
			r *= (c+1);
		}
		
		cout << (r >= l ?"ALIVE AND KICKING" :"DEAD AND ROTTING") << "\n";
	}

	return 0;
}
