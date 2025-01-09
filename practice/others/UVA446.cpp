#include <bits/stdc++.h>
using namespace std;
char ch; 
int a,b,t; 
int main()
{
    cin >> t;
	while(t --) 
    {
        scanf("%x%s%x",&a,&ch,&b);
        cout << bitset<13>(a) << ' ' << ch << ' ' << bitset<13>(b) << " = " << (ch ^ 45 ? a + b : a - b) << endl;
    }
}