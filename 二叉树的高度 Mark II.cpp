#include <bits/stdc++.h>
using namespace std;
struct node {int l,r;}tree[100'0005];
int n;
int Tree_height(int root) {if(!root) return 0;return 1+max(Tree_height(tree[root].l),Tree_height(tree[root].r));}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>tree[i].l>>tree[i].r;
    cout<<Tree_height(1);
}