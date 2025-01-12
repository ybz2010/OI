#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 20;
const int maxm = 1e6 + 41;
const int mod = 1e9 + 7;

int T;
int d;
std::string a;
int n;
int cnt = 20;

long long sum = 1;                      // dp[i][1] 的前缀和
long long b1[maxm], b0[maxm]; // dp[i][0] + dp[i][1] 的桶前缀和
long long dp[maxn][2];
int p, lft;
int hsh[maxn];
int maxv = 0;

inline std::string read()
{
    std::string str = "";
    char ch = getchar();
    // 处理空格、换行或回车
    while (ch == ' ' || ch == '\n' || ch == '\r')
        ch = getchar();
    // 读入
    while (ch != ' ' && ch != '\n' && ch != '\r')
    {
        str += ch;
        ch = getchar();
    }
    return str;
}

void __stdcall print(int x)
{
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
/*初始化字符串 hash*/
inline void init()
{
    maxv = 0;
    p = d, lft = 1;
    int cnt2 = 0, cnt5 = 0;
    while (!(p & 1))
        p >>= 1, lft <<= 1, ++cnt2;
    while (!(p % 5))
        p /= 5, lft *= 5, cnt5++;
    cnt = cnt2 > cnt5 ? cnt2 : cnt5;
    hsh[n + 1] = 0;
    for (int i = n, p10 = 1; i >= 1; i--, p10 = p10 * 10 % p)
        hsh[i] = (hsh[i + 1] + (a[i] - '0') * p10) % p, maxv = std::max(maxv, hsh[i]);
}
inline void solve()
{
    sum = 1;
    dp[0][1] = 1, dp[0][0] = 0;
    b0[hsh[1]] = b1[hsh[1]] = cnt == 0 ? 1 : 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = sum;
        bool fl = true;
        for (int j = 0,tmp = 0,p10 = 1; j < min(i,cnt); j++,p10 = p10 * 10 % d)
        {
            tmp = (tmp + p10 * (a[i - j] - '0')) % d;
            if (!tmp)
            {
                dp[i][0] = ((dp[i][0] - dp[i - j - 1][1]) % mod + mod) % mod;
                dp[i][1] = (dp[i][1] + dp[i - j - 1][0] + dp[i - j - 1][1]) % mod;
            }
            fl = !(tmp % lft);
        }

        /*处理 20 位以外的部分*/ 
        if (fl)
        {
            dp[i][0] = ((dp[i][0] - b0[hsh[i + 1]]) % mod + mod) % mod;
            dp[i][1] = (dp[i][1] + b1[hsh[i + 1]]) % mod;
        }
        sum = (sum + dp[i][1]) % mod;
        if (i >= cnt)
        {
            b0[hsh[i - cnt + 1]] = (b0[hsh[i - cnt + 1]] + dp[i - cnt][1]) % mod;
            b1[hsh[i - cnt + 1]] = (b1[hsh[i - cnt + 1]] + dp[i - cnt][0] + dp[i - cnt][1]) % mod;
        }
    }
    print((dp[n][1] + dp[n][0]) % mod), putchar('\n');
    for (int i = 1; i <= n; ++i)
        hsh[i] = dp[i][0] = dp[i][1] = 0;
    for (int i = 0; i <= maxv; ++i)
        b0[i] = b1[i] = 0;
}

signed main()
{
    a = read();
    scanf("%d", &d);
    n = a.size();
    a = ' ' + a;
    init();
    solve();
    return 0;
}