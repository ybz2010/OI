#include<bits/extc++.h>
using namespace std;
random_device seed;
mt19937 rnd(seed());
signed main()
{
    for (int i = 1; i <= 10; i++)
        cout << (int)rnd() << endl;
    return 0;
}