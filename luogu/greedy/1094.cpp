#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int w,G;
    cin>>w>>G;
    vector<int> goods;
    for(int i=0;i<G;i++)
    {
        int temp;
        cin>>temp;
        goods.push_back(temp);
    }
    sort(goods.begin(),goods.end(),cmp);
    int left=0,right=goods.size()-1;
    int ans=0;
    while(left<=right)
    {
        if(left!=right&&goods[left]+goods[right]<=w)
        {
            ans++;
            left++;
            right--;
        }else {
            left++;
            ans++;
        }
    }
    cout<<ans<<endl;
    

    return 0;
}