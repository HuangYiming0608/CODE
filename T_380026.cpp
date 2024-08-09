#include <bits/stdc++.h>
#define N 10'0010
using namespace std;
int res=0,n,d,vis[N];
vector <int> arr[N];
void _Search(int point,int step,int ans)
{
    //cout<<point<<step<<" "<<ans<<endl;
    if(step>=d) {res+=ans;return;}
    for(int i=0;i<arr[point].size();i++) if(!vis[arr[point][i]]) {vis[arr[point][i]]=true;_Search(arr[point][i],step+1,ans+1);vis[arr[point][i]]=false;/*cout<<point<<step<<ans<<"to\n";*/}
}
signed main()
{
	cin>>n>>d;
    for(int i=1;i<=n-1;i++) {int from,to;cin>>from>>to;arr[from].push_back(to);arr[to].push_back(from);}
    _Search(1,0,0);
    cout<<res;
	return 0;
}
// I AK IOI
// 垃圾 CCF