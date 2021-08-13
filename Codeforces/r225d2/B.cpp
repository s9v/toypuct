#include <iostream>
using namespace std;

int n, m, k;

int main()
{
	cin >> n >> m >> k;
	
	cout << m*(m-1)/2 << "\n";
	
	for (int i = 0; i < m; i++)
		for (int j = i+1; j < m; j++)
			cout << (k == 0 ?i :j)+1 << " " << (k == 0 ?j :i)+1 << "\n";
	
	return 0;
}
