#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> logs;
long long check(long long x)
{
    long long cnt=0,now=0;
    for(int i=0;i<logs.size();i++)
    {
        now=max(now+logs[i],0ll);
        if(now>=x)
        {
            cnt++;
            now=0;
        }
    }
    return cnt;
}
int main()
{
    int l,k;
    long long sum=0,ans1=-1,ans2=-1;
    cin>>l>>k;
    while(l--)
    {
        int temp;
        cin>>temp;
        sum+=temp;
        logs.push_back(temp);
    }
    long long left=1,right=sum;
    while(left<=right)
    {
        long long mid=(left+right)/2;
        
        if(check(mid)<=k)
        {
            if(check(mid)==k) ans1=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    
    left=1,right=sum;
    while(left<=right)
    {
        long long mid=(left+right)/2;
        if(check(mid)>=k)
        {
            if(check(mid)==k) ans2=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    if (ans1==-1)
    {
        printf("%lld",ans1);
    } else{
        cout<<ans1<<" "<<ans2<<endl;
    }
    
    

    return 0;
}