#include <bits/stdc++.h>
#define eps 1e-4
using namespace std;
long long n = 1e18;
long double x;
int main()
{
    x = pow(n, 1 / 3.0);
    if (abs(x - ceil(x)) < eps || abs(x - floor(x)) < eps)
    {
        cout << ceil(x) << " " << floor(x) << endl;
        cout << "YES";
    }
    else
        cout << "NO";
}
