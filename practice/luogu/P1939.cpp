#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n;
struct mat
{
    int a[3][3];
    mat(int x = 0)
    {
        memset(a,0,sizeof a);
        a[0][0] = a[1][1] = a[2][2] = x;
    }
    int *operator[](int x){return a[x];}
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    ret[i][j] = (ret[i][j] + x[i][k] * y[k][j] % mod) % mod;
        return ret;
    }
}base,origin;
template<typename type>
type binpow(type x,int y)
{
    type ret(1);
    while (y)
    {
        if (y & 1)
            ret = ret * x;
        x = x * x;
        y >>= 1;
    }
    return ret;
}
void mian()
{
    cin >> n;
    base = origin = mat();
    base[0][0] = base[0][2] = base[1][0] = base[2][1] = 1;
    origin[0][0] = origin[1][0] = origin[2][0] = 1;
    base = binpow(base,n - 1);
    origin = origin * base;
    cout << origin[1][0] << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        mian();
    return 0;
}