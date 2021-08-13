#include <iostream>
#define  ln(s)  (int)s.length()
using namespace std;

int a, b;
int c, d;
string s;
string s1;
string s2;

int main()
{
	cin >> s;
	
	int idx = s.find('|');
	s1 = s.substr(0, idx);
	s2 = s.substr(idx+1, ln(s)-idx-1);
	
	cin >> s;
	
	a = ln(s1);
	b = ln(s2);
	c = ln(s);
	d = c+b-a;
	
	if ((d&1) || d/2 > c || c-d/2 > c)
	{
		cout << "Impossible";
		return 0;
	}
	
	d /= 2;
	
	for (int i = 0; i < d; i++)
		s1 += s[i];
	
	for (int i = d; i < ln(s); i++)
		s2 += s[i];
	
	cout << s1 << "|" << s2;
	
	return 0;
}
