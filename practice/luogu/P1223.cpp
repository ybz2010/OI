#include<bits/extc++.h>
using namespace std;
int n,cnt;
double sum;
struct node{int tim,id;}a[1005];
bool operator<(node x,node y){return x.tim < y.tim;}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].tim;
        a[i].id = i;
    }
    sort(a + 1,a + n + 1);
    cnt = n - 1;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].id << " ";
        sum += a[i].tim * (cnt--);
    }
    printf("\n%.2lf",sum / n);
    return 0;
}