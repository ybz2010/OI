#include<bits/extc++.h>
#define int long long
#define inf 1e18 + 114514
#define maxn (int)2e7 + 5
using namespace std;
int q,x,y,cnt;
int ls[maxn],rs[maxn],val[maxn];
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
int que(int rt,int l,int r,int x)
{
    val[rt] --;
    if (l == r)
        return x;
    int mid = l + r >> 1;
    if (!ls[rt])
        ls[rt] = ++cnt,val[ls[rt]] = mid - l + 1;
    if (!rs[rt])
        rs[rt] = ++cnt,val[rs[rt]] = r - mid;
    if (val[ls[rt]] >= x)
        return que(ls[rt],l,mid,x);
    else
        return mid - l + 1 + que(rs[rt],mid + 1,r,x - val[ls[rt]]);    
}
signed main()
{
    scanf("%lld",&q);
    val[1] = inf;
    while (q--)
    {
        scanf("%lld%lld",&x,&y);
        int num = getnum(x,y);
        printf("%lld\n",que(1,1,inf,num));
    }
    return 0;
}