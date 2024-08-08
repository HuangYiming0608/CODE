#include <bits/stdc++.h>
using namespace std;
struct node {int l,r,data;}tree[100'0005];
int n,maxx=INT_MIN;
int maxSub(int root)
{
    int lmax=0,rmax=0;
    if(!tree[root].l&&!tree[root].r) return tree[root].data;
    if(tree[root].l) lmax=maxSub(tree[root].l);
    if(tree[root].r) rmax=maxSub(tree[root].r);
    maxx=max(maxx,lmax+rmax);
    return lmax+rmax+tree[root].data;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>tree[i].data;
    for(int i=1;i<=n;i++) cin>>tree[i].l>>tree[i].r;
    cout<<maxx;
    return 0;
}