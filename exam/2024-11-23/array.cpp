#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int maxn = 2e5 + 5;
int q,x,y;
int tr[maxn * 70][2],id = 1,siz[maxn * 70];
gp_hash_table<int,int>apr;
int getr(int c){return c << 1 | 1;}
int getnum(int x,int y)
{
    int c = max(abs(x),abs(y));
    int r = getr(c) - 1;
    int st = pow(getr(c - 1),2);
    if (y == c && -c + 1 <= x && x <= c)
        return st + x + c;
    else if (x == c && c - 1 >= y && y >= -c)
        return st + r + c - y;
    else if (y == -c && c - 1 >= x && x >= -c)
        return st + r * 2 + c - x;
    else 
        return st + r * 3 + y + c;
}
void insert(int x)
{
    int p = 1;
    for (int i = 63; i >= 0; i--)
    {
        int ch = (x >> i) & 1;
        if (!tr[p][ch])
            tr[p][ch] = ++id;
        p = tr[p][ch];
        siz[p] ++;
    }
}
int find(int x)
{
    int ret = 0,p = 1;
    for (int i = 63; i >= 0; i--)
    {
        int ch = (x >> i) & 1;
        if (ch)
            ret += siz[tr[p][0]];
        if (!tr[p][ch])
        {
            if (!ch)
                return 0;
            break;
        }
        p = tr[p][ch];
    }
    return ret;
}
signed main()
{
    freopen("array.in","r",stdin);
    freopen("array.out","w",stdout);
    scanf("%lld",&q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld%lld",&x,&y);
        int pos = getnum(x,y);
        int cnt = find(pos) + apr[pos];
        cout << pos + cnt << endl;
        apr[pos]++;
        insert(pos);
    }
    return 0;
}