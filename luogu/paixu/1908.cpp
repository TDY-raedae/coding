#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> num;
unordered_map<int,int> hash_m;
int main()
{

    int n;
    long long answer=0;
    bool first=true;
    scanf("%d",&n);
    while(n--)
    {
        int temp;
        scanf("%d",&temp);
        if(first==true)
        {   
            num.push_back(temp);
            hash_m[temp]=0;
            first=false;
        }else{
            if(hash_m.find(temp)!=hash_m.end())
            {
                int sum=0;
                for(int i=0;i<num.size();i++)
                {
                    if(num[i]>temp)
                    {
                        sum++;
                    }
                }
                hash_m[temp]=sum;
                answer+=sum;
            }
        }
    }
    printf("%d",&answer);
    return 0;
}
