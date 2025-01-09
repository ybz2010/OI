#include <bits/stdc++.h>
#include <unordered_map>
#define for1(a, b, i) for (int i = a; i <= b; ++i)
#define FOR2(a, b, i) for (int i = a; i >= b; --i)
#define int long long
using namespace std;
inline int read()
{
    int f = 1, sum = 0;
    char x = getchar();
    for (; (x < '0' || x > '9'); x = getchar())
        if (x == '-')
            f = -1;
    for (; x >= '0' && x <= '9'; x = getchar())
        sum = sum * 10 + x - '0';
    return f * sum;
}

#define M 3005
#define mod 76543
#define N 1000005
bool vis[N];
int sta[M], zt[N];
int A[M], dis[M][M];
int cnt, a[M][10], f[M], s[N], g[N][10];
int x_[10] = {0, 2, 3, 5, 7, 11, 13, 17, 19};

unordered_map<int, int> st;

inline void max(int &x, int y)
{
    if (x < y)
        x = y;
}
inline void min(int &x, int y)
{
    if (x > y)
        x = y;
}

inline void dfs(int x, int d, int sum)
{
    if (x == 9)
    {
        f[++cnt] = d;
        for (int i = 0; i <= 8; i++)
            a[cnt][i] = sta[i];
        int t = 0;
        for (int i = 1; i <= 8; i++)
            if (sta[i])
                t = t * mod + sta[i];
        st[t] = cnt;
        return;
    }

    for (int i = 0; i <= sta[x - 1]; i++)
    {
        sta[x] = i;
        dfs(x + 1, d * (i + 1), sum);
        sum *= x_[x];
        if (sum > 200000000)
            break;
    }
}

inline int get_(int x)
{
    int now = x;
    int b[10] = {0};
    for (int i = 1; i <= s[x]; i++)
    {
        int y = g[x][i];
        while (!(now % y))
            now /= y, ++b[i];
    }
    sort(b + 1, b + s[x] + 1);
    int t = 0;
    for (int i = s[x]; i >= 1; i--)
        t = t * mod + b[i];
    return st[t];
}

signed main()
{
    //    freopen("a.in","r",stdin);
    sta[0] = 30;
    dfs(1, 1, 1);

    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= cnt; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (a[i][j] + 1 > a[i][j - 1])
                continue;
            int x = 0;
            ++a[i][j];
            for (int k = 1; k <= 8; k++)
                 if (a[i][k]) x = x * mod + a[i][k];
            --a[i][j];
            if (st.count(x))
            {
                int t = st[x];
                dis[i][t] = dis[t][i] = 1;
            }
        }
    }

    for1(1, cnt, i)
        for1(1, cnt, j) if (dis[j][i] < 100)
            for1(1, cnt, k) if (dis[i][k] < 100)
                min(dis[j][k], dis[j][i] + dis[i][k]);

    for1(1, cnt, i)
    {
        for1(1, cnt, j) A[j] = dis[i][j], dis[i][j] = 1e9;
        for1(1, cnt, j) min(dis[i][f[j]], A[j]);
    }

    for1(2, N - 5, i)
    {
        if (s[i])
            continue;
        int x = i;
        while (x + 4 < N)
            g[x][++s[x]] = i, x += i;
    }

    int size = 0;
    for1(1, cnt, i) if (!vis[f[i]]) vis[f[i]] = 1, zt[++size] = f[i];

    int Test_ = read();
    while (Test_--)
    {
        int x = read(), y = read();
        x = get_(x), y = get_(y);
        int ans = 1e9;
        for1(1, size, i) min(ans, dis[x][zt[i]] + dis[y][zt[i]]);
        printf("%d\n", ans);
    }
}