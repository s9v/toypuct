/*
 * HopcroftCarp Library
 * Bipartite Matching
 * 
 * */

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

class HopcroftCarp {
	public:
		int *dist;
		vector<int> *gr;
		int V1; // vertices of left
		int V2; // vertices of right
		int *matchingL;
		int *matchingR;
		int matching;
		bool *vis;

		bool bfs() {
			fill(dist, dist+V1, -1);
			queue<int> Q;
			
			for (int v = 0; v < V1; v++)
				if (matchingL[v] < 0) {
					dist[v] = 0;
					Q.push(v);
				}

			bool unmatched = false;
			while ( ! Q.empty()) {
				int v = Q.front();
				Q.pop();

				for (size_t i = 0; i < gr[v].size(); i++) {
					int u = gr[v][i];
					int w = matchingR[u];

					if (w >= 0 && dist[w] < 0) {
						dist[w] = dist[v]+1;
					}

					if (w < 0)
						unmatched = true;
				}
			}

			return unmatched;
		}

		bool dfs(int v) {
			vis[v] = true;
			for (size_t i = 0; i < gr[v].size(); i++) {
				int u = gr[v][i];
				int w = matchingR[u];

				if (w < 0 || (!vis[w] && dist[w] == dist[v]+1 && dfs(w))) {
					matchingL[v] = u;
					matchingR[u] = v;
					return true;
				}
			}

			return false;
		}

		HopcroftCarp(int V1 = 0, int V2 = 0) : V1(V1), V2(V2) {
			gr = new vector<int> [V1];
			matchingL = new int [V1];
			matchingR = new int [V2];
			matching = 0;
			dist = new int [V1];
			vis = new bool [V1];
		}
		void add_edge(int v, int u) {
			assert(0 <= v && v < V1);
			assert(0 <= u && u < V2);
			gr[v].push_back(u);
		}
		void max_matching() {
			matching = 0;
			fill(matchingL, matchingL+V1, -1);
			fill(matchingR, matchingR+V2, -1);

			while (bfs()) {
				fill(vis, vis+V1, 0);

				for (int v = 0; v < V1; v++)
					if (matchingL[v] < 0 && dfs(v))
						matching++;
			}
		}
		void debug() {
			for (int i = 0; i < V1; i++) {
				cout << i << "$ ";
				for (int j = 0; j < gr[i].size(); j++) {
					cout << gr[i][j] << " ";
				}
				cout << "\n";
			}
		}
};

int main() {
	HopcroftCarp graph(5, 4);
	
	graph.add_edge(0, 0);
	graph.add_edge(0, 1);
	graph.add_edge(1, 0);
	
	graph.add_edge(2, 2);
	graph.add_edge(3, 2);
	graph.add_edge(3, 3);
	graph.add_edge(4, 3);

	graph.debug();
	graph.max_matching();

	cout << "max-matching : " << graph.matching << "\n";

	cout << "matching-ltr : ";
	for (int i = 0; i < 5; i++)
		cout << graph.matchingL[i] << " ";

	return 0;
}
