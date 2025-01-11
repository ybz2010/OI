#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1000 + 5;
const int mod = 1e9 + 7;
int h,w;
char ch;
int dp[maxn][maxn];
signed main()
{
    scanf("%lld%lld",&h,&w);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> ch;
            if (i == 1 && j == 1)
                dp[1][1] = 1;
            else if (ch == '.')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    printf("%lld",dp[h][w]);
    return 0;
}