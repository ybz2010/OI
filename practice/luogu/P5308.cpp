#include<bits/extc++.h>
using namespace std;
typedef long double ld;
const int maxn = 1e5 + 5;
const ld eps = 1e-15;
int tot,n;
int q[maxn],head,tail;
ld dp[maxn],cnt[maxn];
inline ld x(int i){return (ld)1 / ld(n - i);}
inline ld y(int i){return (ld)dp[i] - (ld)i / ld(n - i);}
inline ld k(int i){return (ld)-i;}
inline ld slope(int i,int j){return (y(j) - y(i)) / (x(j) - x(i));}
bool check(ld mid)
{
    q[head = tail = 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head < tail && slope(q[head],q[head + 1]) - k(i) > -eps)
            head++;
        int j = q[head];
        dp[i] = dp[j] + ld(i - j) / ld(n - j) - mid;
        cnt[i] = cnt[j] + 1;
        while (head < tail && slope(q[tail],i) - slope(q[tail - 1],q[tail]) > -eps)
            tail--;
        q[++tail] = i;
    }
    return cnt[n] >= tot;
}
int main()
{
    scanf("%d%d",&n,&tot);
    ld l = 0,r = 2e6,mid;
    while (r - l > eps && (ld)clock() / (ld)CLOCKS_PER_SEC < 0.9)
    {
        mid = (l + r) / (ld)2;
        if (check(mid))
            l = mid + eps;
        else
            r = mid - eps;
    }
    check(l);
    printf("%.9Lf",dp[n] + 1.0 * l * tot);
    return 0;
}