#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#define  ln(S)  (int)S.length()
using namespace std;

string s;

int perm[] = {1, 6, 8, 9};
int suffix[7];

int main()
{
	cin >> s;
	
	s.erase(s.begin() + s.find('1'));
	s.erase(s.begin() + s.find('6'));
	s.erase(s.begin() + s.find('8'));
	s.erase(s.begin() + s.find('9'));
	
	sort(s.begin(), s.end(), greater<char>());
	
	do {
		int temp = 0;
		for (int i = 0; i < 4; i++)
			temp *= 10,
			temp += perm[i];
		
		suffix[temp%7] = temp;
	} while (next_permutation(perm, perm+4));
	
	if (s[0] == '0')
	{
		cout << suffix[0];
		cout << s;
		return 0;
	}
	
	int temp = 0;
	for (int i = 0; i < ln(s); i++)
		temp *= 10,
		temp += s[i]-'0',
		temp %= 7;
	
	temp *= 10000;
	temp %= 7;
	
	cout << s;
	cout << suffix[(7-temp)%7];
	
	return 0;
}
