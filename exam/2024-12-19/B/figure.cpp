#include<bits/extc++.h>
#define int long long
#define eps 1e-4
using namespace std;
using namespace __gnu_pbds;
int m,q;
int t[505];
gp_hash_table<int,int>val,cnt;
struct node{int cnt,val;};
bool operator<(node x,node y){return x.cnt ^ y.cnt ? x.cnt > y.cnt : x.val < y.val;}
set<node>st;
bool check(int x)
{
    double y = pow(x,1.0 / 3);
    return abs(y - ceil(y)) < eps || abs(y - floor(y)) < eps;
}
int calc(int x)
{
    int ret = 1;
    for (int i = 1; i <= m; i++)
    {
        int c = 0;
        while (x % t[i] == 0)
        {
            x /= t[i];
            c ++;
        }
        if (c % 3 == 1)
            ret *= t[i] * t[i];
        else if (c % 3 == 2)
            ret *= t[i];
    }
    if (!check(x))
        return 0;
    return ret;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> t[i];
    cin >> q;
    int op,x;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            val[x] = calc(x);
            if (val[x] == -1)
                continue;
            st.erase({cnt[val[x]],val[x]});
            cnt[val[x]] ++;
            st.insert({cnt[val[x]],val[x]});
        }
        else if (op == 2)
        {
            cin >> x;
            val[x] = calc(x);
            if (val[x] == -1)
                continue;
            st.erase({cnt[val[x]],val[x]});
            cnt[val[x]] --;
            st.insert({cnt[val[x]],val[x]});
        }
        else
            cout << (*(st.begin())).val << endl;
    }
    return 0;
}