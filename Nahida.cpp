#include<bits/stdc++.h>

using namespace std;

int n, m, mapp[105], cnt = 0, f[105][105][105];

struct point 
{
    int s, num;
}a[105];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            mapp[i] = (mapp[i] << 1) + (c == 'P');
        }
    for(int i = 0; i < (1 << m); i++)
    {
        if((i & (i << 1)) || (i & (i << 2)) || (i & (i >> 1)) || (i & (i >> 2))) continue;
        cnt++;
        a[cnt].s = i;
		a[cnt].num = __popcount(i);
        if((i & mapp[1]) == i) f[1][0][cnt] = a[cnt].num;
    }
    cout << cnt << endl; //这个是预处理后的个数
    for(int i = 1; i <= cnt; i++)
        for(int j = 1; j <= cnt; j++)
            if(!(a[i].s & a[j].s) && (mapp[2] & a[j].s) == a[j].s) f[2][i][j] = f[1][0][i] + a[j].num;
    for(int i = 3; i <= n; i++)
        for(int j = 1; j <= cnt; j++)
            if((mapp[i] & a[j].s) == a[j].s) 
                for(int k = 1; k <= cnt; k++)
                    if(!(a[j].s & a[k].s))
                        for(int l = 1; l <= cnt; l++)
                            if(!(a[k].s & a[l].s) && !(a[j].s & a[l].s))
								f[i][k][j] = max(f[i][k][j], f[i - 1][l][k] + a[j].num);
    int ans = 0;
    for(int i = 1; i <= cnt; i++)
        for(int j = 1; j <= cnt; j++) ans = max(ans, f[n][i][j]);
    printf("%d\n", ans);
    return 0;
}