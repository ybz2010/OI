#include<bits/extc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int max1[maxn],dp[maxn][105];
vector<pair<int,int> >a,b;
deque<int>q[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if (m > n)
    {
        cout << "0";
        return 0;
    }
    a.resize(n + 1,{0,0});
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin() + 1,a.end());
    b.push_back({0,0});
    for (int i = 1; i <= n; i++)
    {
        static int lst(0);
        if (lst < a[i].second)
        {
            b.push_back(a[i]);
            lst = a[i].second;
        }
        else
            m --;
    }
    m = max(m,0);
    b.push_back({inf,inf});
    n = b.size() - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= min(m,i - 1); j++)
        {
            int pos = i - j - 1;
            while (!q[pos].empty() && b[q[pos].front()].second < b[i].first)
            {
                max1[pos] = max(max1[pos],dp[q[pos].front()][q[pos].front() - pos]);
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
    cout << dp[n][m];
    return 0;   
}