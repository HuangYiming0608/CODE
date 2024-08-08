#include<bits/stdc++.h>
#define N 10'0010
using namespace std;
long long n,ans=N;
bool vis[N];
vector<long long> tree[N];
long long dfs(long long u,long long fa)
{
	vis[u]=1;long long size=0,sum=1;
	for(long long i=0;i<tree[u].size();i++)
	{
		long long j=tree[u][i];
		if(j==fa) continue;
		long long s=dfs(j,u);
		size=max(size,s),sum+=s;
	}
	ans=min(ans,max(size,n-sum));
	return sum;
}
long long main()
{
	cin>>n;
	for(long long i=1;i<n;i++) {long long u,v;cin>>u>>v;tree[u].push_back(v);tree[v].push_back(u);}
	dfs(1,-1);
	cout<<ans;
}