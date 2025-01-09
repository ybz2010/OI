#include<bits/extc++.h>
using namespace std;
double sum;
int n,k;
signed main()
{
    cin >> k;
    for (; sum <= k; n++,sum += 1.0 / n);
    cout << n;
    return 0;
}