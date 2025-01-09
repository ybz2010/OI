#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,m;
int a[maxn],pre[maxn];
deque<int>q;
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",pre + i);
        pre[i] += pre[i - 1];
    }
    int ans = 0;
    q.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && q.front() < i - m)
            q.pop_front();
        ans = max(ans,pre[i] - pre[q.front()]);
        while (!q.empty() && pre[q.back()] >= pre[i])
            q.pop_back();
        q.push_back(i);
    }
    printf("%lld",ans);
    return 0;
}