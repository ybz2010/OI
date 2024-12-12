#include <bits/stdc++.h>
// #define int long long

using namespace std;
template <typename T>
inline void read(T &x){
    T res = 0,f = 1;
    char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1;ch = getchar();}
    while(isdigit(ch)){res = (res << 1) + (res << 3) + (ch ^ 48);ch = getchar();}
    x = res * f;
}

const int maxn = 2e6 + 10;
int n,m,p[maxn],apr[maxn];
bool flag[maxn];

signed main(){
    read(n),read(m);
    int Ta = max(n,m),Tb = sqrt(Ta) + 1;
    for(int i = 1;i <= Ta;i ++) apr[i] = i;
    flag[0] = flag[1] = 1;
    for(int i = 2;i <= Tb;i ++){
        if(!flag[i]){
            for(int j = i;j <= Ta;j += i){
                flag[j] = 1;
                while(!(apr[j] % (i * i))) apr[j] /= (i * i);
            }
        }
    }
    int Answer = 0;
    for(int i = 1;i <= n;i ++)
        Answer += floor(sqrt(m / apr[i]));
    printf("%d\n",Answer);
    return 0;
}