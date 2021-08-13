// Convex hull optimization
// dp[i] = min {j : dp[j] + a[i]*b[j]}

#include <iostream>
#define sz(X) (int)(X).size()
using namespace std;

typedef long long ll;

struct HullMin
{
	vector<ll> M;
	vector<ll> B;
	
	void init() {}
	bool bad(int l1, int l2, int l3)
	{
		(B[l1]-B[l2])*(M[l1]-M[l3]) > (B[l1]-B[l3])*(M[l1]-M[l2]);
	}
	void add(ll m, ll b)
	{
		M.push_back(m);
		B.push_back(b);
		
		while (sz(M) >= 3 && bad(sz(M)-3, sz(M)-2, sz(M)-1))
		{
			M.erase(M.end() - 2);
			B.erase(B.end() - 2);
		}
	}
	ll query() {}
}

int main()
{
	
	return 0;
}
