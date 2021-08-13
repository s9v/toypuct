// IZhO V - 2007/2008
// codeforces.com/gym/100142
// E. Watermelons of the Field of Wonders of the Fool's Land

#include <iostream>
using namespace std;

struct wmelon {
	int w; // init weight
	int s; // growth speed
	bool operator<(wmelon other) const { return w < other.w; }
};

int n;
int m;
wmelon wms[100000];
int hull[100000];
int nhull;

bool bad(int l1, int l2, int l3) {
	return (wms[l1].s-wms[l2].s)*(wms[l3].w-wms[l2].w) > (wms[l2].s-wms[l3].s)*(wms[l2].w-wms[l1].w);
	return (B[l1]-B[l2])*(M[l3]-M[l2]) > (B[l2]-B[l3])*(M[l2]-M[l1]);
	return (B[l1]-B[l2])*(M[l3]-M[l1]) > (B[l1]-B[l3])*(M[l2]-M[l1]);
}

void hulltrick() {
	
	
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> wms[i].w >> wms[i].s;
	
	sort(wms, wms+n);
	hulltrick();
	
	
	return 0;
}
