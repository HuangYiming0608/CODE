#include <bits/stdc++.h>
#define N 10'0010
using namespace std;
int a[N],b[N];long long res=0,n;
void Search1(int i,int j)
{
    if(i==n/2+1) a[j]++;
    else Search1(i+1,j),Search1(i+1,j+i);
}
void Search2(int i,int j)
{
    if(i==n+1) b[j]++;
    else Search2(i+1,j),Search2(i+1,j+i);
}
int main()
{
    cin>>n;
    Search1(1,0);
    Search2(n/2+1,0);
    for(int i=0;i<=n*n;i++) for(int j=0;j<=n*n;j++) if(i+j==(n+1)*n/2-i-j) res+=1ll*a[i]*b[j];
    cout<<res/2;
	return 0;
}