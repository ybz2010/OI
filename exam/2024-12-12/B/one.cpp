#include<bits/extc++.h>
using namespace std;
constexpr int maxn(2e6 + 5);
int n,m;
int val[maxn];
bool b[maxn];
void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
signed main()
{
    read(n),read(m);
    int max1(max(n,m));
    for (int i(1); i <= max1; i++)
        val[i] = i;
    b[0] = b[1] = 1;
    for (int i(2); i * i <= max1; i++)
    {
        if (!b[i])
        {
            for (int j(i); j <= max1; j += i)
            {
                b[j] = 1;
                while (val[j] % (i * i) == 0)
                    val[j] /= (i * i);
            }
        }
    }
    int ans(0);
    for (int i(1); i <= n; i++)
        ans += floor(sqrt(1.0 * m / val[i]));
    printf("%d",ans);
    return 0;
}