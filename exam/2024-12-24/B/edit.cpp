#include<bits/extc++.h>
using namespace std;
int n,q,m;
int f[(1 << 20) + 5],dp[65][(1 << 20) + 5];
int calc(int x){return (x >> 1) + ((x & 1) << (n - 1));}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q >> n;
    memset(f,-1,sizeof f);
    for (int i = 0; i < (1 << n); i++)
    {
        if (~f[i])
            continue;
        int x = i;
        while (!(~f[x]))
        {
            f[x] = i;
            x = calc(x);
        }
    }
    dp[0][0] = 1;
    for (int i = 1,x = 0; i <= n * 3; i++)
    {
        x ^= 1 << (i - 1) % n;
        for (int j = 0; j < (1 << n); j++)
            dp[i][f[j]] |= dp[i - 1][f[j ^ x]];
    }
    while (q--)
    {
        int a,b;
        char ch;
        a = b = 0;
        for (int i = n - 1; ~i; i--)
        {
            cin >> ch;
            a |= (ch == '1') << i;
        }
        for (int i = n - 1; ~i; i--)
        {
            cin >> ch;
            b |= (ch == '1') << i;
        }
        if (!a)
            cout << "0\n";
        else
        {
            for (int i = 1; ; i++)
            {
                a ^= b;
                if (dp[i][f[a]])
                {
                    cout << i << endl;
                    break;
                }
                b = calc(b);
            }
        }
    }
    return 0;
}