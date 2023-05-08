#include <bits/stdc++.h>
#define MAX (100000 + 7)
#define long long long
using namespace std;

int N, k, a[MAX];
long l, r, ans1 = -1, ans2 = -1;

long work(long im)
{
    int ans = 0; long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum = max(sum + a[i], 0ll);
        if (sum >= im) sum = 0, ans++;
    }return ans;
}

int main()
{
    scanf("%d%d", &N, &k);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
    l = 1, r = 1e18;//注意l应设为1 
    while (l <= r)
    {
        long mid = (l + r) >> 1;
        if (work(mid) <= k)
        {
        	r = mid - 1;
        	if (work(mid) == k) ans1 = mid;//注意符合条件才更新答案 
		}
		else l = mid + 1;
    }
    
    l = 1, r = 1e18;//注意l应设为1 
    while (l <= r)
    {
        long mid = (l + r) >> 1;
        if (work(mid) >= k)
        {
        	l = mid + 1;
        	if (work(mid) == k) ans2 = mid;//注意符合条件才更新答案 
		}
		else r = mid - 1;
    }
    if (ans1 == -1) puts("-1");
    else printf("%lld %lld\n", ans1, ans2);
}