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

void solve() {
	int n;
	cin >> n;
	vi p(n);
	vi prefix(n + 1);
	prefix[0] = 0;
	REP(i, 0, n - 1) {
		cin >> p[i];
		prefix[i + 1] = prefix[i] + p[i];
	}
	int ans = 0;
	REP(i, 0, n - 1) {
		REP(j, i, n - 1) {
			int sum = prefix[j + 1] - prefix[i];
			// debug(sum)
			if (sum % (j + 1 - i) == 0) {
				int avg = sum / (j + 1 - i);
				// debug(avg)
				// debug(i)
				// debug(j)
				REP(k, i, j) {
					if (p[k] == avg) {
						ans++;
						break;
					}
				}
			}
		}
	}
	cout << ans;
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
