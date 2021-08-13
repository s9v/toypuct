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

//time_t st=clock();

using namespace std;

/* TYPE DEFINITIONS */
typedef		long long		i64;
typedef		vector<int>		vi;
typedef		vector<vi>		vvi;
typedef		pair<int,int>	pi;
typedef		vector<pi>		vpi;
typedef		vector<vpi>		vvpi;
typedef		vector<i64>		v64;
typedef		vector<v64>		vv64;
typedef		pair<i64,i64>	p64;
typedef		vector<p64> 	vp64;
typedef		vector<vp64>	vvp64;
typedef		vector<string>	vs;
typedef		vector<vs>		vvs;
typedef		vector<bool>	vb;
typedef		vector<vb>		vvb;
typedef		vector<char>	vc;
typedef		vector<vc>		vvc;

/* TOOLS */
template <class T> inline T max(T a, T b, T c){   return max(a, max(b, c));   }
template <class T> inline T min(T a, T b, T c){   return min(a, min(b, c));   }
template <class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' '; cerr<<endl;}

/* ALGEBRA */
template <class T> T gcd (T a, T b){    return ( b==(T)0 ?a :gcd(b,a%b) );    }
template <class T> T lcm (T a , T b){    return a/gcd(a,b)*b;    }
template <class T> T mathround (T x){    i64 i64x=(i64)x; if( x<i64x+0.5 ) return (T)i64x; return (T)i64x+1;    }
template <class T> bool isprime(T x)
{
	int till = (T)sqrt(x+.0);
	if (x <= 1) return 0;
	if (x == 2) return 1;
	if (x%2 == 0) return 0;
	for (int i=3; i<=till; i+=2) if (x%i == 0) return 0;
	return 1;
}

/* CONSTANTS */
//const double Pi = 4.0 * atan(1.0); // 4*atan(1)
//int dir[8][2] = {{+1,+0},{-1,+0},{+0,+1},{+0,-1},{-1,-1},{+1,+1},{+1,-1},{-1,+1}};
//int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/* {END} */

int k;
i64 x;
int n;
int m;

i64 r[100][5];
char pos[3] = {'A','X','C'}; // position? possible values!

int main()
{
	cin >> k;
	cin >> x;
	cin >> n;
	cin >> m;
	
	r[0][0] = 1;
	r[0][1] = 0;
	r[0][2] = 0;
	r[0][3] = 0;
	r[0][4] = 0;
	
	r[1][0] = 0;
	r[1][1] = 1;
	r[1][2] = 0;
	r[1][3] = 0;
	r[1][4] = 0;
	
	r[2][0] = 1;
	r[2][1] = 1;
	r[2][2] = 0;
	r[2][3] = 0;
	r[2][4] = 1;
	
	for (int i = 3; i <= 50; i++) {
		r[i][0] = r[i-1][0] + r[i-2][0];
		r[i][1] = r[i-1][1] + r[i-2][1];
		r[i][2] = r[i-1][2] + r[i-2][2] + (i%2 == 1);
		r[i][3] = r[i-1][3] + r[i-2][3] + (i%2 == 0);
		r[i][4] = r[i-1][4] + r[i-2][4];
	}
	
	k--;
	
	char A[n+1];
	fill(A, A+n, 'X');
	A[n] = '\0';
	
	char B[m+1];
	fill(B, B+m, 'X');
	B[m] = '\0';
	
	for (int a = 0; a <= 50; a++) { // r 1
		for (int b = 0; b <= 50; b++) { // r 2
			for (int birbas = 0; birbas < 3; birbas++) {
				for (int birson = 0; birson < 3; birson++) {
					for (int ikibas = 0; ikibas < 3; ikibas++) {
						for (int ikison = 0; ikison < 3; ikison++) {
							fill(A, A+n, 'X');
							fill(B, B+m, 'X');
							
							A[0] = pos[birbas];
							A[n-1] = pos[birson];
							B[0] = pos[ikibas];
							B[m-1] = pos[ikison];
							
							if (A[0] != pos[birbas] || A[n-1] != pos[birson] || B[0] != pos[ikibas] || B[m-1] != pos[ikison])
								continue;
							
							i64 san = 0;
							san += r[k][0]*a;
							san += r[k][1]*b;
							san += r[k][2]*(B[m-1] == 'A' && A[0] == 'C');
							san += r[k][3]*(B[m-1] == 'A' && B[0] == 'C');
							san += r[k][4]*(A[n-1] == 'A' && B[0] == 'C');
							
							if (san == x) {
								int rem;
								
								rem = a;
								for (int i = 0; i < n && rem > 0; i++) {
									if (A[i] != 'X')
										continue;
									
									char trans = 'A';
									if (i > 0 && A[i-1] == 'A')
										trans = 'C';
									
									rem -= (trans == 'C');
									
									A[i] = trans;
								}
								
								if (rem > 0)
									continue;
								
								rem = b;
								for (int i = 0; i < m && rem > 0; i++) {
									if (B[i] != 'X')
										continue;
									
									char trans = 'A';
									if (i > 0 && B[i-1] == 'A')
										trans = 'C';
									
									rem -= (trans == 'C');
									
									B[i] = trans;
								}
								
								if (rem > 0)
									continue;
								
								i64 san2 = 0;
								san2 += r[k][0]*a;
								san2 += r[k][1]*b;
								san2 += r[k][2]*(B[m-1] == 'A' && A[0] == 'C');
								san2 += r[k][3]*(B[m-1] == 'A' && B[0] == 'C');
								san2 += r[k][4]*(A[n-1] == 'A' && B[0] == 'C');
								
								if (san2 != x)
									continue;
								
								int cnt;
								
								cnt = 0;
								for (int i = 1; i < n; i++)
									cnt += (A[i-1] == 'A' && A[i] == 'C');
								
								if (cnt != a)
									continue;
								
								cnt = 0;
								for (int i = 1; i < m; i++)
									cnt += (B[i-1] == 'A' && B[i] == 'C');
								
								if (cnt != b)
									continue;
								
								cout << A << "\n";
								cout << B << "\n";
								return 0;
							}
						}
					}
				}
			}
		}
	}
	
	cout << "Happy new year!";
	
//	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);		// needs disabled ios_base::sync_with_stdio(false);
//	freopen("output.txt", "w", stdout);		// needs disabled ios_base::sync_with_stdio(false);
//	cin >> noskipws;
//	cin >> skipws;
	
	
	
//	cout<<clock()-st;
	/*
	getchar();
	getchar();
	*/
	return EXIT_SUCCESS;
}
