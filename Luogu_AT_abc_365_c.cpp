#include <bits/stdc++.h>
#define N 1000'0010
using namespace std;
long long arr[N],sum=0;
signed main()
{
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>arr[i],sum+=arr[i];
    if(sum<=m) cout<<"infinite";
    else
    {
        long long l=0,r=sum;
        while(l-r>1||r-l>1)
        {
            long long mid=(l+r+1)>>1,sum=0;
            for(long long i=1;i<=n;i++) sum+=min(mid,arr[i]);
            if(sum<=m) l=mid;
            else r=mid;
        }
        cout<<l;
    }
	return 0;
}