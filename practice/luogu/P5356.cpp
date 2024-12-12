#include<bits/stdc++.h>
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
int const maxn=1e5+5;
int n,m,len,blo;
int a[maxn],id[maxn];
int lazy[maxn];
vector<int>blk[maxn];
int read()
{
    int ret=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){f=(ch=='-'?-1:1);ch=getchar();}
    while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}
void init()
{
    len=450;
    for(int i=1;i<=n;i++)
    {
        id[i]=(i-1)/len+1;
        blk[id[i]].push_back(a[i]);
    }
    blo=id[n];
    for(int i=1;i<=blo;i++)
        sort(blk[i].begin(),blk[i].end());
}
void upd(int id)//同一个块里的
{
    int st=(id-1)*len+1;
    int en=min(n,id*len);
    blk[id].clear();
    for(int i=st;i<=en;i++)
        blk[id].push_back(a[i]);
    sort(blk[id].begin(),blk[id].end());
}
void add(int l,int r,int val)
{
    int lid=id[l];
    int rid=id[r];
    if(lid==rid)
    {
        for(int i=l;i<=r;i++)
            a[i]+=val;
        upd(lid);
        return;
    }
    for(int i=l;id[i]==lid;i++)
        a[i]+=val;
    upd(lid);
    for(int i=r;id[i]==rid;i--) 
        a[i]+=val;
    upd(rid);
    for(int i=lid+1;i<=rid-1;i++)
        lazy[i]+=val;
}
int check(int l,int r,int x)
{
    int lid=id[l];
    int rid=id[r];
    int ret=0;
    if(lid==rid)
    {
        for(int i=l;i<=r;i++)   
            ret+=(a[i]+lazy[lid]<=x);
        return ret;
    }
    for(int i=l;id[i]==lid;i++)
        ret+=(a[i]+lazy[lid]<=x);
    for(int i=r;id[i]==rid;i--)
        ret+=(a[i]+lazy[rid]<=x);
    for(int i=lid+1;i<=rid-1;i++)
    {
        if(blk[i].front()+lazy[i]>x)
            continue;
        if(blk[i].back()+lazy[i]<=x)
        {
            ret+=len;
            continue;
        }
        ret+=upper_bound(blk[i].begin(),blk[i].end(),x-lazy[i])-blk[i].begin();
    }
    return ret;
}
int _min(int l,int r)
{
    int ret=inf;
    int lid=id[l];
    int rid=id[r];
    if(lid==rid)
    {
        for(int i=l;i<=r;i++)
            ret=min(ret,a[i]+lazy[lid]);
        return ret;
    }
    for(int i=l;id[i]==lid;i++)
        ret=min(ret,a[i]+lazy[lid]);
    for(int i=r;id[i]==rid;i--)
        ret=min(ret,a[i]+lazy[rid]);
    for(int i=lid+1;i<=rid-1;i++)
        ret=min(ret,blk[i].front()+lazy[i]);
    return ret;
}
int _max(int l,int r)
{
    int ret=-inf;
    int lid=id[l];
    int rid=id[r];
    if(lid==rid)
    {
        for(int i=l;i<=r;i++)
            ret=max(ret,a[i]+lazy[lid]);
        return ret;
    }
    for(int i=l;id[i]==lid;i++)
        ret=max(ret,a[i]+lazy[lid]);
    for(int i=r;id[i]==rid;i--)
        ret=max(ret,a[i]+lazy[rid]);
    for(int i=lid+1;i<=rid-1;i++)
        ret=max(ret,blk[i].back()+lazy[i]);
    return ret;
}
int query(int ql,int qr,int k)
{
    if(k<1||k>qr-ql+1)
        return -1;
    int l=_min(ql,qr);
    int r=_max(ql,qr);
    int ret=-1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        int tmp=check(ql,qr,mid);
        tmp>=k?ret=mid,r=mid-1:l=mid+1;
    }
    return ret;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    init();
    int op,l,r,val;
    while(m--)
    {
        scanf("%lld%lld%lld%lld",&op,&l,&r,&val);
        if(op==1)
            printf("%lld\n",query(l,r,val));
        else
            add(l,r,val);
    }
    return 0;
}