#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
#define  pb  push_back
#define  mp  make_pair
#define  sz(X)  (int)X.size()
#define  ln(X)  (int)X.length()
 using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int INF = 1e9;

int n;
int s[200000];
int t[200000];
int z[200000];

int main()
{
	ifstream fin("boarding.in");
	ofstream fout("boarding.out");
	
	fin >> n;
	
	for (int i = 0; i < n; i++)
	{
		fin >> s[i] >> t[i];
	}
	
	for (int i = n-1; i >= 0; i--)
	{
		z[i] = (n-1-i)+s[i]+t[i];
		
		for (int j = i+1; j < n; j++)
			if (s[j] < s[i])
				z[i] = max(z[i], z[j]+(s[i]-s[j]+1)+t[i]);
	}
	
	fout << *max_element(z, z+n);
	return 0;
}
