#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
char s[700],c;
int n,l,r,w,ans;
int main() {
    scanf("%d%s",&n,s);
    memcpy(s+n,s,n);
    for (int i=0; i<n<<1; i++)
        if (s[i]=='w') w++,r++;
            else if (s[i]==c) w=0,r++;
                else ans=max(ans,l+r),l=r-w,r=w+1,w=0,c=s[i];
    printf("%d",min(max(ans,l+r),n));
}