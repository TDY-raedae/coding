#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;
vector<int> cost;
bool ha[1001]={false};
int map[1010][1010]={0},vis[1010][1010]={0},n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool bfs(int x, int y,int maxc)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    vis[x][y]=1;
    while(!q.empty())
    {
        int x1=q.front().first;
        int y1=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x1+dx[i];
            int ny=y1+dy[i];
            if(nx<0||ny<0||nx>n-1||ny>m-1||map[nx][ny]>maxc||vis[nx][ny]==1)
            {
                continue;
            }else{
                if(nx==n-1)
                {
                    return true;
                }
                vis[nx][ny]=1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    return false;
}
void binary()
{
    int l=0,r=cost.size()-1,ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        memset(vis,0,sizeof(vis));
        if(bfs(0,0,cost[mid])==true)
        {
            ans=cost[mid];
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
            if(ha[map[i][j]]==false)
            {
                ha[map[i][j]]=true;
                cost.push_back(map[i][j]);
            }
        }
    }
    sort(cost.begin(),cost.end());
    binary();
    
    return 0;
}