#include<bits/extc++.h>
#define int long long
// #define LOCAL
using namespace std;
const int maxn = 1e6 + 5;
int n,sum;
int a[maxn];
void read(int &x)
{
    x = 0;
    short f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
signed main()
{
    #ifdef LOCAL
    freopen("average6.in","r",stdin);
    freopen("out.txt","w",stdout); 
    #endif
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        sum += a[i];
    }
    sort(a + 1,a + n + 1);
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        int avg = floor(float(sum) / i);
        int pos = upper_bound(a + 1,a + i + 1,avg) - a;
        ans = max(ans,i - pos + 1);
        sum -= a[i];
    }
    cout << ans;
    return 0;
}