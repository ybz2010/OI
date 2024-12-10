#include <bits/extc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;
const int maxn = 5e5 + 5;
const int maxp = 1e5 + 5;
random_device seed;
mt19937_64 rnd(seed());
int n, p, M;
ll s;
int a[maxp], b[maxp], c[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> M >> s;
    vector<ull>hsh(n + 5);
    gp_hash_table<ull,ll>mp;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        s = (s * 1103515245 + 12345) % (1LL << 31);
        c[i] = 1 + ((s / 10) % M);
        sum += c[i];
    }
    for (int i = 1; i <= p; i++)
    {
        s = (s * 1103515245 + 12345) % (1LL << 31);
        a[i] = ((s / 10) % n);
        s = (s * 1103515245 + 12345) % (1LL << 31);
        b[i] = ((s / 10) % n);
        ull tmp = rnd();
        hsh[a[i]] ^= tmp;
        hsh[b[i]] ^= tmp;
    }
    for (int i = 0; i < n; i++)
    {
        hsh[i] ^= hsh[i - 1];
        mp[hsh[i]] += c[i];
    }
    ll ans = 0;
    for (auto i : mp)
        ans = max(ans,i.second);
    cout << sum - ans;
}