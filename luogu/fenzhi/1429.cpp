#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;
float cal_dis(int x1,int y1,int x2,int y2)
{
    float ans;
    int dx=(x1-x2),dy=(y1-y2);
    ans=sqrt(1.0*dx*dx+dy*dy*1.0);
    return ans;
}
int main()
{
    int n;
    int max=0x7fffffff;
    float ans=(float)max;
    vector<int> x,y;
    scanf("%d",&n);
    while(n--)
    {
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        for(int i=0;i<x.size();i++)
        {
            float dis=cal_dis(x[i],y[i],tx,ty);
            if(dis<ans)
            {
                ans=dis;
            }
        }
        x.push_back(tx);
        y.push_back(ty);
    }
    printf("%.4f",ans);


    return 0;
}