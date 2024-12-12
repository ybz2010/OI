#include<bits/extc++.h>
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
const int maxn = 2e5 + 5;
int n,q;
int a[maxn];
int len,blo;
int bel[maxn],lazy[maxn],l[maxn];
void init()
{
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        bel[i] = (i - 1) / len + 1;
        if (bel[i] != bel[i - 1])
            l[bel[i]] = i;
    }
    blo = bel[n];
    for (int i = 1; i <= blo; i++)
        lazy[i] = -inf;
}
void push_down(int blk)
{
    for (int i = l[blk]; bel[i] == blk; i++)
        a[i] = max(a[i],lazy[blk]);
    lazy[blk] = -inf;
}
void upd1(int p,int x)
{
    push_down(bel[p]);
    a[p] = x;
}
void upd2(int x)
{
    for (int i = 1; i <= blo; i++)
        lazy[i] = max(lazy[i],x);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    cin >> q;
    int op,p,x;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> p >> x;
            upd1(p,x);
        }
        else
        {
            cin >> x;
            upd2(x);
        }
    }
    for (int i = 1; i <= blo; i++)
        push_down(i);
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}
//你觉得这个代码很屎山吗
//没事，我也觉得