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

using namespace std;

class MiniatureDachshund {
	public:
		int maxMikan(vector<int> mikan, int weight) {
			sort(mikan.begin(), mikan.end());
			
			int i = 0;
			for (i = 0; i<(int)mikan.size() && weight+mikan[i] <= 5000; i++) {
				weight += mikan[i];
			}
			
			return i;
		}
};

