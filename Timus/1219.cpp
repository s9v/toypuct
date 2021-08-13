# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

int main()
{
	int k;
	srand((unsigned)time(NULL));
	for (int i=0 ; i<1000000 ; i++)
	{
		k=rand()%26+97;
		cout<<char(k);
	}
	return 0;
}
