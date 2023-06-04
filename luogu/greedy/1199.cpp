#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct general{
    int id;
    int score;
    general(int _i,int _s): id(_i),score(_s){}
};
map<pair<int,int>,int> ts;
bool visit[510]={false};
vector<general> g;
vector<int> p,c;
bool cmp(general a,general b)
{
    if(a.score!=b.score) return a.score>b.score;
    else return a.id<b.id;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp;
            cin>>temp;
            ts[make_pair(i,j)]=temp;
            ts[make_pair(j,i)]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        general temp(i,0);
        for(int j=0;j<n;j++)
        {
            if(j!=i)
            {
                pair<int,int> p(i,j);
                temp.score+=ts[p];
            }
        }
        g.push_back(temp);
    }
    sort(g.begin(),g.end(),cmp);
    
    int count=n/2,cnt=0;
    while(count>0)
    {
        for(int i=cnt;i<g.size();i++)
        {
            if(visit[g[i].id]==false)
            {
                p.push_back(g[i].id);
                cnt=i;
                visit[g[i].id]=true;
                break;
                
            }
        }
        int max=-1,cnt_c;
        for(int i=0;i<n;i++)
        {
            if(i!=g[cnt].id&&visit[i]==false)
            {
                pair<int,int> tp(g[cnt].id,i);
                if(ts[tp]>max)
                {
                    cnt_c=i;
                    max=ts[tp];
                }
           
            }
        }
        visit[cnt_c]=true;
        c.push_back(cnt_c);
        count--;
    }
    
    int max_p=ts[make_pair(p[0],p[1])];
    int max_c=ts[make_pair(c[0],c[1])];
    for (int i=2;i<p.size();i++)
    {
        if(ts[make_pair(p[0],p[i])]>max_p)
        {
            max_p=ts[make_pair(p[0],p[1])];
        }
    }
    for(int i=2;i<c.size();i++)
    {
        if(ts[make_pair(c[0],c[i])]>max_c)
        {
            max_c=ts[make_pair(c[0],c[i])];
        }
    }
    if(max_p>max_c)
    {
        cout<<"1"<<endl<<max_p<<endl;
    }else{
        cout<<"0"<<endl;
    }
    system("pause");

    return 0;
}
