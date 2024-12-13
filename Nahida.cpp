#include <bits/extc++.h>
#define first l
#define second r
using namespace std;
int n, m;
const int N = 1e5 + 5;
struct Node
{
    int l, r;
} a[N], b[N];
int dp[N][110], max1[N];
deque<int> q[N];
bool cmp(Node x, Node y)
{
    return x.l ^ y.l ? x.l < y.l : x.r < y.r;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].l, &a[i].r);
    if (m >= n)
    {
        puts("0");
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    int mx = -1, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].r > mx)
            b[++cnt] = a[i];
        else
            m--;
        mx = max(mx, a[i].r);
    }
    m = max(m, 0);
    b[++cnt].l = 1e9, b[cnt].r = 1e9;
    n = cnt;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= min(i - 1, m); j++)
        {
            int pos = i - j - 1;
            while (q[pos].size() && b[q[pos].front()].r < b[i].l)
            {
                max1[pos] = max(max1[pos], dp[q[pos].front()][q[pos].front() - pos]);
                q[pos].pop_front();
            }
            dp[i][j] = max(dp[i][j],max1[pos] + b[i].second - b[i].first);
            if (!q[pos].empty())
                dp[i][j] = max(dp[i][j],dp[q[pos].front()][q[pos].front() - pos] + b[i].second - b[q[pos].front()].second);
            pos = i - j;
            while (!q[pos].empty() && dp[q[pos].back()][q[pos].back() - pos] - b[q[pos].back()].second <= dp[i][j] - b[i].second)
                q[pos].pop_back();
            q[pos].push_back(i);
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}
//nohtyp