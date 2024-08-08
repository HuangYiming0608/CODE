#include <bits/stdc++.h>
#define N 200010
using namespace std;
struct node {int key,id;}arr[N];
struct node2 {int lft,rit;}tree[N];
bool cmp(node a,node b) {return a.id<b.id;}
int n,ri[N],m;
void dfs(int i) {if(i==n)return;cout<<arr[i].key<<" ";dfs(tree[i].lft);dfs(tree[i].rit);}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].key,arr[i].id=i;
    sort(arr+1,arr+n+1,cmp);m=0;
    for(int i=1;i<=n;i++)
    {
        bool judge=0;
        while(m>0&&ri[m]>arr[i].id) m--,judge=true;
        if(judge) tree[arr[i].id].lft=ri[m+1];
        if(!m) tree[ri[m]].rit=arr[i].id;
        ri[++m]=arr[i].id;
    }
    dfs(1); 
}