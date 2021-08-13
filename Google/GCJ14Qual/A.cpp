#include <fstream>
using namespace std;

int t;
int r1;
int m1[4][4];
int r2;
int m2[4][4];

int main()
{
	ifstream fin("A.txt");
	ofstream fout("A.out");
	
	fin >> t;
	
	for (int tfoo = 0; tfoo < t; tfoo++)
	{
		fin >> r1;
		r1--;
		
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				fin >> m1[i][j];
		
		fin >> r2;
		r2--;
		
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				fin >> m2[i][j];
		
		int cnt = 0;
		int lstx = -1;
		for (int x = 1; x <= 16; x++)
		if ((m1[r1][0] == x || m1[r1][1] == x || m1[r1][2] == x || m1[r1][3] == x) &&
			(m2[r2][0] == x || m2[r2][1] == x || m2[r2][2] == x || m2[r2][3] == x))
		{
			cnt++;
			lstx = x;
		}
		
		fout << "Case #" << tfoo+1 << ": ";
		
		if (cnt == 0)
			fout << "Volunteer cheated!";
		else if (cnt == 1)
			fout << lstx;
		else
			fout << "Bad magician!";
		
		fout << "\n";
	}
	
	return 0;
}
