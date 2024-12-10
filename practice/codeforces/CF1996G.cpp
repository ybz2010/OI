#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rnd(time(0));
int n,m;
void solve()
{
    cin >> n >> m;
    vector<unsigned int>hsh(n + 5,0);
    gp_hash_table<unsigned int,int>mp;
    int l,r;
    while (m--)
    {
        cin >> l >> r;
        int tmp = rnd();
        hsh[l] ^= tmp;
        hsh[r] ^= tmp;
    }
    for (int i = 1; i <= n; i++)
    {
        hsh[i] ^= hsh[i - 1];
        mp[hsh[i]] ++;
    }
    int ans = 0;
    for (auto i : mp)
        ans = max(ans,i.second);
    cout << n - ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}