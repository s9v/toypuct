#include <iostream>
using namespace std;
typedef long long llint;
const int MOD = 1000000007;

int t;
int a0;
int a1;
int a2;
int a3;
int s;

// Use 64 bits integers to avoid overflow errors during multiplication.
long modPow(long a, long x, long p) {
    //calculates a^x mod p in logarithmic time.
    long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

long modInverse(long a, long p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}
long modBinomial(long n, long k, long p) {
// calculates C(n,k) mod p (assuming p is prime).

    long numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }
    
    long denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }
    
    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}

int calculate(int k, int n) {
    return (int)( modBinomial(n+k,k+1, 1000000007) );
}

llint sack[200];

int f(int n) {
	int ret = 0;
	ret += a0;
	ret %= MOD;
	ret += a1*n;
	ret %= MOD;
	ret += a2*n*n;
	ret %= MOD;
	ret += a3*n*n*n;
	ret %= MOD;
	
	return ret;
}

int main() {
	cin >> t;
	
	while (t--) {
		cin >> a0;
		cin >> a1;
		cin >> a2;
		cin >> a3;
		
		cin >> s;
		
		fill(sack, sack+200, 0);
		
		sack[0] = ;
		for (int x = 1; x < 100; x++) {
			for (int i = 1; i <= s; i+)
				s[i+f(x)] += s[i];
		}
		
		cout << sack[s];
		
		calculate();
	}
	
	return 0;
}
