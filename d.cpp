#include <bits/stdc++.h>
#define ln(S) (S).length()
#define sz(S) (S).size()
#define mp make_pair
#define pb push_back
#define L first
#define R second
using namespace std;

typedef long long i64;
typedef pair<int, int> pi;

const int LARGE = 1e9;
const int MOD = 31991;

struct Matrix {
	vector<vector<int>> entries;

	Matrix(int r, int c) {
		entries.resize(r);

		for (int i = 0; i < r; ++i) {
			entries[i].resize(c);
		}
	}

	Matrix mult(Matrix other) {
		auto &A = entries;
		auto &B = other.entries;

		int r = sz(A);
		int s = sz(A[0]);
		int c = sz(B[0]);

		assert(sz(A[0]) == sz(B));

		Matrix res(r, c);
		auto &R = res.entries;

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				for (int k = 0; k < s; ++k) {
					R[i][j] = (R[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
				}
			}
		}

		return res;
	}
};

int d;
int n;

Matrix pwr(Matrix a, int n) {
	if (n == 1) {
		return a;
	}
	else if (n == 2) {
		return a.mult(a);
	}
	else if (n%2 == 0) {
		Matrix tmp = pwr(a, n/2);
		return tmp.mult(tmp);
	}
	else {
		Matrix tmp = pwr(a, n/2);
		return tmp.mult(tmp.mult(a));
	}
}

int main() {
	cin >> d >> n;

	int D = d+1;

	// all about [factor]
	Matrix factor(D, D);
	auto &F = factor.entries;

	for (int i = 0; i < D-1; ++i) {
		F[i][i+1] = 1;
	}

	F[D-1][0] = -1;
	F[D-1][D-1] = 2;

	// all about [fibos]
	Matrix fibos(D, 1);
	auto &FF = fibos.entries;

	FF[0][0] = 1;
	FF[1][0] = 1;
	for (int i = 2; i < D; ++i) {
		for (int j = 0; j < i; ++j)
			FF[i][0] = (FF[i][0] + FF[j][0]) % MOD;
	}

	factor = pwr(factor, n);
	Matrix answer = factor.mult(fibos);

	cout << answer.entries[0][0];

	return 0;
}
