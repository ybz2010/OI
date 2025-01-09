#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1005;
int n;
bool ipr[maxn];
vector<int>pr,dp;
void init()
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr.push_back(i);
        for (auto j : pr)
        {
            if (i * j > n)
                break;
            ipr[i * j] = 1;
            if (i % j == 0)
                continue;
        }
    }
}
signed main()
{
    scanf("%lld",&n);
    init();
    dp.resize(n + 5,0);
    dp[0] = 1;
    for (auto i : pr)
        for (int j = i; j <= n; j++)
            dp[j] += dp[j - i];
    cout << dp[n];
    return 0;
}