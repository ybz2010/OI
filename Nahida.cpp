#include <bits/stdc++.h>
#define maxn 5000010
using namespace std;
int T, n, t, f[maxn], w[maxn], dep[maxn], lson[maxn], rbro[maxn], mxu[maxn], mxv[maxn], siz[maxn], win[maxn];
bool vis[maxn];
long long a, b, ans;

inline int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}

inline void write(long long x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

void dfs(int p, bool a)
{
    vis[p] = a;
    if (siz[p] == 0)
        return;
    if (a || win[p] == 1)
    {
        for (int i = lson[p]; i; i = rbro[i])
            if (a || !win[i])
                dfs(i, !a);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    T = read();
    while (T--)
    {
        n = read();
        t = read();
        a = read();
        b = read();
        for (int i = 1; i <= n; i++)
        {
            vis[i] = dep[i] = win[i] = siz[i] = lson[i] = rbro[i] = 0;
            mxu[i] = mxv[i] = 0x3F3F3F3F;
        }
        for (int i = 2; i <= n; i++)
        {
            f[i] = read();
            dep[i] = dep[f[i]] + 1;
            rbro[i] = lson[f[i]];
            lson[f[i]] = i;
            siz[f[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            w[i] = read();
        }
        for (int i = n; i >= 1; i--)
        {
            if (!win[i])
                win[f[i]]++;
        }
        if ((win[1] != 0) ^ t)
        {
            puts("0");
            continue;
        }
        dfs(1, !t);
        ans = 0x3F3F3F3F3F3F3F3Fll;
        for (int i = n; i >= 1; i--)
        {
            if (vis[i])
                mxu[i] = min(mxu[i], w[i]);
            if (!win[i])
                mxv[i] = min(mxv[i], w[i]);
            if (siz[i])
            {
                int mmxu = mxu[lson[i]], mmxv = mxv[lson[i]];
                for (int j = rbro[lson[i]]; j; j = rbro[j])
                {
                    if (mmxu != 0x3F3F3F3F && mxv[j] != 0x3F3F3F3F)
                        ans = min(ans, a * mmxu + b * mxv[j]);
                    if (mmxv != 0x3F3F3F3F && mxu[j] != 0x3F3F3F3F)
                        ans = min(ans, a * mxu[j] + b * mmxv);
                    mmxu = min(mmxu, mxu[j]);
                    mmxv = min(mmxv, mxv[j]);
                }
                mxu[i] = min(mxu[i], mmxu);
                mxv[i] = min(mxv[i], mmxv);
                if (vis[i] && mmxv != 0x3F3F3F3F)
                    ans = min(ans, a * w[i] + b * mmxv);
            }
        }
        if (ans != 0x3F3F3F3F3F3F3F3Fll)
            write(ans), puts("");
        else
            puts("-1");
    }
    return 0;
}