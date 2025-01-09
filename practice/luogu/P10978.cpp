#include<iostream>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
int n,k;
int dp[105][16005];
struct 世界树上最纯净的枝丫{int l,p,s;}a[105];
bool operator<(const 世界树上最纯净的枝丫 &x,const 世界树上最纯净的枝丫 &y){return x.s < y.s;}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cin >> a[i].l >> a[i].p >> a[i].s;
    sort(a + 1,a + k + 1);
    for (int i = 1; i <= k; i++)
    {   
        deque<int>q;
        q.push_back(max(a[i].s - a[i].l,0ll));
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            if (j >= a[i].l + a[i].s)
                continue;
            while (!q.empty() && q.front() + a[i].l < j)
                q.pop_front();
            if (j < a[i].s)
            {
                int tmp = dp[i - 1][j] - j * a[i].p;
                while (!q.empty() && dp[i - 1][q.back()] - q.back() * a[i].p < tmp)
                    q.pop_back();
                q.push_back(j);
            }
            else
                dp[i][j] = max(dp[i][j],dp[i - 1][q.front()] + a[i].p * (j - q.front()));
        }
    }
    cout << dp[k][n];
    return 0;
}