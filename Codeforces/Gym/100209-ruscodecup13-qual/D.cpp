#include <iostream>
#include <vector>
using namespace std;

int n;

void prbinary(int x)
{
	vector<bool> v;
	
	for (int i = 0; i < n; i++, x >>= 1)
		v.push_back(x - x/2*2);
	
	for (int i = v.size()-1; i >= 0; i--)
		cout << v[i];
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < (1<<n); i++)
	{
		prbinary(i^(i/2));
		cout << "\n";
	}
	
	return 0;
}

