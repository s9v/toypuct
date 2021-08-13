#include <iostream>
#include <string>

#define  all(A)			(A).begin() , (A).end()
#define  rall(A)		(A).rbegin() , (A).rend()
#define  sz(A)			(int)(A).size()
#define  pb				push_back
#define  ppb			pop_back
#define  mp				make_pair
#define  ln(X)			(int)(X).length()
#define  square(X)		((X)*(X))
#define  cube(X)		((X)*(X)*(X))
#define  forn(i, n)  for (int i = 0; i < int(n); i++)
#define  forr(i, n)  for (int i = int(n - 1); i >= 0; i--)
#define  fora(i, a, b)  for (int i = int(a); i <= int(b); i++)
#define  forb(i, a, b)  for (int i = int(a); i >= int(b); i--)
#define  fore(it, a)	for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define  dbg(vari) cerr << #vari << " = " << (vari) << endl;
using namespace std;

int n;
string s;

int main()
{
	cin >> n;
	cin >> s;
	int id = s.find("*");
	int len1 = id;
	int len2 = ln(s)-len1-1;
	
	//cerr << id << " : aster\n";
	
	//dbg(id);
	//dbg(len1);
	//dbg(len2);
	
	forn (i, n)
	{
		string t;
		cin >> t;
		
		if (ln(t) >= ln(s)-1)
			cout << (t.substr(0, len1) == s.substr(0, len1) && t.substr(ln(t)-len2, len2) == s.substr(ln(s)-len2, len2) ?"DA" :"NE");
		else
			cout << "NE";
		cout << "\n";
	}
	
	return 0;
}
