#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct product{
    int price;
    int number;
    product(int p,int num):price(p),number(num){}
};
vector<product> pro;
bool cmp(product a,product b)
{
    if(a.price!=b.price) return a.price <b.price;
    else return a.number<b.number;
}
int main()
{
    int n,m;
    long long ans=0;
    cin>>n>>m;
    while(m--)
    {
        int pr,nu;
        cin>>pr>>nu;
        product tp(pr,nu);
        pro.push_back(tp);
    }
    sort(pro.begin(),pro.end(),cmp);
    
    for(int i=0;i<pro.size()&&n>0;i++)
    {
        if(pro[i].number<=n)
        {
            ans+=pro[i].number*pro[i].price;
            n-=pro[i].number;
        }else{
            ans+=pro[i].price*n;
            n-=n;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
