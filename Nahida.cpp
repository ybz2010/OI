#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s1[N], s2[N], t1[N], t2[N];
int n, bel1[N], bel2[N], cnt1[N][2], cnt2[N][2];
void solve()
{
    cin >> n;
    cin >> (s1 + 1);
    cin >> (s2 + 1);
    cin >> (t1 + 1);
    cin >> (t2 + 1);
    int cnt = 0;
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    memset(bel1, 0, sizeof(bel1));
    memset(bel2, 0, sizeof(bel2));
    t1[0] = '*';
    t2[0] = '*';
    for (int i = 1; i <= n; i++)
    {
        if (t1[i] != t1[i - 1])
            bel1[i] = ++cnt;
        else
            bel1[i] = bel1[i - 1];
        cnt1[bel1[i]][s1[i] - '0']++;
    }
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (t2[i] != t2[i - 1])
            bel2[i] = ++cnt;
        else
            bel2[i] = bel2[i - 1];
        cnt2[bel2[i]][s2[i] - '0']++;
    }
    int ans = 0;
    // 判上下都固定的情况和一边固定的情况
    for (int i = 1; i <= n; i++)
    {
        if (t1[i] == '0' && t2[i] == '0')
        {
            if (s1[i] == s2[i])
                ans++;
            continue;
        }
        else if (t1[i] == '0')
        {
            if (cnt2[bel2[i]][s1[i] - '0'])
            {
                cnt2[bel2[i]][s1[i] - '0']--;
                ans++;
            }
        }
        else if (t2[i] == '0')
        {
            if (cnt1[bel1[i]][s2[i] - '0'])
            {
                cnt1[bel1[i]][s2[i] - '0']--;
                ans++;
            }
        }
    }
    // 最后判断上下都不固定的情况
    for (int i = 1; i <= n; i ++)
    {
        if (t1[i] == '1' && t2[i] == '1')
        {
            if (cnt1[bel1[i]][0] && cnt2[bel2[i]][0])
            {
                cnt1[bel1[i]][0] --;
                cnt2[bel2[i]][0] --;
                ans ++;
            }
            else if (cnt1[bel1[i]][1] && cnt2[bel2[i]][1])
            {
                cnt1[bel1[i]][1] --;
                cnt2[bel2[i]][1] --;
                ans ++;
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}