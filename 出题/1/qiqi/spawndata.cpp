#include<bits/extc++.h>
#include<windows.h>
using namespace std;
char s[50];
void tostr(int x)
{
    string str = "data.exe > data\\qiqi" + to_string(x) + ".in";
    for (int i = 0; i < str.length(); i++)
        s[i] = str[i];
}
signed main()
{
    for (int i = 11; i <= 20; i++)
    {
        srand(time(0) * clock());
        tostr(i);
        system(s);
    }
    return 0;
}