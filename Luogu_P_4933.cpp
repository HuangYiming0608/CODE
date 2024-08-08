#include <bits/stdc++.h>
#define N 10'0010
#define dpn 1010
#define MOD 998244353
using namespace std;
int h[N],dp[dpn][dpn];long long res=0;
int main()
{
	int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) {for(int j=i;j>0;j--) dp[i][h[i]-h[j]+20000]+=dp[j][h[i]-h[j]+20000],dp[i][h[i]-h[j]+20000]%=MOD;res+=i,res%=MOD;}
    for(int i=1;i<=n;i++) for(int j=i;j>0;j--) res+=dp[j][h[i]-h[j]+20000]+1,res%=MOD;
    cout<<res%MOD;
	return 0;
}