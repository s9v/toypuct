#include <bits/stdc++.h>
using namespace std;

typedef long long llint;

struct Node {
	llint val;
	bool stable;
	Node *prev;
	Node *next;

	Node() {}
	// Node(val, stable, prev, next) : val(val), stable(stable) prev(prev), next(next) {}
};

int n, k;

int dummyNodesSize = 0;
Node dummyNodes[100100];

Node *newNode(llint val) {
	Node *dummyNode = &dummyNodes[dummyNodesSize++];

	dummyNode->val = val;
	dummyNode->stable = true;
	dummyNode->prev = NULL;
	dummyNode->next = NULL;

	return dummyNode;
}

void insertc(Node *a, Node *b, Node *c) {
	a->next = c;
	c->prev = a;

	b->prev = c;
	c->next = b;
}

void unbind(Node *x) {
	x->prev->next = x->next;
	x->next->prev = x->prev;

	x->next = NULL;
	x->prev = NULL;
}

Node *dbegin;
Node *dend;

llint c[100100];

int main(){
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i) {
		scanf("%lld", &c[i]);
	}

	sort(c, c+n);

	dbegin = newNode(LLONG_MIN);
	dend = newNode(LLONG_MAX);

	Node *last = dbegin;

	for (int i = 0; i < n; ++i) {
		Node *node = newNode(c[i]);
		insertc(last, dend, node);
		last = node;
	}
	printf("\n");

	for (int i = 0; i < k; ++i) {
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		l--;
		r--;

		Node *lnode = dbegin->next;
		for (int foo = 0; foo < l; ++foo)
			lnode = lnode->next;

		Node *rnode = lnode;
		for (int foo = 0; foo <= r-l; ++foo) {
			rnode->val = rnode->val + x;
			rnode->stable = false;

			rnode = rnode->next;
		}

		/*{
			printf("+ ");
			Node *node = dbegin->next;

			while (node != dend) {
				printf("%lld ", node->val);
				node = node->next;
			}

			printf("\n");
		}*/

		if (x > 0) {
			Node *anode = lnode;
			Node *bnode = rnode;

			while (anode->stable == false) {
				Node *anodenext = anode->next;

				while (true) {
					if (anode->val <= bnode->val) {
						unbind(anode);
						insertc(bnode->prev, bnode, anode);
						break;
					}

					bnode = bnode->next;
				}

				anode->stable = true;
				anode = anodenext;
			}
		}
		else {
			Node *anode = rnode->prev;
			Node *bnode = lnode->prev;

			while (anode->stable == false) {
				Node *anodeprev = anode->prev;

				while (true) {
					if (bnode->val <= anode->val) {
						unbind(anode);
						insertc(bnode, bnode->next, anode);
						break;
					}

					bnode = bnode->prev;
				}

				anode->stable = true;
				anode = anodeprev;
			}
		}

		/*{
			printf("> ");
			Node *node = dbegin->next;

			while (node != dend) {
				printf("%lld ", node->val);
				node = node->next;
			}

			printf("\n\n");
		}*/
	}

	Node *node = dbegin->next;

	while (node != dend) {
		printf("%lld ", node->val);
		node = node->next;
	}

	return 0;
}