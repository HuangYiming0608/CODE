#include <bits/stdc++.h>
using namespace std;
struct node {int l,r;}tree[100'0005];
int n;
int Tree_height(int root)
{
    if(!root) return 0;
    int lheight=Tree_height(tree[root].l),rheight=Tree_height(tree[root].r);
    if(lheight==-1||rheight==-1||abs(lheight-rheight)) return -1;
    return 1+max(lheight,rheight);
}
bool IsBalanced(int root) {if(!root) return 1;return Tree_height(root)>=0;}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>tree[i].l>>tree[i].r;
    cout<<(IsBalanced(1)?"Yes":"No");
}