#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    long long ans=0;
    bool flag=true,first=true;
    vector<int> h;
    cin>>n;
    while(n--)
    {
        int temp;
        cin>>temp;
        h.push_back(temp);
    }
    sort(h.begin(),h.end());
    int left=0,right=h.size()-1,pre;
    while(left<=right)
    {
        if(flag==true)
        {
            if(first==true)
            {
                ans+=h[right]*h[right];
                first=false;
            }else{
                ans+=(h[right]-h[pre])*(h[right]-h[pre]);
            }
            pre=right;
            right--;
            flag=false;
        }else{
            ans+=(h[pre]-h[left])*(h[pre]-h[left]);
            pre=left;
            left++;
            flag=true;
        }
    }
    cout<<ans;
    
    return 0;
}