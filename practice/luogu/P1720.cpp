#include<bits/extc++.h>
using namespace std;
int n;
signed main()
{
    scanf("%d",&n);
    double x1 = (1.0 + sqrt(5.0)) / 2.0;
    double x2 = (1.0 - sqrt(5.0)) / 2.0;
    double f = (pow(x1,n) - pow(x2,n)) / sqrt(5.0);
    printf("%.2lf",f);
    return 0;
}