#include <bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n;
int p[maxn];
vector<int> ec;
signed main()
{
    scanf("%lld",&n);
    ec.resize(n + 5,0);
    for (int i = 1; i < n; i++)
        scanf("%lld",&ec[i]);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int cnt = 0;
    do
    {
        for (int i = 1; i <= n; i++)
        vector<int> c(n + 5,0);
        for (int i = 1; i < n; i++)
        {
            c[i] = 0;
            for (int j = i + 1; j <= n; j++)
            {
                if (p[i] > p[j])
                {
                    swap(p[i],p[j]);
                    c[i]++;
                }
            }
        }
        if (c == ec)
            cnt ++;
    } while (next_permutation(p + 1,p + n + 1));
    cout << cnt;
    return 0;
}