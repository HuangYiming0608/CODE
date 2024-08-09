#include <bits/stdc++.h>
#define N 1010
using namespace std;
string as,bs;int dp[N][N],mp[6][6]={{0,0,0,0,0,0},{0,5,-1,-2,-1,-3},{0,-1,5,-3,-2,-4},{0,-2,-3,5,-2,-2},{0,-1,-2,-2,5,-1},{0,-3,-4,-2,-1,0}};
int a[N],b[N];
int main()
{
	int n,m;
    cin>>n>>as;
    for(int i=1;i<N;i++) for(int j=1;j<N;j++) dp[i][j]=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        if(as[i-1]=='A') a[i]=1;
        if(as[i-1]=='C') a[i]=2;
        if(as[i-1]=='G') a[i]=3;
        if(as[i-1]=='T') a[i]=4;
    }
    cin>>m>>bs;
    for(int i=1;i<=m;i++)
    {
        if(bs[i-1]=='A') b[i]=1;
        if(bs[i-1]=='C') b[i]=2;
        if(bs[i-1]=='G') b[i]=3;
        if(bs[i-1]=='T') b[i]=4;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++) dp[i][0]=dp[i-1][0]+mp[a[i]][5];
    for(int i=1;i<=m;i++) dp[0][i]=dp[0][i-1]+mp[5][b[i]];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
        dp[i][j]=max(dp[i][j],dp[i-1][j]+mp[a[i]][5]),
        dp[i][j]=max(dp[i][j],dp[i][j-1]+mp[5][b[j]]),
        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+mp[a[i]][b[j]]);
    cout<<dp[n][m];
	return 0;
}