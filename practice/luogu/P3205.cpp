#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 19650827;
struct modint
{
    int val;
    modint(int val = 0):val((val + mod) % mod){};
    modint &operator=(int x){val = x;return *this;}
    modint &operator+=(modint x){val = (val + x.val) % mod;return *this;}
    friend istream &operator>>(istream &in,modint &x){in >> x.val,x.val %= mod;return in;}
    friend ostream &operator<<(ostream &out,modint x){out << x.val;return out;}
};
int n,a[1005];
modint dp[2][1005][1005];
signed main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        dp[0][i][i] = 1;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1,j = i + len - 1; j <= n; i++,j++)
        {
            if (a[i] < a[i + 1])
                dp[0][i][j] += dp[0][i + 1][j];
            if (a[i] < a[j])
                dp[0][i][j] += dp[1][i + 1][j];
            if (a[j] > a[j - 1])
                dp[1][i][j] += dp[1][i][j - 1];
            if (a[j] > a[i])
                dp[1][i][j] += dp[0][i][j - 1];
        }
    }
    cout << (dp[0][1][n] += dp[1][1][n]);
    return 0;
}
