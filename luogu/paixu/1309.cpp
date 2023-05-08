#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct person{
    int s;
    int w;
    int id;
    
}p[200001];
vector<person> pw,pl;
bool cmp(person a,person b)
{
    if(a.s!=b.s)  return a.s>b.s;
    else return a.id<b.id;
}
void merge(vector<person> p1,vector<person> p2)
{
    int i=0,j=0,cnt=0;
    while(i<p1.size()&&j<p2.size())
    {
        if(cmp(p1[i],p2[j])==true)
        {
            p[cnt++]=p1[i++];
        }else{
            p[cnt++]=p2[j++];
        }
    }
    while(i<p1.size()) p[cnt++]=p1[i++];
    while(j<p2.size()) p[cnt++]=p2[j++];
    return;
}


int main()
{

    int n,r,q,cnt=0;
    scanf("%d%d%d",&n,&r,&q);
    for(int i=0;i<2*n;i++)
    {
        scanf("%d",&p[i].s);
        p[i].id=i+1;
        
    }
    for(int i=0;i<2*n;i++)
    {
        scanf("%d",&p[i].w);
    }

    sort(p,p+2*n,cmp);
    
    while(r--)
    {
        pw.clear();
        pl.clear();
        for(int i=0;i<n;i++)
        {
            if(p[2*i].w>p[2*i+1].w)
            {
                p[2*i].s+=1;
                pw.push_back(p[2*i]);
                pl.push_back(p[2*i+1]);
            }else{
                p[2*i+1].s+=1;
                pw.push_back(p[2*i+1]);
                pl.push_back(p[2*i]);
            }
        }
        merge(pw,pl);
    }
    
    printf("%d",p[q-1].id);
    
    return 0;
}