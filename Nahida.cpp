#include <bits/stdc++.h>
using namespace std;
int n, m, k, ch[500001][3], tot = 1, bo[500001], sum[500001], x;
bool p[500001];
/// ch[u][i]表示节点u的i字符指针指向的节点，若值为0，表示没有这个节点
inline int read()
{
    int data = 0, w = 1;
    char ch = 0;
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = getchar();
    if (ch == '-')
        w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        data = data * 10 + ch - '0', ch = getchar();
    return data * w;
} /// 快读

void add(bool a[])
{ // 插入字符串
    int u = 1;
    for (int i = 1; i <= k; i++)
    {
        int c = a[i];
        if (ch[u][c] == -1)
            ch[u][c] = ++tot;
        u = ch[u][c]; /// 它指向它的子节点
        sum[u]++;     /// 经过该节点字符串个数
    }
    bo[u]++; /// 该字符串以u结尾
}

int find(bool a[])
{
    int u = 1;
    int res = 0;
    for (int i = 1; i <= k; i++)
    {
        int c = a[i];
        if (ch[u][c] == -1)
            return res;
        u = ch[u][c];
        res += bo[u]; /// 加上与当前节点为结束的个数
    }
    return res - bo[u] + sum[u]; // 加上前缀相同且长度比它长的字符串个数
}

int main()
{
    int x;
    m = read();
    n = read();
    memset(ch, -1, sizeof ch); // 因为输入为0或1，所以初始值为-1
    for (int i = 1; i <= m; i++)
    {
        k = read();
        for (int j = 1; j <= k; j++)
        {
            p[i] = read();
        }
        add(p);
    }
    for (int i = 1; i <= n; i++)
    {
        k = read();
        for (int j = 1; j <= k; j++)
        {
            p[j] = read();
        }
        printf("%d\n", find(p));
    }
}