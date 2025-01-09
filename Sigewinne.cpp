#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
const int maxn = 1e6 + 10, maxm = 610;
int prime[maxn], val[maxn], tot;
bool book[maxn];
vector<int> v[maxn];
map<vector<int>, vector<int>> mp;
signed main()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!book[i])
        {
            prime[++tot] = i;
            val[i] = i;
        }
        for (int j = 1; j <= tot && prime[j] * i < maxn; j++)
        {
            book[i * prime[j]] = 1;
            val[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = 2; i < maxn; i++)
    {
        v[i] = v[i / val[i]];
        if (val[i] == val[i / val[i]])
            v[i].back()++;
        else
            v[i].push_back(2);
    }
    for (int i = 2; i < maxn; i++)
        sort(v[i].begin(), v[i].end(), greater<int>());

    // auto &tmp1 = mp[v[1]];
    mp[v[1]].resize(maxm);
    mp[v[1]][1] = 0;
    for (int i = 2; i < maxm; i++)
        mp[v[1]][i] = mp[v[1]][i / val[i]] + val[i] - 1;

    for (int i = 2; i < maxn; i++)
    {
        if (!mp.count(v[i]))
        {
            auto tmp = v[i];
            tmp.pop_back();
            mp[v[i]].resize(maxm);
            for (int j = 1; j < maxm; j++)
                mp[v[i]][j] = mp[tmp][j] + v[i].back() - 1;
            for (int j = 1; j < maxm; j++)
                for (int k = 2; j * k < maxm; k++)
                    mp[v[i]][j * k] = min(mp[v[i]][j * k], min(mp[tmp][j] + abs(v[i].back() - k), mp[v[i]][j] + k - 1));
        }
    }
    for (int i = read(); i; i--)
    {
        int tmp2 = read(), tmp1 = read();
        int ans = 0x3f3f3f3f;
        auto &x = mp[v[tmp2]], &y = mp[v[tmp1]];
        for (int j = 1; j < maxm; j++)
            ans = min(ans, x[j] + y[j]);
        printf("%d\n", ans);
    }
    return 0;
}