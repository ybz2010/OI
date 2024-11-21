#include<bits/extc++.h>
using namespace std;
char s[50];
void tostr(int x)
{
    string str = "qiqi.exe < data\\qiqi" + to_string(x) + ".in > data\\qiqi" + to_string(x) + ".out";
    for (int i = 0; i < str.length(); i++)
        s[i] = str[i];
}
signed main()
{
    for (int i = 1; i <= 20; i++)
    {
        tostr(i);
        int st = clock();
        system(s);
        cout << clock() - st << endl;
    }
    return 0;
}