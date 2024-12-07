#include<bits/stdc++.h>
// #define int long long

#include<bits/extc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
const int inf = 1e9;
int n,m,q,x[MAXN],y[MAXN],r[MAXN];
int mp[2000005],Answer;
bool flag[MAXN];
vector <int> vec;

inline void read(int &T)
{
    T = 0;
    int f = 1;
    char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1;ch = getchar();}
    while(isdigit(ch)){T = (T << 1) + (T << 3) + (ch ^ 48);ch = getchar();}
    T *= f;
}

void modify(int x,int y,int k)
{
    int val = ((k >> 1) ? -inf : -1);
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(val == -1)
        vec.push_back(x * m + y);
    mp[x * m + y] = val;
}

void Solve_flag(int x,int y,int r)
{
    for(int i = 0;i < r;i ++)
    {
        for(int j = 0;j + i < r;j ++)
        {
            modify(x + i,y + j,r - i - j);
            if(i) modify(x - i,y + j,r - i - j);
            if(j) modify(x + i,y - j,r - i - j);
            if(i && j) modify(x - i,y - j,r - i - j);
        }
    }
}

void bfs()
{
    queue <int> q;
    for(auto x : vec) q.push(x);
    while(!q.empty())
    {
        while(!q.empty())
        {
            int head = q.front(),x = head / m,y = head % m;
            q.pop();
            for(int i = 0;i < 4;i ++)
            {
                int nx = x + dx[i],ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(mp[nx * m + ny] > mp[head] + 1)
                {
                    mp[nx * m + ny] = mp[head] + 1;
                    q.push(nx * m + ny);
                }
            }
        }
    }
}

signed main()
{
    read(n),read(m),read(q);
    int lenV = 1000;
    for(int i = 0;i < n * m;i ++) mp[i] = inf;
    for(int i = 1;i <= q;i ++)
    {
        read(x[i]),x[i] --;
        read(y[i]),y[i] --;
        read(r[i]);
        if(r[i] >= n + m)
            r[i] = n + m - 1;
        if(mp[x[i] * m + y[i]] - r[i] + 1 >= 0)
        {
            flag[i] = 1;
            for(int j = i - 1;j % lenV;j --)
            {
                if(flag[j])
                {
                    if(abs(x[i] - x[j]) + abs(y[i] - y[j]) - r[i] - r[j] + 1 < 0)
                    {
                        flag[i] = 0;
                        break;
                    }
                }
            }
            if(flag[i])
            {
                Answer ++;
                Solve_flag(x[i],y[i],r[i]);
            }
        }
        if(i % lenV == 0) bfs();
    }
    printf("%d\n",Answer);
    for(int i = 1;i <= q;i ++)
    {
        if(flag[i])
            printf("%d ",i);
    }
    return 0;
}
signed main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	cout << a + b;
	return 0;
}