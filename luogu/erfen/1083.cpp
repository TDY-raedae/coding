#include<cstdio>
#include<vector>
#include<utility>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m,rent[1000010]={0},d[1000010]={0},l[1000010]={0},r[1000010]={0};
long long diff[1000010]={0},need[1000010]={0};
bool check(int x)
{
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=x;i++)
    {
        diff[l[i]]+=d[i];
        diff[r[i]+1]-=d[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        need[i]=need[i-1]+diff[i];
        if(need[i]>rent[i]) return false;
    }
    return true;
}
int main()
{   
    
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&rent[i]);   
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&d[i],&l[i],&r[i]);
    }
    if(check(m)==true) 
    {
        printf("0");
        return 0;
    }else{
        printf("-1\n");
    }    
    int left=1,right=m;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(check(mid)==true)
        {
            left=mid+1;
        }else{
            right=mid-1;
        }
    }

    printf("%d",left);
    
    return 0;
}