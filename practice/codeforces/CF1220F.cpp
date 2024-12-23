#include<bits/extc++.h>
#pragma GCC optimize(2)
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 4e5 + 5;
int n;
int st[maxn],top;
int a[maxn],b[maxn];
int lg[maxn],f[maxn][30],dep[maxn];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
struct 世界树上最纯净的枝丫{int l,r,val,lazy;}世界树[maxn << 3];
void push_up(int rt){世界树[rt].val = max(世界树[ls].val,世界树[rs].val);}
void push_down(int rt)
{
    世界树[ls].val += 世界树[rt].lazy;
    世界树[rs].val += 世界树[rt].lazy;
    世界树[ls].lazy += 世界树[rt].lazy;
    世界树[rs].lazy += 世界树[rt].lazy;
    世界树[rt].lazy = 0;
}
void build(int l,int r,int rt)
{
    世界树[rt].l = l;
    世界树[rt].r = r;
    世界树[rt].lazy = 0;
    if (l == r)
    {
        世界树[rt].val = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int ql,int qr,int x,int rt)
{
    int l = 世界树[rt].l;
    int r = 世界树[rt].r;
    if (ql <= l && r <= qr)
    {
        世界树[rt].val += x;
        世界树[rt].lazy += x;
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
int que(int ql,int qr,int rt)
{
    int l = 世界树[rt].l;
    int r = 世界树[rt].r;
    if (ql <= l && r <= qr)
        return 世界树[rt].val;
    push_down(rt);
    int mid = (l + r) >> 1,ret = 0;
    if (ql <= mid)
        ret = max(ret,que(ql,qr,ls));
    if (qr > mid)
        ret = max(ret,que(ql,qr,rs));
    return ret;
}
#undef ls
#undef rs

int 左子树[maxn],柚子树[maxn];
void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
int get_min(int l,int r)
{
    int k = lg[r - l + 1];
    return min(f[l][k],f[r - (1 << k) + 1][k]);
}
void dfs(int u,int fa)
{
    dep[u] = dep[fa] + 1;
    if (左子树[u])
        dfs(左子树[u],u);
    if (柚子树[u])
        dfs(柚子树[u],u);
}
signed main()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            for (int j = 1,k = i; j <= n; j++,k = k % n + 1)
                b[j] = a[k];
            break;
        }
    }
    for (int i = 1; i <= n; i++)
        b[i + n] = b[i];
    lg[1] = 0;
    for (int i = 2; i <= n + n; i++)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n + n; i++)
        f[i][0] = b[i];
    for (int j = 1; j < 30; j++)
        for (int i = 1; i + (1 << (j - 1)) <= n + n; i++)
            f[i][j] = min(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
    int l = n + 1,r = n << 1;
    st[top = 1] = l;
    for (int i = l + 1; i <= r; i++)
    {
        while (top && b[st[top]] > b[i])
            top --;
        if (!top)
            左子树[i] = st[top + 1];
        else
        {
            左子树[i] = 柚子树[st[top]];
            柚子树[st[top]] = i;
        }
        st[++top] = i;
    }
    dfs(st[1],0);
    build(1,n << 1,1);
    for (int i = l; i <= r; i++)
        upd(i,i,dep[i],1);
    int ans = inf,pos = 0;
    int tmp = que(l,r,1);
    if (tmp < ans)
    {
        ans = tmp;
        pos = l;
    }
    for (int i = n; i > 1; i--)
    {
        int del = i + n;
        int tl = l,tr = r - 1,mid,tans = 0;
        while (tl <= tr)
        {
            mid = (tl + tr) >> 1;
            if (get_min(mid,r) < b[del])
            {
                tans = mid;
                tl = mid + 1;
            }
            else
                tr = mid - 1;
        }
        upd(tans + 1,del,-1,1);
        
        int ins = i;
        tl = l,tr = r - 1;
        while (tl <= tr)
        {
            mid = (tl + tr) >> 1;
            if (get_min(l,mid) < b[ins])
            {
                tans = mid;
                tr = mid - 1;
            }
            else
                tl = mid + 1;
        }
        int d = que(tans,tans,1);
        upd(ins,ins,d,1);
        upd(ins,tans - 1,1,1);

        l --,r --;
        tmp = que(l,r,1);
        if (ans > tmp)
        {
            pos = l;
            ans = tmp;
        }
    }

    tmp = b[pos];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == tmp)
        {
            cout << ans << " " << i - 1;
            break;
        }
    }
    return 0;
}