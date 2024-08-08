#include<bits/stdc++.h>
using namespace std;
int arr[2001][2001],dp[2001][2001];
struct pos {int x,y;};
struct node {pos from,to;};
vector<node> v;
int main()
{
	int r;
	cin>>r;
	for(int i=1;i<=r;i++) for(int j=1;j<=i;j++) cin>>arr[i][j];
	for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++) 
        {
            dp[i][j]=arr[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            if(dp[i-1][j]>dp[i-1][j-1]) v.push_back({{i-1,j},{i,j}});
            else v.push_back({{i-1,j-1},{i,j}});
        }
    }
    int maxv=INT_MIN;
    for(int i=1;i<=r;i++) maxv=max(maxv,dp[r][i]);
    cout<<maxv<<endl;
    for(int i=1;i<=r;i++) cout<<v[i].from.x<<" "<<v[i].from.y<<" "<<v[i].to.x<<" "<<v[i].to.y<<endl;
	return 0;
}
