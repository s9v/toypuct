#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, k;
string tmp;
int q;
int p[50];
string c[50][100];
string r[100][50];
string res[100];

bool issmaller(int x) {
	for (int i = 0; i < q; i++)
		if (res[i] > r[x][i])
			return 0;
		else if (res[i] < r[x][i])
			return 1;
	
	return (res[q-1] < r[x][q-1]);
}

bool compare(string a, string b) {
	/*
	for (int i = 0; i < q; i++)
		if (a[i] > b[i])
			return 0;
		else if (a[i] < b[i])
			return 1;
	
	return (a[q-1] < b[q-1]);
	*/
	return 0;
}

int main() {
	ifstream fin("nocow.in");
	ofstream fout("nocow.out");
	
	fin >> n >> k;
	k--;
	
	for (int i = 0; i < n; i++) {
		fin >> tmp >> tmp >> tmp >> tmp;
		
		q = 0;
		while (fin >> tmp, tmp != "cow.") {
			c[q][ p[q]++ ] = tmp;
			r[i][q] = tmp;
			q++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < q; j++)
			cerr << r[i][j] << "| ";
		cerr << "\n";
	}
	
	for (int i = 0; i < q; i++) {
		sort(c[i], c[i]+p[i]);
		p[i] = unique(c[i], c[i]+p[i]) - c[i];
	}
	
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < p[i]; j++)
			cerr << c[i][j] << "| ";
		cerr << "\n";
	}
	
	for (int kk = 0; kk < 12; kk++) {
		int tk = kk;
		
		for (int j = q-1; j >= 0; j--) {
			res[j] = c[j][ tk%p[j] ];
			tk /= p[j];
		}
		
		for (int i = 0; i < q; i++)
			cerr << res[i] << " ";
		cerr << "\n";
	}
	
	cerr << "================\n";
	
	for (string *i = r[0]; i < r[n]; i++)
	{
		
	}
	
	sort(, , compare);
	
	for (int i = 0; i < n; i++) {
		int tk = k;
		
		for (int j = q-1; j >= 0; j--) {
			res[j] = c[j][ tk%p[j] ];
			tk /= p[j];
		}
		
		if (issmaller(i))
			break;
		
		cerr << k << " k++\n";
		k++;
	}
	
	for (int i = 0; i < q; i++) {
		fout << res[i];
		
		if (i != q-1)
			fout << " ";
	}
	
	fin.close();
	fout.close();
	return 0;
}
