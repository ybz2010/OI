#include <bits/stdc++.h>
using namespace std;
int main(){
	char s; int a, b, t; cin >> t;
	while(t--) scanf("%x%s%x", &a, &s, &b), cout << bitset<13>(a) << ' ' << s << ' ' << bitset<13>(b) << " = " << (s^45?a+b:a-b) << '\n';
}