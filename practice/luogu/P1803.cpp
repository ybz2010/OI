#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n;
struct node{int l,r;}a[maxn];
bool operator<(node x,node y){return x.r ^ y.r ? x.r < y.r : x.l < y.l;}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].l >> a[i].r;
    sort(a + 1,a + n + 1);
    int lst = a[1].r,sum = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].l >= lst)
        {
            sum ++;
            lst = a[i].r;
        }
    }
    cout << sum;
    return 0;
}