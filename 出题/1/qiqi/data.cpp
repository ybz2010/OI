#include<bits/extc++.h>
using namespace std;
int n,m;
int mod = 1e8;
signed main()
{
    random_device rg;
    mt19937 rnd(rg());
    n = rnd() % 50001 + 450000,m = rnd() % mod;
    printf("%d %d\n",n,m);
    for (int i = 1; i <= n; i++)
        printf("%d %d\n",rnd() % mod,rnd() % mod);
    return 0;
}