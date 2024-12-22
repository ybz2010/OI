#include<bits/extc++.h>
using namespace std;
random_device seed;
mt19937 rnd(seed());
int n = 2e5;
signed main()
{
    freopen("data.txt","w",stdout);
    cout << n << endl;
    for (int i = 1; i <= n; i++)
        cout << rnd() % (unsigned int)1e9 + 1 << " ";
    return 0;
}