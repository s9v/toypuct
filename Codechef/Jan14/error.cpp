#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		cout << (s.find("010") != -1U || s.find("101") != -1U ?"Good" :"Bad") << "\n";
	}

	return 0;
}
