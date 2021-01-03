#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define REP_REV(i,a,b) for (int i = a; i >= b; i--)
#define debug(x) cerr << #x << " is " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define pb push_back
#define rsz resize
#define f first
#define s second
#define mp make_pair

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vc = vector<char>;
using ull = unsigned long long ;
using pi = pair<int, int>;
using vl = vector<long long>;
using pl = pair<long long, long long>;
using vpl = vector<pair<long long, long long>>;
using msl = map<string, long long>;
using vvl = vector<vector<long long>>;

const ll MOD = 1e9 + 7;
const int INF = int(1e9);

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return (a * b) / gcd(a, b);
}

bool isPrime(int n) {
	if (n == 2) return true;
	for(int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
} 

unsigned long long factorial(int n) {
    const unsigned int M = MOD;
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f = (f*i) % M;  
    return f;
}

// Last digit of partial sum of Fibonacci numbers
void solve() {
	ll s, e, m = 10;
	cin >> s >> e;
	ll f1 = 0, f2 = 1, f3;
	vi c;
	REP(i, 0, 10000) {
		f3 = (f1 + f2) % m;
		c.pb(f1);
		f1 = f2 % m;
		f2 = f3 % m;
		if (sz(c) % 2 == 0 && sz(c) > 0) {
			int start = 0, mid = sz(c) / 2;
			while(mid <= sz(c) - 1 && c[start] == c[mid]) {
				start++;
				mid++;
			}
			if(mid == sz(c) && mid > 2) break;
		}
	}
	vi p(sz(c) / 2);
	REP(i, 0, sz(c) / 2 - 1) {
		p[i] = c[i];
	}
	ll indexS = s % sz(p);
	ll indexE = e % sz(p);
	ll ansS = 0, ansE = 0;
	REP(i, 0, indexS - 1) {
		ansS += p[i] % 10;
	}
	REP(i, 0, indexE) {
		ansE += p[i] % 10;
	}
	cout << ((ansE - ansS) % 10 + 10) % 10; // integers with negative dividend
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("split.in", "r", stdin);
	// freopen("split.out", "w", stdout);
	// ll t; cin >> t;
	// while (t--)
		solve();
	return 0;
}
