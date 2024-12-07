#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
const int MAXN = 3e5 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f;

inline int read()
{
    int f = 1,res = 0;
    char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1;ch = getchar();}
    while(isdigit(ch)){res = (res << 1) + (res << 3) + (ch ^ 48);ch = getchar();}
    return res * f;
}

int T,n,m,a[MAXN],b[MAXN],pre[MAXN];

inline void operator += (pii &x,pii &y)
{
    if(x.first != y.first)
    {
        if(x.first > y.first) x = y;
    }
    else if((x.second += y.second) >= mod)
        x.second -= mod;
}

struct Segmentree
{
    int l,r;
    pii val;
}tree[MAXN << 2];
void push_down(int rt)
{
    if (tree[rt].val.first == inf)
        return;
    tree[rt << 1].val += tree[rt].val;
    tree[rt << 1 | 1].val += tree[rt].val;
    tree[rt].val = mkp(inf,0);
}
void build(int l,int r,int rt)
{
    tree[rt].l = l,tree[rt].r = r;
    tree[rt].val = {inf,0};
    if(l == r)
    {
        if(l == 1) 
            tree[rt].val = {0,1};
        return;
    }
    int mid = l + r >> 1;
    build(l,mid,rt << 1);
    build(mid + 1,r,rt << 1 | 1);
}
void upd(int ql,int qr,int rt,pii x)
{
    int l = tree[rt].l,r = tree[rt].r;
    if(ql <= l && qr >= r)
    {
        tree[rt].val += x;
        return;
    }
    int mid = l + r >> 1;
    push_down(rt);
    if(ql <= mid) upd(ql,qr,rt << 1,x);
    if(qr > mid) upd(ql,qr,rt << 1 | 1,x);
}

pii que(int x,int rt)
{
    int l = tree[rt].l,r = tree[rt].r;
    if(l == r) return tree[rt].val;
    int mid = l + r >> 1;
    push_down(rt);
    return que(x,rt << 1 | (x > mid));
}

signed main()
{
    T = read();
    while(T --)
    {
        pii Answer = {inf,0};
        n = read(),m = read();
        for(int i = 1;i <= n;i ++)
        {
            a[i] = read();
            pre[i] = pre[i - 1] + a[i];
        }
        for(int i = 1;i <= m;i ++) b[i] = read();
        build(1,n,1);
        for(int j = 1;j <= m;j ++)
        {
            pii tmp1;
            tmp1 = {inf,0};
            for(int i = 1;i <= n;i ++)
            {
                int pos = upper_bound(pre + i,pre + n + 1,b[j] + pre[i - 1]) - (pre);
                if(i < pos)
                {
                    pii tmp2 = que(i,1);
                    tmp2.first += m - j;
                    if(pos == n + 1)
                    {
                        tmp1 += tmp2;
                        pos --;
                    }
                    if(i < pos) upd(i + 1,pos,1,tmp2);
                }
            }
            Answer += tmp1;
        }
        if(Answer.first == inf) printf("-1\n");
        else printf("%lld %lld\n",Answer.first,Answer.second);
    }
    return 0;
}