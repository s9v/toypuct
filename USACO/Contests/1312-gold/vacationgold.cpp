#include <iostream>
#include <fstream>
#include <vector>
#define  pb(X)		push_back(X)
#define  mp(X,Y)		make_pair(X,Y)
#define  sz(X)			(int)X.size()
#define  DBG(X)			cerr << #X << " : " << X << "\n"
using namespace std;
typedef long long llint;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
const int LRG = (int)1e9;

int res;
llint tot;
int N, M, K, Q;
int hubs[200];
int ishub[20000];
vpi gr[20000];
vpi in[20000];
vpi out[20000];
int d[200][200];

void floyd_warka() {
	fill(d[0], d[200], LRG);
	
	for (int i = 0; i < K; i++)
		d[i][i] = 0;
	
	for (int i = 0; i < K; i++) {
		int u = hubs[i];
		
		for (int j = 0; j < sz(gr[u]); j++) {
			int v = gr[u][j].first;
			int dist = gr[u][j].second;
			
			if (ishub[v] != -1)
				d[i][ ishub[v] ] = min(d[i][ ishub[v] ], dist);
		}
	}
	
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			for (int k = 0; k < K; k++)
				if (d[i][j] != LRG && d[j][k] != LRG && d[i][k] > d[i][j]+d[j][k]) {
					d[i][k] = d[i][j]+d[j][k];
				}
}

int main() {
	ifstream fin("vacationgold.in");
	ofstream fout("vacationgold.out");
	
	fin >> N;
	fin >> M;
	fin >> K;
	fin >> Q;
	
	res = Q;
	tot = 0;
	
	for (int i = 0; i < M; i++) {
		int u, v, d;
		fin >> u >> v >> d;
		u--; v--;
		gr[u].pb(mp(v,d));
	}
	
	fill(ishub, ishub+20000, -1);
	
	for (int i = 0; i < K; i++) {
		fin >> hubs[i];
		hubs[i]--;
		ishub[ hubs[i] ] = i;
	}
	
	for (int i = 0; i < N; i++) {
		int u = i;
		
		for (int j = 0; j < sz(gr[u]); j++) {
			int v = gr[u][j].first;
			int dist = gr[u][j].second;
			
			if (ishub[u] != -1)
				in[v].pb(mp(ishub[u], dist));
			
			if (ishub[v] != -1)
				out[u].pb(mp(ishub[v], dist));
		}
	}
	
	/*
	for (int i = 0; i < N; i++)
	{
		cerr << i+1 << " in --> ";
			for (int j = 0; j < sz(in[i]); j++)
				cerr << hubs[ in[i][j].first ]+1 << " ";
		cerr << "\n";
		cerr << i+1 << " out --> ";
			for (int j = 0; j < sz(out[i]); j++)
				cerr << hubs[ out[i][j].first ]+1 << " ";
		cerr << "\n";
	}
	*/
	
	
	floyd_warka();
	
	for (int i = 0; i < Q; i++) {
		int a, b;
		fin >> a >> b;
		a--; b--;
		
		if (ishub[a] != -1 && ishub[b] != -1) {
			if (d[ ishub[a] ][ ishub[b] ] == LRG)
				res--;
			else
				tot += d[ ishub[a] ][ ishub[b] ];
		}
		else if (ishub[a] == -1 && ishub[b] == -1) {
			int mnd = LRG;
			
			for (int i = 0; i < sz(out[a]); i++)
				for (int j = 0; j < sz(in[b]); j++)
					if (out[a][i].second != LRG && in[b][j].second != LRG)
						mnd = min(mnd, d[ out[a][i].first ][ in[b][j].first ] + out[a][i].second + in[b][j].second);
			
			if (mnd == LRG)
				res--;
			else
				tot += mnd;
		}
		else if (ishub[a] != -1 && ishub[b] == -1) {
			int mnd = LRG;
			
			for (int j = 0; j < sz(in[b]); j++)
				if (in[b][j].second != LRG)
					mnd = min(mnd, d[ ishub[a] ][ in[b][j].first ] + in[b][j].second);
			
			if (mnd == LRG)
				res--;
			else
				tot += mnd;
		}
		else if (ishub[a] == -1 && ishub[b] != -1) {
			int mnd = LRG;
			
			for (int i = 0; i < sz(out[a]); i++)
				if (out[a][i].second != LRG)
					mnd = min(mnd, d[ out[a][i].first ][ ishub[b] ] + out[a][i].second);
			
			if (mnd == LRG)
				res--;
			else
				tot += mnd;
		}
	}
	
	fout << res << "\n";
	fout << tot << "\n";
	
	return 0;
}
