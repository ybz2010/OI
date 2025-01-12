// 什么部诗人题目啊
// 取模放求和里面
#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define local 0
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int n;
int p[maxn],id[maxn];
char s[maxn];
struct Nahida
{
    int val,lazy;
    int l,r;
}tree[maxn << 2];
void push_up(int rt){tree[rt].val = tree[ls].val + tree[rs].val;}
void push_down(int rt)
{
    if (!tree[rt].lazy)
        return;
    tree[ls].val += (tree[ls].r - tree[ls].l + 1) * tree[rt].lazy;
    tree[ls].lazy += tree[rt].lazy;
    tree[rs].val += (tree[rs].r - tree[rs].l + 1) * tree[rt].lazy;
    tree[rs].lazy += tree[rt].lazy;
    tree[rt].lazy = 0;
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].lazy = 0;
    if (l == r)
    {
        tree[rt].val = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        tree[rt].val += (r - l + 1) * x;
        tree[rt].lazy += x;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,ls);
    if (qr > mid)
        upd(ql,qr,x,rs);
    push_up(rt);
}
int que(int pos,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (l == r)
        return tree[rt].val;
    push_down(rt);
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return que(pos,ls);
    else
        return que(pos,rs);
}
void solve(int l,int r)
{
    int sum = 0;
    for (int i = l + 1; i <= r - 1; i = p[i] + 1)
    {
        id[i] = ++sum;
        solve(i,p[i]);
    }
    for (int i = l + 1; i <= r - 1; i = p[i] + 1)
        upd(i,p[i],id[i] * (sum - id[i] + 1));
}
signed main()
{
    #if local
    freopen("ex_bracket2.in","r",stdin);
    freopen("ex_bracket2.out","w",stdout);
    #endif
    scanf("%s",s + 1);
    n = strlen(s + 1);
    stack<int>st;
    // bool fl = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (!st.empty())
        {
            p[st.top()] = i;
            p[i] = st.top();
            st.pop();
        }
    }
    build(1,n,1);
    for (int i = 1; i <= n;)
    {
        if (p[i])
        {
            int st = i;
            while (p[i])
                i = p[i] + 1;
            solve(st - 1,i);
        }
        else
            i++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += que(i) * i % mod;
    printf("%lld",ans);
    return 0;
}
// 1 1 1 1
// 4 