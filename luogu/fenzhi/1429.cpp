#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
#include<climits>
#include<cfloat>
#define maxn 200000
using namespace std;
int temp[maxn]={0},cnt=0,n;
struct Point{
    double x,y;
}P[maxn];

bool cmp1(Point a,Point b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}
bool cmp2(const int &a,const int &b)
{
    return P[a].y<P[b].y;
}
double min(double a,double b){ return a<b ? a:b;}
double dis(int a,int b)
{
    double xq=(P[a].x-P[b].x)*(P[a].x-P[b].x);
    double yq=(P[a].y-P[b].y)*(P[a].y-P[b].y);
    return sqrt(xq+yq);
}
double merge(int left,int right)
{
    double d=DBL_MAX;
    if(left==right) return d;
    if(left+1==right) return dis(left,right);
    int mid=(left+right)/2;
    double d1=merge(left,mid);
    double d2=merge(mid+1,right);
    d=min(d1,d2);
    int cnt=0;
    for(int i=left;i<right;i++)
    {
        if(fabs(P[mid].x-P[i].x)<d)
        {
            temp[cnt++]=i;
        }
    }
    sort(temp,temp+cnt,cmp2);
    for(int i=0;i<cnt;i++)
    {
        for(int j=i+1;j<cnt&&P[temp[j]].y-P[temp[i]].y<d;j++)
        {
            double d3=dis(temp[i],temp[j]);
            if(d3<d)
            {
                d=d3;
            }
        }
    }
    return d;
}
int main()
{
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        
        scanf("%lf%lf",&P[cnt].x,&P[cnt].y);
        cnt++;
        
    }
    sort(P,P+n,cmp1);
    double ans=merge(0,n-1);
    printf("%.4lf",ans);
    return 0;
}