#include <cstdio>
typedef long long llint;

int t;
llint n;
int dummy;
char s[1000000];

int main() {
	scanf("%d", &t);
	
	while (t--) {
		scanf("%lld", &n);
		
		for (int i = 0; i < n; i++)
			scanf("%d", &dummy);
		
		printf("%lld\n", n*(n-1)/2);
	}
	
	return 0;
}
