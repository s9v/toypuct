# include <iostream>

using namespace std;

const int MAXN = 15000;
const int MAXX = 32010;
const int INIT_VALUE = 0;
const int NEUTRAL_VALUE = 0;

int n;
int res[MAXN];
int kord[MAXX][2];
int rt_sum[4*MAXX];

int unite(int a, int b) {
	return a + b;
}

void init(int root, int left, int right, int *range_tree) {
	if (left == right) {
		rt_sum[root] = INIT_VALUE;
	} else {
		init(2 * root + 1, left, (left + right) / 2 + 0, range_tree);
		init(2 * root + 2, (left + right) / 2 + 1, right, range_tree);
		rt_sum[root] = unite(
			rt_sum[2 * root + 1],
			rt_sum[2 * root + 2]
			);
	}
}

void init_sum(int n) {
	init(0, 0, MAXX, rt_sum);
}

int query(int a, int b, int root, int left, int right, int  *range_tree) {
	if (b < left || right < a)
	return NEUTRAL_VALUE;
	
	if (a <= left && right <= b)
	return range_tree[root];
	
	return unite(
		query(a, b, 2 * root + 1, left, (left + right) / 2 + 0, range_tree),
		query(a, b, 2 * root + 2, (left + right) / 2 + 1, right, range_tree)
		);
}

int query_sum(int a, int b) {
	return query(a, b, 0, 0, MAXX, rt_sum);
}

void modify(int ind, int delta, int root, int left, int right, int *range_tree) {
	if (ind < left || right < ind)
		return;
	
	if (left == ind && ind == right) {
		range_tree[root] += delta;
		return;
	}
	
	modify(ind, delta, 2 * root + 1, left, (left + right) / 2 + 0, range_tree);
	modify(ind, delta, 2 * root + 2, (left + right) / 2 + 1, right, range_tree);
	
	range_tree[root] = unite(
		range_tree[2 * root + 1],
		range_tree[2 * root + 2]
		);
}

void modify_sum(int ind, int delta) {
	modify(ind, delta, 0, 0, MAXX, rt_sum);
}

int main()
{
	cin >> n;
	
	init_sum(MAXX);
	
	for (int i=0; i<n; i++)
	{
		int x, y;
		cin >> x >> y;
		
		res[ query_sum(0,x) ]++;
		modify_sum(x,1);
	}
	
	for (int i=0; i<n; i++)
	cout << res[i] << "\n";
	
	return 0;
}
