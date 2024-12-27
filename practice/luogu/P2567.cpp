#include<bits/extc++.h>
#define int __int128
#define lcm(x,y) (x == 0 ? y : x * y / __gcd(x,y))
using namespace std;
void read(int &x)
{
    x = 0;
    short f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
void write(int x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
int a,b,ans;
map<vector<int>::iterator,bool>vis;
vector<int>pending,num;
void dfs1(int x)
{
    if (x > b)
        return;
    if (x)
        pending.push_back(x);
    dfs1(x * 10 + 6);
    dfs1(x * 10 + 8);
}
void dfs2(vector<int>::iterator idx,int cnt,int x)
{
    if (x > b)
        return;
    if (idx == num.end())
    {
        if (x == 0)
            return;
        ans += (cnt & 1 ? 1 : -1) * (floor(1.0 * b / x) - ceil(1.0 * a / x) + 1);
        return;
    }
    dfs2(idx + 1,cnt + 1,lcm(x,*idx));
    dfs2(idx + 1,cnt,x);
}
signed main()
{
    read(a),read(b);
    dfs1(0);
    for (auto i = pending.begin(); i != pending.end(); i++)
    {
        if (!vis[i])
            num.push_back(*i);
        for (auto j = i + 1; j != pending.end(); j++)
            if (*j % *i == 0)
                vis[j] = 1;
    }
    sort(num.begin(),num.end(),greater<int>());
    dfs2(num.begin(),0,0);
    write(ans);
    return 0;
}