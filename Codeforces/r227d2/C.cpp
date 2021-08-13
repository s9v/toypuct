#include <iostream>
#include <string>
using namespace std;

string s;
int res;

int main()
{
	cin >> s;
	
	res = 1; // NOTE THIS
	int lst = s.length()-1;
	
	while (lst > 0)
	{
		int fst = lst;
		
		while (s[fst] == '0')
			fst--;
		
		if (lst-fst+1 < fst)
		{
			res++;
			lst = fst-1;
		}
		else if (lst-fst+1 > fst)
			break;
		else if (lst-fst+1 == fst)
		{
			if (s.substr(0,fst) >= s.substr(fst, lst-fst+1))
			{
				res++;
				lst = fst-1;
			}
			else
				break;
		}
	}
	
	cout << res;
	
	return 0;
}
