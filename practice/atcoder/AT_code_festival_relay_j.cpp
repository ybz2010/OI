#include<bits/extc++.h>
#define int long long
using namespace std;
int n,k;
signed main()
{
    scanf("%lld%lld",&n,&k);
    if (n / 2 <= k)
        printf("first\n");
    else if (n & 1)
        printf("first\n");
    else
        printf("second\n");
    return 0;
}