#include<bits/extc++.h>
#define int long long
using namespace std;
int q,x;
const int maxn = 2e5 + 5;
int tr[maxn][70],id = 1,siz[maxn * 70];
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
    scanf("%lld",&q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld",&x);
        cout << find(x) << endl << endl;
        insert(x);
    }
    return 0;
}