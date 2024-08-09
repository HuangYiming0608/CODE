#include <bits/stdc++.h>
#define N 10'0010
using namespace std;
int arr[N],dp[1010][1010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=0x3f3f;
	for(int i=n;i>=1;i--) for(int j=i;j<=n;j++)
	{
		if(i==j) dp[i][j]=1;
		else if(i+1==j) {if(arr[i]==arr[i+1]) dp[i][j]=1; else dp[i][j]=2;}
		else 
		{if(arr[i]==arr[j]) dp[i][j]=dp[i+1][j-1]; for(int k=i;k<=j;k++) dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);}
		//cout<<dp[i][j]<<endl;
	}
	cout<<dp[1][n];
	return 0;
}