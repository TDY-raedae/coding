#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
#include<set>
#include<cstring>
using namespace std;
vector<int> we,va;
//vector<long long> pre_n,pre_v;
vector<pair<int,int>> q;
long long pre_n[200010],pre_v[200010],Y,sum,s;
int mn=0x7fffffff,mm=-1,n,m,l[200010],r[200010],w[200010],v[200010];
bool get_y(int wt)
{
    Y=0,sum=0;
    memset(pre_n,0,sizeof(pre_n));
    memset(pre_v,0,sizeof(pre_v));
    for(int i=1;i<=n;i++)
    {
        if(w[i]>=wt) pre_n[i]=pre_n[i-1]+1,pre_v[i]=pre_v[i-1]+v[i];
        else pre_n[i]=pre_n[i-1],pre_v[i]=pre_v[i-1];
    }
    
    for(int i=1;i<=m;i++)
    {
        Y+=(pre_n[r[i]]-pre_n[l[i]-1])*(pre_v[r[i]]-pre_v[l[i]-1]);
    }
    sum=llabs(Y-s);
    if(Y>s) return true;
    else return false;
    
}
void binary_search()
{
    
}
int main()
{
    //set<int> a;
    int cnt=1;
    scanf("%d%d%lld",&n,&m,&s);
    
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&v[i]);
        mm=max(mm,w[i]);
        mn=min(mn,w[i]);
        
    }
    for(int i=1;i<=m;i++)
		scanf(" %d %d",&l[i],&r[i]);
    int l=mn-1,r=mm+2,mid;
    long long ans=0x3f3f3f3f3f3f3f3f;
    while(l<=r)
    {
        mid=(l+r)>>1;
        

        if(get_y(mid))
        {
            l=mid+1;
        }else{
            r=mid-1;
        }
        if(sum<ans) ans=sum;
    }
    printf("%lld",ans);
    
    return 0;
}