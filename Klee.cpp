#include <bits/stdc++.h>
using namespace std;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < 48 || ch > 57)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= 48 && ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}
int s[200001];
int sj[3001][3001];
int md(const int a)
{
    return a < 998244353 ? a : a - 998244353;
}
int main()
{
    int a, b(0);
    long long d(1);
    a = read();
    for (int v = 1; v < a; ++v)
    {
        s[v] = read();
        b = max(b, s[v]);
    }
    for (int v = 0; v <= b; ++v)
        sj[v][0] = 1;
    sj[1][1] = 2;
    for (int v = 2; v <= b; ++v)
    {
        sj[v][1] = v + 1;
        sj[v][v] = v + 1;
        for (int var = 2; var < v; ++var)
            sj[v][var] = md(sj[v - 1][var] + sj[v - 1][var - 1]);
    }
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j < i; j++)
            cout << sj[i][j] << " ";
        cout << endl;
    }
        
    for (int v = a; v; --v)
        if (s[v - 1] <= s[v])
            d = d * sj[s[v]][s[v - 1]] % 998244353;
    cout << d;
    return 0;
}