#include <bits/stdc++.h>
using namespace std;
int f[2][2010][2010], a[2010];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        f[0][i][i] = 1;
    for (int len = 1; len <= n; len++)
        for (int i = 1, j = i + len; j <= n; i++, j++)
        {
            if (a[i] < a[i + 1])
                f[0][i][j] += f[0][i + 1][j];
            if (a[i] < a[j])
                f[0][i][j] += f[1][i + 1][j];
            if (a[j] > a[j - 1])
                f[1][i][j] += f[1][i][j - 1];
            if (a[j] > a[i])
                f[1][i][j] += f[0][i][j - 1];
            f[0][i][j] %= 19650827;
            f[1][i][j] %= 19650827;
        }
    cout << (f[0][1][n] + f[1][1][n]) % 19650827;
    return 0;
}