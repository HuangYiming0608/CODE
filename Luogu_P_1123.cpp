#include <bits/stdc++.h>
#define N 1010
using namespace std;
int arr[N][N],vis[N][N],n,m,res=INT_MIN,flag[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void Search(int x,int y,int cnt)
{
	res=max(res,cnt);
	if(x>n||y>m||1>x||1>y) return;
	if(!vis[x][y])
	{
		vis[x][y]++;
		for(int j=0;j<8;j++) vis[x+flag[j][0]][y+flag[j][1]]++;
		if(y==m) Search(x+1,1,cnt+arr[x][y]);
		else Search(x,y+1,cnt+arr[x][y]);
		for(int j=0;j<8;j++) vis[x+flag[j][0]][y+flag[j][1]]--;
		vis[x][y]--;
	}
	vis[x][y]++;
	if(y==m) Search(x+1,1,cnt);
	else Search(x,y+1,cnt);
	vis[x][y]--;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		memset(arr,0,sizeof(arr));memset(vis,0,sizeof(vis));res=INT_MIN;
		cin>>n>>m;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>arr[i][j];
		Search(1,1,0);
		cout<<res<<"\n";
	}
	return 0;
}