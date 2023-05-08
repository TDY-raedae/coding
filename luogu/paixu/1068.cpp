#include<iostream>
#include<algorithm>
using namespace std;
struct student{
    int grade;
    int id;
}stu[5001];
bool cmp(student a,student b)
{
    if(a.grade!=b.grade) return a.grade>b.grade;
    else return a.id<b.id;
}
int main()
{
    int n,m,cnt=0;
    cin>>n>>m;
    while(n--)
    {
        int g,i;
        cin>>i>>g;
        stu[cnt].grade=g;
        stu[cnt].id=i;
        cnt++;
    }
    sort(stu,stu+cnt,cmp);
    int idx=(int)(m*1.5);
    while(idx<=cnt&&stu[idx-1].grade==stu[idx].grade)
    {
        idx++;
    }
    cout<<stu[idx-1].grade<<" "<<idx<<endl;
    for(int i=0;i<idx;i++)
    {
        cout<<stu[i].id<<" "<<stu[i].grade;
        if(i!=idx-1)
        {
            cout<<endl;
        }
    }
    return 0;

}