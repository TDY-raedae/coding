#include<iostream>
using namespace std;
long long quick_pow(long long a, long long b,long long p)
{
    long long ans=1;
    while(b)
    {
        if(b&1!=0)
        {
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}
int main()
{
    long long a,b,p;
    cin>>a>>b>>p;
    long long ans=quick_pow(a,b,p);
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<ans<<endl;
}