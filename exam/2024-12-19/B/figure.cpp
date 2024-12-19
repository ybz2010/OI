#include<bits/extc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
int m,q;
int t[505];
int cnt[505][3];
void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
signed main()
{
    read(m);
    for (int i = 1; i <= m; i++)
        read(t[i]);
    read(q);
    int x,op;
    while (q--)
    {
        read(op);
        if (op == 1)
        {
            read(x);
            for (int i = 1; i <= m; i++)
            {
                int c = 0;
                while (x % t[i] == 0)
                {
                    c ++;
                    x /= t[i];
                }
                cnt[i][c % 3] ++;
            }
            for (int i = 1; i <= m; i++)
            {
                for (int j = 0; j < 3; j++)
                    cout << cnt[i][j] << " ";
                cout << endl;
            }
        }
        else if (op == 2)
        {
            read(x);
            for (int i = 1; i <= m; i++)
            {
                int c = 0;
                while (x % t[i] == 0)
                {
                    c ++;
                    x /= t[i];
                }
                cnt[i][c % 3] --;
            }
            for (int i = 1; i <= m; i++)
            {
                for (int j = 0; j < 3; j++)
                    cout << cnt[i][j] << " ";
                cout << endl;
            }
        }
        else
        {
            int _max = -inf,ans = inf;
            for (int i = 1; i <= m; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (cnt[i][j] > _max)
                    {
                        _max = cnt[i][j];
                        ans = pow(t[i],(3 - j) % 3);
                    }
                    else if (cnt[i][j] == _max)
                        ans = min(ans,(int)pow(t[i],(3 - j) % 3));
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}