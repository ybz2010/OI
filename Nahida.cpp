#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n;
bool ipr[maxn];
vector<int>pr;
void prime()
{
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
            pr.push_back(i);
        for (auto j : pr)
        {
            if (j * i > n)
                break;
            ipr[j * i] = 1;
            if (i % j == 0)
                break;
        }
    }
}
signed main()
{
    scanf("%lld",&n);
    prime();
    cout << pr.size();
    return 0;
}