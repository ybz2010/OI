#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <map>
#define int long long
using namespace std;
const int N = 3e5 + 10;
const int mod = 1e12;
int n;
int a[N];
map<int, int> mp;
int f[N];
vector<int> ve[N];
signed main()
{
    int T;
    scanf("%d", &T);
    int re = 0, x, op, ans = 0;
    while (T--)
    {
        scanf("%d", &n);
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            ve[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (ve[i].size() == 0)
                continue;
            if (ve[i].size() == 1)
                f[ve[i][0]] = 0;
            re = 0;
            for (int j = 0; j < ve[i].size() - 1; ++j)
            {
                x = rand() * rand() % mod * rand() % mod * rand() % mod;
                op = rand() & 1;
                if (op)
                    x = -x;
                f[ve[i][j]] = x;
                re += x;
            }
            f[ve[i][ve[i].size() - 1]] = -re;
        }
        mp.clear();
        re = 0;
        mp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            re += f[i];
            ans += mp[re];
            ++mp[re];
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n; ++i)
            ve[i].clear();
    }
    return 0;
}