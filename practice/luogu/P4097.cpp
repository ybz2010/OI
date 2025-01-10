#include<cstdio>
#include<utility>
#include<algorithm>
#define int long long
using namespace std;
typedef long double ld;
typedef pair<long double,int> pdi;
const int mod1 = 39989;
const int mod2 = 1e9;
const int maxn = 40000;
const ld eps = 1e-10;
int n,rt,cnt,Gid;
int x0,y0,x1,y1,op,lst;
struct line
{
    ld k,b;
    int id;
    line(ld k = 0,ld b = 0,int id = 0):k(k),b(b),id(id){};
    ld f(int x){return k * x + b;}
};
struct Nahida
{
    int ls,rs;
    line ln;
    bool fl;
}tree[maxn << 2];
void upd(int ql,int qr,line ln,int l,int r,int &rt)
{
    if (!rt)
        rt = ++cnt;
    if (ql <= l && r <= qr)
    {
        ld lpos = tree[rt].ln.f(l),rpos = tree[rt].ln.f(r);
        ld lque = ln.f(l),rque = ln.f(r);
        if (!tree[rt].fl)
        {
            tree[rt].ln = ln;
            tree[rt].fl = 1;
        }
        else if (lque - lpos > eps && rque - rpos > eps)
            tree[rt].ln = ln;
        else if (lque - lpos > eps || rque - rpos > eps)
        {
            int mid = (l + r) >> 1;
            if (ln.f(mid) - tree[rt].ln.f(mid) > eps)
                swap(ln,tree[rt].ln);
            if (ln.f(l) - tree[rt].ln.f(l) > eps)
                upd(ql,qr,ln,l,mid,tree[rt].ls);
            else
                upd(ql,qr,ln,mid + 1,r,tree[rt].rs);
        }
    }
    else
    {
        int mid = (l + r) >> 1;
        if (ql <= mid)
            upd(ql,qr,ln,l,mid,tree[rt].ls);
        if (qr > mid)
            upd(ql,qr,ln,mid + 1,r,tree[rt].rs);
    }
}
pdi que(int pos,int l,int r,int rt)
{
    if (!rt)
        rt = ++cnt;
    ld ret = tree[rt].ln.f(pos);
    int id = tree[rt].ln.id;
    if (l == r)
        return {ret,id};
    int mid = (l + r) >> 1;
    pdi tmp;
    if(pos <= mid)
        tmp = que(pos,l,mid,tree[rt].ls);
    else
        tmp = que(pos,mid + 1,r,tree[rt].rs);
    if(tmp.first - ret > eps || (abs(tmp.first - ret) < eps && tmp.second < id))
        ret = tmp.first,id = tmp.second;
    return {ret,id};
}
signed main()
{
    scanf("%lld",&n);
    lst = 0;
    while (n--)
    {
        scanf("%lld%lld",&op,&x0);
        x0 = (x0 + lst - 1 + mod1) % mod1 + 1;
        if (op == 0)
            printf("%lld\n",(lst = que(x0,1,mod1,rt).second));
        else
        {
            scanf("%lld%lld%lld",&y0,&x1,&y1);
            x1 = (x1 + lst - 1 + mod1) % mod1 + 1;
            y0 = (y0 + lst - 1 + mod2) % mod2 + 1;
            y1 = (y1 + lst - 1 + mod2) % mod2 + 1;
            if(x0 > x1)
            {
                swap(x0,x1);
                swap(y0,y1);
            }
            ld k,b;
            if(x0 == x1)
                k = 0,b = max(y0,y1);
            else
            {
                k = ((ld)y0 - (ld)y1) / ((ld)x0 - (ld)x1);
                b = y1 - k * x1;
            }
            ++Gid;
            upd(x0,x1,line(k,b,Gid),1,mod1,rt);
        }
    }
    return 0;
}