#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
 
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
 
//#define inf 1<<30
 
// isupper() -> upper case check
// tolower() -> convert upper to lower case
// idx = str.find("bear", pos)) != string::npos =>substring find
// Tuple access -> get<0>(v[i])
// cmnt - ctrl []
// stoi("...") -> decimel
// istringstream ss(str) while(ss >> n)
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tpl = tuple<int, int, int>;
using pcc = pair<char, char>;
 
const ll inf = 1e18+100;
ll mod = 1e9+7;
 
int dr[] = {-1, 0, 1,  0};// up, right, down, left
int dc[] = { 0, 1, 0, -1};
 
// King moves similar to 8 direction
//int dr[] = {-1, -1, 0, 1, 1,  1, 0, -1};
//int dc[] = { 0,  1, 1, 1, 0, -1,-1, -1};
 
// Knight moves
int kr[] = {-1,  1, -2, -2, -1, 1,  2,  2};
int kc[] = {-2, -2, -1,  1,  2, 2, -1,  1};
// diagonal moves
int dgr[] = {-1, -1,  1, 1};
int dgc[] = { 1, -1, -1, 1};

/*
const int N = ;
vector<ll>prime;
bool isPrime[N];

void sieve()
{
    memset(isPrime, true, sizeof isPrime);

    for(int i=4; i<N; i+=2) 
        isPrime[i] = false;

    for(ll i=3; i < N; i += 2) {
        if(isPrime[i]) {
            for(ll j = i*i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    prime.pb(2);
    for(ll i = 3; i < N; i += 2) {
        if(isPrime[i]) {
            prime.pb(i);
        }
    }
}

bool is_pwr(int x)
{
    return x && (!(x & (x-1)));
}

ll LCM(ll a, ll b)
{
    return ((a/__gcd(a, b)))*b;
}
*/
// Find Modular Multiplicative Inverse
ll d, x, y;

void extendedEuclid(ll a, ll b)
{
    if(b == 0) {
        d = a, x = 1, y = 0;
    }else {
        extendedEuclid(b,a%b);
        ll temp = x;
        x = y;
        y = temp - (a/b)*y;
    }
}

ll modInv(ll a, ll m)
{
    extendedEuclid(a, m);
    return (x%m+m)%m;
}

ll bin_pow(ll a, ll b)
{
    if(!b) return 1;
    if(b%2) return (a*bin_pow((a*a)%mod, (b-1)/2))%mod;

    return bin_pow((a*a)%mod, b/2)%mod;
}

ll eulerTot(ll n)
{
    ll ans = n;

    for(ll i=2; i*i <= n; i++){
        if(n%i == 0) {
            while(n%i == 0) n/=i;
            ans = ans-ans/i;
        }
    }
    if(n > 1) ans = ans-ans/n;
    return ans;
}


void solve()
{  
    string str;

    while(getline(cin, str)) {

        istringstream ss(str);
        //cout << str << endl;
        ll n, e, c;

        ss >> n; ss >> e; ss >> c;

        //cout << x << " " << y << " " <<mod <<endl;
        mod = eulerTot(n);
        //printf("mod %lld\n", mod);
        ll d = modInv(e, mod);
        mod = n;
        ll ans = bin_pow(c, d);
        //ans = bin_pow(ans, e);
        //ans = bin_pow(ans, d);

        printf("%lld\n", ans);
    }

}   
 
int main()
{
    fast_io;
 
    int tt = 1;
 
    //cin >> tt;
    //string tmp;
    //getline(cin, tmp);

    while(tt--) {
        solve();
    }
 
    return 0;
}