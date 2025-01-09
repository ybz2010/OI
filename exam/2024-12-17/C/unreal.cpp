#include<bits/extc++.h>
#define dd double
#define inf 1e8
using namespace std;
const dd stt = 1e8,ent = 1e-6,d = 0.99;
const int maxn = 50005;
// random_device seed;
mt19937 rnd(0x114514);
int n;
int h[maxn],m[maxn],s[maxn];
dd ah[maxn],am[maxn],ans = inf;
void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
dd geth(int h,int m,int s){return h * 30.0 + m * 0.5 + s / 120.0;}
dd getm(int m,int s){return m * 6.0 + s / 10.0;}
dd cost(int h,int m,int s)
{
    dd tah = geth(h,m,s);
    dd tam = getm(m,s);
    dd ret = -inf;
    for (int i = 1; i <= n; i++)
    {
        ret = max(ret,min(abs(tah - ah[i]),abs(abs(tah - ah[i]) - 360)));
        ret = max(ret,min(abs(tam - am[i]),abs(abs(tam - am[i]) - 360)));
    }
    return ret;
}
void SA()
{
    dd tmp = stt;
    while (tmp > ent)
    {
        int nh = rnd() % 12,nm = rnd() % 60,ns = rnd() % 60;
        dd nans = cost(nh,nm,ns);
        dd delta = nans - ans;
        if (exp(-delta / tmp) > rnd())
            ans = nans;
        tmp *= d;
    }
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        read(h[i]),read(m[i]),read(s[i]);
        h[i] %= 12;
        ah[i] = geth(h[i],m[i],s[i]);
        am[i] = getm(m[i],s[i]);
    }
    while (clock() < 900)
        SA();
    printf("%.6lf",ans);
    return 0;
}