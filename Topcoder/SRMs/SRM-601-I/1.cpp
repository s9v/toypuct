#include <iostream>
#include <vector>
#define  sz(X) (int)X.size()
using namespace std;
typedef long long llint;
const int INF = 1000000000;

class WinterAndPresents {
	public:
		llint getNumber(vector<int> apple, vector<int> orange) {
			int N = sz(apple);
			
			int X = INF;
			for (int i = 0; i < N; i++)
				X = min(X, apple[i]+orange[i]);
			
			llint ret = 0;
			for (int x = 1; x <= X; x++) {
				llint mnapple = 0;
				llint mxapple = 0;
				
				for (int i = 0; i < N; i++)
					mxapple += min(x, apple[i]);
				
				for (int i = 0; i < N; i++)
					mnapple += x - min(x, orange[i]);
				
				ret += mxapple-mnapple+1;
				
				//~ cerr << x << " x\n";
				//~ cerr << mnapple << " " << mxapple << "\n\n";
			}
			
			return ret;
		}
};

int main() {
	WinterAndPresents tmp;
	//cout << tmp.getNumber(vector<int> {2, 2, 2}, vector<int> {2, 2, 2});
	cout << tmp.getNumber(vector<int> {1000000}, vector<int> {1000000});
	
	return 0;
}
