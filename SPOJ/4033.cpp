// 4033. Phone List

#include <iostream>
#include <cassert>
#define  sz(S)    (int)S.size()
using namespace std;

struct node {
	int words;
	node *children[10];
	
	node() {
		words = 0;
		for (int i = 0; i < 10; i++)
			children[i] = NULL;
	}
};

int t;
int n;
node *root;
string s[10000];

bool trie_fail(string s) {
	node *cur = root;
	bool fail = 0;
	
	for (int i = 0; i < sz(s); i++) {
		int dgt = s[i] - '0';
		
		if (cur->words > 0)
			fail = 1;
		
		assert(cur->children[dgt] != NULL);
		cur = cur->children[dgt];
	}
	
	return fail;
}

void trie_insert(string s) {
	node *cur = root;
	
	for (int i = 0; i < sz(s); i++) {
		int dgt = s[i] - '0';
		
		if (cur->children[dgt] == NULL)
			cur->children[dgt] = new node();
		cur = cur->children[dgt];
	}
	
	cur->words++;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		root = new node();
		
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			trie_insert(s[i]);
		}
		
		bool fail = 0;
		for (int i = 0; i < n; i++)
			if (trie_fail(s[i])) {
				fail = 1;
				break;
			}
		
		cout << (fail ?"NO" :"YES") << "\n";
	}
	
	return 0;
}
