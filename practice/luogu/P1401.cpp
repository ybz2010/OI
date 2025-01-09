#include<bits/extc++.h>
#define int long long
using namespace std;
int l1,r1,l2,r2;
int x[4];
signed main()
{
    scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
    x[0] = l1 * l2;
    x[1] = l1 * r2;
    x[2] = r1 * l2;
    x[3] = r1 * r2;
    for (int i = 0; i < 4; i++)
    {
        if (x[i] < INT_MIN || x[i] > INT_MAX)
        {
            cout << "long long int";
            return 0;
        }
    }
    cout << "int";
    return 0;
}