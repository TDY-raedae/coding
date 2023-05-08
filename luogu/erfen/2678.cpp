#include<iostream>
#include<vector>
using namespace std;
int d,n,m;
vector<int> rock;
bool judge(int s)
{
    bool answer=true;
    int now=0,i=0,move=0;
    while(i<rock.size())
    {
        int step=rock[i]-now;
        if(step<s)//如果发现要跳的距离小于目前测试的最小跳跃的步长,就进行石块的移动,在下次计算当前位置与下一块石块的距离
        {
            i++;
            move++;
        }else{
            now=rock[i++];//否则就跳跃
        }
    }
    //跳跃结束查看要移动的岩石个数是否小于等于规定移动的岩石个数
    if(move>m)
    {
        answer=false;
    }
    return answer;
}
//利用二分去加速枚举最小最大跳跃长度
void binary(int a,int b)
{
    int ans,l=a,r=b;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(judge(mid)==true)
        {
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    cin>>d>>n>>m;
    while(n--)
    {
        int temp;
        cin>>temp;
        rock.push_back(temp);
    }
    rock.push_back(d);
    binary(1,d);
    
    return 0;
}