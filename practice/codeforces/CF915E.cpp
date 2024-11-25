#include<stdio.h>
const int maxn = 3e5 + 5;
int n,q,cnt,rt;
struct Nahida
{
    int val,lazy,ls,rs;
    Nahida(){lazy = -1;};
}tree[maxn * 55];
inline int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
void write(int x)
{
    if(x > 9) write(x / 10);
    if(x < 0) x = -x,putchar('-');
    putchar(x % 10 + '0');
}
inline void push_up(int rt)
{
    tree[rt].val = tree[tree[rt].ls].val + tree[tree[rt].rs].val;
}
inline void push_down(int rt,int l,int r)
{
    if (tree[rt].lazy != -1)
    {
        int mid = l + r >> 1;
        if (!tree[rt].ls)
            tree[rt].ls = ++cnt;
        if (!tree[rt].rs)
            tree[rt].rs = ++cnt;
        tree[tree[rt].ls].lazy = tree[rt].lazy;
        tree[tree[rt].rs].lazy = tree[rt].lazy;
        tree[tree[rt].ls].val = tree[rt].lazy * (mid - l + 1);
        tree[tree[rt].rs].val = tree[rt].lazy * (r - mid);
        tree[rt].lazy = -1;
    }
}
void upd(int ql,int qr,int x,int l,int r,int &rt)
{
    if (!rt)
        rt = ++cnt;
    if (ql <= l && r <= qr)
    {
        tree[rt].val = x * (r - l + 1);
        tree[rt].lazy = x;
        return;
    }
    push_down(rt,l,r);
    int mid = l + r >> 1;
    if (ql <= mid)
        upd(ql,qr,x,l,mid,tree[rt].ls);
    if (qr > mid)
        upd(ql,qr,x,mid + 1,r,tree[rt].rs);
    push_up(rt);
}
signed main()
{
    n = read(),q = read();
    int l,r,op;
    for (int i = 1; i <= q; i ++)
    {
        l = read(),r = read(),op = read();
        if (op == 1)
            upd(l,r,1,1,n,rt);
        else
            upd(l,r,0,1,n,rt);
        write(n - tree[rt].val);
        putchar('\n');
    }
    return 0;
}