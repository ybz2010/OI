#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,cnt;
int a[maxn],tmp[maxn];
void read(int &ret)
{
    ret = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){f = ch == '-' ? -1 : 1;ch = getchar();}
    while (ch >= '0' && ch <= '9'){ret = ret * 10 + ch - '0';ch = getchar();}
    ret *= f;
}
int merge(int l,int r)
{
    int mid = l + r >> 1,ret = 0;
    int u = l,v = mid + 1;
    for (int i = l; i <= r; i++)
    {
        if (v > r || (u <= mid && a[u] <= a[v]))
            tmp[i] = a[u++];
        else
        {
            tmp[i] = a[v++];
            ret += mid - u + 1;
        }
    }
    for (int i = l; i <= r; i++)
        a[i] = tmp[i];
    return ret;
}
void msort(int l,int r)
{
    if (l == r)
        return;
    int mid = l + r >> 1;
    msort(l,mid);
    msort(mid + 1,r);
    cnt += merge(l,r);
}
signed main()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    msort(1,n);
    cout << cnt;
    return 0;
}