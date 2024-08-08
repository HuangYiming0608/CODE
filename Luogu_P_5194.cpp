#include <bits/stdc++.h>
#define N 1000'0010
using namespace std;
long long n,c,t,res=INT_MIN,ans[N],sum=0,arr[N];
void Search1(long long x,long long weight)
{
    if(weight>c) return;
    if(x==n/2+1) {ans[weight]=weight;return;}
    Search1(x+1,weight),Search1(x+1,weight+arr[x]);
}
void Search2(long long x,long long weight)
{
    if(weight>c) return;
    if(x==n+1) if(x==n+1) {res=max(res,weight+ans[min(sum,c-weight)]);return;}
    Search2(x+1,weight),Search2(x+1,weight+arr[x]);
}
int main()
{
	cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>arr[i];
    Search1(1,0);
    for(int i=1;i<=n/2;i++) sum+=arr[i];
    for(int i=1;i<=sum;i++) ans[i]=max(ans[i],ans[i-1]);
    Search2(n/2+1,0); 
    cout<<res;
	return 0;
}