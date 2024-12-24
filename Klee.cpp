#include<bits/extc++.h>
using namespace std;
int n;
signed main()
{
    cin >> n;
    srand(time(0));
    for (int i = 1; i <= n; i++)
    {
        cout << (rand() & 1 ? "-" : "") << 1 << " ";
    }
    return 0;
}