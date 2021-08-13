#include <iostream>
#include <ctime>
using namespace std;

int n, m;
int q;

int main()
{
	srand(time(NULL));
	
	n = m = 5;
	q = 30;
	
	cout << n << " ";
	cout << m << "\n";
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << (rand()%100)*(rand()%3) + (rand()%10) << " ";
		}
		cout << "\n";
	}
	
	cout << q << "\n";
	
	for (int i = 0; i < q; i++)
	{
		if (rand()%2 == 0)
		{
			cout << "c ";
			cout << rand()%n+1 << " ";
			cout << rand()%m+1 << " ";
			cout << (rand()%100)*(rand()%3) + (rand()%10) << " ";
			cout << "\n";
		}
		else
		{
			int a = rand()%n+1;
			int b = rand()%m+1;
			int c = rand()%(n-a+1) + a;
			int d = rand()%(m-b+1) + b;
			cout << "q ";
			cout << a << " ";
			cout << b << " ";
			cout << c << " ";
			cout << d << " ";
			cout << "\n";
		}
	}
	
	return 0;
}
