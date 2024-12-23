#include<bits/extc++.h>
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
const int maxn = 1e5 + 5;
int n,wei;
int a[maxn],pre[maxn];
int dp[maxn],cnt[maxn];
deque<int>q;
struct 世界树上最纯净的枝丫
{
    int l,r,min1,max1;
}tree[maxn << 2];
void push_up(int rt)
{
    tree[rt].max1 = max(tree[rt << 1].max1,tree[rt << 1 | 1].max1);
    tree[rt].min1 = min(tree[rt << 1].min1,tree[rt << 1 | 1].min1);
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if (l == r)
    {
        tree[rt].min1 = tree[rt].max1 = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l,mid,rt << 1);
    build(mid + 1,r,rt << 1 | 1);
    push_up(rt);
}
int querymin(int ql,int qr,int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].min1;
    int mid = l + r >> 1;
    int ret = inf;
    if (ql <= mid)
        ret = min(ret,querymin(ql,qr,rt << 1));
    if (qr > mid)
        ret = min(ret,querymin(ql,qr,rt << 1 | 1));
    return ret;
}
int querymax(int ql,int qr,int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].max1;
    int mid = l + r >> 1;
    int ret = -inf;
    if (ql <= mid)
        ret = max(ret,querymax(ql,qr,rt << 1));
    if (qr > mid)
        ret = max(ret,querymax(ql,qr,rt << 1 | 1));
    return ret;
}
int cost(int l,int r)
{
    if (l > r)
        return 0;
    return querymax(l,r,1) - querymin(l,r,1);
}
signed main()
{
    scanf("%lld%lld",&n,&wei);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%lld",a + i);
        pre[i] = pre[i - 1] + a[i];
    }
    build(1,n,1);
    dp[0] = pre[n];
    q.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && pre[i] - pre[q.front()] > wei)
            q.pop_front();
        dp[i] = inf;
        for (auto j : q)
        {
            int x = cost(j + 1,i);
            if (dp[j] + x + pre[n] - pre[i] < dp[i])
            {
                dp[i] = dp[j] + x + pre[n] - pre[i];
                cnt[i] = cnt[j] + 1;
            }
        }
        while (!q.empty() && dp[i] <= dp[q.back()])
            q.pop_back();
        while (!q.empty() && cnt[q.front()] < cnt[i] - 1)
            q.pop_front();
        q.push_back(i);
    }
    cout << dp[n];
    return 0;
}