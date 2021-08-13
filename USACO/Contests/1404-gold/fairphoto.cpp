#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define  all(X)  (X).begin(), (X).end()
#define  mp  make_pair
#define  pb  push_back
#define  dbg(vari)  cerr << #vari << " = " << (vari) << endl;
using namespace std;

typedef vector<int> vi;
typedef pair<vi, int> pvi;

const int BREED = 3;
const int LARGE = (int)1e8;

struct mycmp { bool operator() (pvi a, pvi b) const { return a.first < b.first; } };
// set<pvi, mycmp> s; // s.insert(mp(vi{5,1,1}, 5));

int n, k;
int res = -1;
pair<int, int> cow[100000];
// vi cnt(BREED);
// vi v(BREED);
bool use[BREED];

int main()
{
	freopen("fairphoto.in", "r", stdin);
	freopen("fairphoto.out", "w", stdout);
	
	cin >> n;
	cin >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> cow[i].first;
		cin >> cow[i].second;
	}
	
	sort(cow, cow+n);
	
	for (int mask = 0; mask < (1<<BREED); mask++) {
		int nbreed = 0;
		
		// dbg(mask);
		
		// cerr << "use : ";
		for (int i = 0; i < BREED; i++) {
			use[i] = ((mask&(1<<i)) > 0);
			nbreed += ((mask&(1<<i)) > 0);
			// cerr << use[i] << " ";
		}
		// cerr << "\n";
		
		// dbg(nbreed);
		// dbg(k);
		
		if (nbreed < k) {
			// cerr << "Less number of diffbreeds\n\n";
			// cerr << "\n===================================\n";
			continue;
		}
		else {
			// cerr << "OK. Sufficient number of diffbreeds.\n\n";
		}
		
		for (int fst = 0, lst = 0; lst <= n; lst++) {
			/*
			if (mask == 3 && lst != n) {
				cerr << lst << " --» " << use[ cow[lst].second-1 ] << "\n";
			}
			*/
			
			if (lst == n || use[ cow[lst].second-1 ] == 0) {
				// dbg(fst);
				// dbg(lst);
				
				set<pvi, mycmp> s;
				vi v(BREED);
				vi cnt(BREED);
				
				s.insert(mp(v, fst-1));
				
				int mn = LARGE;
				for (int i = fst; i < lst; i++) {
					// dbg(i);
					
					cnt[cow[i].second - 1]++;
					
					/*
					cerr << "cnt : ";
					for (int j = 0; j < BREED; j++)
						cerr << cnt[j] << " ";
					cerr << "\n";
					*/
					
					mn = LARGE;
					for (int j = 0; j < BREED; j++)
						if (use[j])
							mn = min(mn, cnt[j]);
					
					// dbg(mn);
					
					// cerr << "v : ";
					for (int j = 0; j < BREED; j++) {
						v[j] = (use[j] ?cnt[j]-mn :0);
						// cerr << v[j] << " ";
					}
					// cerr << "\n";
					
					if (s.find(mp(v, i)) == s.end()) {
						s.insert(mp(v, i));
						// cerr << "Insert new «mp(v, i)»\n";
					}
					else if (mn != 0) {
						int idx = (*s.find(mp(v, i))).second;
						// dbg(idx);
						// dbg(cow[i].first);
						// dbg(cow[idx+1].first);
						res = max(res, cow[i].first - cow[idx+1].first);
					}
				}
				
				fst = lst+1;
			}
		}
		
		// cerr << "\n===================================\n";
	}
	
	// cerr << "RES : ";
	
	cout << res;
	
	return 0;
}
