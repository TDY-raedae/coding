#include<iostream>
#include<algorithm>
using namespace std;
int a[101]={0};
bool hash_m[1001]={false};
int main()
{
    int n,cnt=0;
    cin>>n;
    while(n--)
    {
        int temp;
        cin>>temp;
        if(hash_m[temp]==false)
        {
            hash_m[temp]=true;
            a[cnt++]=temp;
        }
    }
    cout<<cnt<<endl;
    sort(a,a+cnt);
    for(int i=0;i<cnt;i++)
    {
        cout<<a[i];
        if(i!=cnt-1)
        {
            cout<<" ";
        }
    }
    
    return 0;
}
