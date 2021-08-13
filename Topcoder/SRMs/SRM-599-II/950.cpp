# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <functional> // greater<int>()
# include <vector>
# include <string>
# include <queue>
# include <stack>
# include <list>
# include <map>
# include <set>
# include <cstdio>
# include <cstdlib>
# include <cmath>
# include <ctime>
# include <cstring>
# include <cctype>
# include <climits> // LLONG_MAX , LLONG_MIN , INT_MAX , INT_MIN

/* MACROS */

# define  all(A)		(A).begin() , (A).end()
# define  rall(A)		(A).rbegin() , (A).rend()
# define  sz(A)			(int)(A).size()
# define  pb			push_back
# define  ppb			pop_back
# define  mp			make_pair
# define  bir			first
# define  iki			second
# define  rsz(A,X)		(A).resize(X)
# define  ln(A)			(int)(A).length()
# define  FILL(X, A)	memset((X), (A), sizeof(X))
# define  minof(X)		min_element(all(X))-X.begin()
# define  maxof(X)		max_element(all(X))-X.begin()
# define  square(X)		((X)*(X))
# define  cube(X)		((X)*(X)*(X))

# define  FOR(i, a, b)	for (int i=a; i<b; i++)
# define  FORD(i, a, b)	for (int i=a-1; i>=b; i--)
# define  REP(i,n)		for( int i=0 ; i<n ; i++ )
# define  REPD(i,n)		for( int i=n-1 ; i>=0 ; i-- )
# define  TR(it,container)  \
		for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
# define  setmap_found(container, element) (container.find(element) != container.end())
# define  vector_found(container, element) (find(all(container),element) != container.end())
# define  DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;

using namespace std;

class SimilarNames2 {
	public:
		bool isprefixof(string &big, string &small) {
			if (ln(big) < ln(small))
				return false;
			
			for (int i = 0; i < ln(small); i++)
				if (small[i] != big[i])
					return false;
			
			return true;
		}
		
		int count(vector <string> names, int L) {
			const long long MOD = 1000000007;
			
			sort(all(names));
			
			int n = sz(names);
			int dp[50][50];
			fill(dp[0], dp[50], 0);
			
			for (int i = n-1; i >= 0; i--) { // in non-descending order of length
				dp[i][0] = 1;
				
				for (int j = i+1; j < n; j++)
				if (isprefixof(names[j], names[i])) {
					for (int k = 1; k < n; k++)
						dp[i][k] = (dp[i][k] + dp[j][k-1]) % MOD;
				}
			}
			
			long long ret = 0;
			
			for (int i = 0; i < n; i++)
				ret = (ret + dp[i][L-1]) % MOD;
			
			for (int i = 2; i <= n-L; i++)
				ret = (ret * i) % MOD;
			
			return ret;
		}
};

/*
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	
}
*/
