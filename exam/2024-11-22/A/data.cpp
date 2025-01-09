#include<bits/extc++.h>
using namespace std;
random_device seed;
mt19937 rnd(seed());
int n,m;
signed main()
{
    n = rnd() % 70 + 1,m = rnd() % 70 + 1;
    printf("%d %d\n",n,m);
    for (int i = 1; i <= n; i++)
        printf("%u ",rnd() % 1000u);
    return 0;
}