#include <bits/stdc++.h>
using namespace std;

#define sz(arr) ((int) arr.size())
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;

int dirx[4] = {0, -1, 1, 0};
int diry[4] = {-1, 0, 0, 1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

const string ABC = "abcdefghijklmnopqrstuvwxyz";
const char ln = '\n';

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

vl p;
bitset<1000010> bs;
void sieve(ll n){
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i<=n; i++){
        if (bs[i]){
            for (ll j=i*i; j<=n; j+=i) bs[j] = 0;
            p.push_back(i);
        }
    }
}

ll div(ll n){
    ll ans = 1LL;
    for (ll i = 0; i<sz(p) && p[i]*p[i]<=n; i++){
        ll e = 1;
        while(n % p[i] == 0){
            e++;
            n /= p[i];
        }
        ans *= e;
    }
    if (n != 1) ans*= 2LL;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    sieve(1e6);
    int t; cin >> t;

    while (t--){
        ll a, b; cin >> a >> b;
        ll g = gcd(a, b);
        cout << div(g) << "\n";
    }
    
    return 0;
}