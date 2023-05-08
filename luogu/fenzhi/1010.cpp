#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
vector<int> get_bin(int n)
{
    vector<int> ans;
    while(n!=0)
    {
        int temp=n%2;
        n/=2;
        ans.push_back(temp);
    }
    return ans;
}
map<int,string> m;
int main()
{
    int n;
    cin>>n;
    m[0]="2(0)";
    m[1]="2";
    m[2]="2(2)";
    m[3]="2(2+2(0))";
    m[4]="2(2(2))";
    m[5]="2(2(2)+2(0))";
    m[6]="2(2(2)+2)";
    m[7]="2(2(2)+2+2(0))";
    m[8]="2(2(2+2(0)))";
    m[9]="2(2(2+2(0))+2(0))";
    m[10]="2(2(2+2(0))+2)";
    m[11]="2(2(2+2(0))+2+2(0))";
    m[12]="2(2(2+2(0))+2(2))";
    m[13]="2(2(2+2(0))+2(2)+2(0))";
    m[14]="2(2(2+2(0))+2(2)+2)";
    vector<int> bin=get_bin(n);
    int cnt=0;
    while(bin[cnt]==0)
    {
        cnt++;
    }
    for (int i=bin.size()-1;i>=0;i--)
    {
        if(bin[i]==1)
        {
            cout<<m[i];
            if(i>cnt)
            {
                cout<<"+";
            }
        }
        
    }
    
    return 0;
}
