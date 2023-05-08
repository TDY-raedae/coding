#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<float> result;
double a,b,c,d;
float f(float x)
{
    float ans=a*(x*x*x)+b*x*x+c*x+d;
    return ans;
}

int main()
{
    cin>>a>>b>>c>>d;
    int cnt=0;
    for(int i=-100;i<100;i++)
    {
        double l=i,r=i+1;
        if(f(l)==0)
        {
           printf("%.2lf ",i);
           cnt++;
        }
        if(f(i)*f(i+1)<0)
        {
            
            while(r-l>=0.001)
            {
                double m=(r+l)/2;
                if(f(m)*f(l)<0) r=m;
                if(f(m)*f(r)<0) l=m;
            }     
            printf("%.2lf",r);
            cnt++;
        }
        if(cnt==3)
        {
            break;
        }
    }
   
    return 0;
}
