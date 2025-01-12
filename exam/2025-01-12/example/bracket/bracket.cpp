// 什么部诗人题目啊
// 取模放求和里面
#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define local 0
using namespace std;
const int maxn = 1e7 + 5;
const int mod = 1e9 + 7;
int n;
int up[maxn],p[maxn];
int a[maxn],b[maxn],ans[maxn];
char s[maxn];
signed main()
{
    #if local
    freopen("ex_bracket2.in","r",stdin);
    freopen("ex_bracket2.out","w",stdout);
    #endif
    scanf("%s",s + 1);
    n = strlen(s + 1);
    stack<int>st;
    // bool fl = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
        {
            up[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }
        else if (!st.empty())
        {
            p[st.top()] = i;
            p[i] = st.top();
            st.pop();
        }
    }
    for (int i = 1; i <= n; i++)
        if (p[i] && s[i] == ')')
            b[i] = b[p[i] - 1] + 1;
    for (int i = n; i >= 1; i--)
        if (p[i] && s[i] == '(')
            a[i] = a[p[i] + 1] + 1;
    for (int i = 1; i <= n; i++)
    {
        if (!p[i] || s[i] == ')')
            continue;
        ans[i] = a[i] * b[p[i]] % mod;
        if (up[i])
            ans[i] = (ans[i] + ans[up[i]]) % mod;
        ans[p[i]] = ans[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += ans[i] * i % mod;
    cout << sum;
    return 0;
}
// 1 1 1 1
// 4 