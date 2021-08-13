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

class BigFatInteger2 {
	public:
		string isDivisible(int a, int b, int c, int d) {
			if (c == 1)
				return string("divisible");
			
			vector< pair<int,int> > pa;
			vector< pair<int,int> > pc;
			
			int sqrta = sqrt(a);
			for (int i = 2; i <= sqrta && a > 1; i++) {
				int cnt = 0;
				while (a%i == 0) {
					a /= i;
					cnt++;
				}
				
				if (cnt > 0)
					pa.pb(mp(i, cnt));
			}
			if (a > 1)
				pa.pb(mp(a, 1));
			
			int sqrtc = sqrt(c);
			for (int i = 2; i <= sqrtc && c > 1; i++) {
				int cnt = 0;
				while (c%i == 0) {
					c /= i;
					cnt++;
				}
				
				if (cnt > 0)
					pc.pb(mp(i, cnt));
			}
			if (c > 1)
				pc.pb(mp(c, 1));
			
			/*
			cerr << "pa::\n";
			for (int i = 0; i < sz(pa); i++)
				cerr << pa[i].first << " " << pa[i].second << "\n";
			cerr << "\n";
			
			cerr << "pc::\n";
			for (int i = 0; i < sz(pc); i++)
				cerr << pc[i].first << " " << pc[i].second << "\n";
			cerr << "\n";
			*/
			
			int i = 0, j = 0;
			while (i < sz(pa) && j < sz(pc)) {
				if (pa[i].first == pc[j].first) {
					if (1LL*pa[i].second*b >= 1LL*pc[j].second*d) {
						i++;
						j++;
					}
					else return string("not divisible");
				}
				else
					i++;
			}
			
			return (sz(pc) == j ?string("divisible") :string("not divisible"));
		}
};

/*
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	
}
*/
