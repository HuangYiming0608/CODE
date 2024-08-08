#include <bits/stdc++.h>
using namespace std;
struct node {int l,r;}tree[100'0005];
int n;
queue<node> q;
int Tree_height(int root)
{
    int ans=0;
    q.push(tree[root]);
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--) 
        {
            node t=q.front();q.pop();
            if(t.l) q.push(tree[t.l]);
            if(t.r) q.push(tree[t.r]);
        }
        ans++;
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>tree[i].l>>tree[i].r;
    cout<<Tree_height(1);
    return 0;
}