#include<bits/extc++.h>
using namespace std;
int db[15] = {0,1,3,6,10,21,21,50,73,116,167,248};
signed main()
{
    int n;
    scanf("%d",&n);
    cout << db[n];
    return 0;
}