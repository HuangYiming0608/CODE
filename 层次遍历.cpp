#include <bits/stdc++.h>
using namespace std;
struct node {char ch;int left,right;}tree[101];
int cnt=0;
queue<node> q;
int buildTree(int T)
{
	char ch;cin>>ch;
	if(ch=='.') return 0;
	T=++cnt;
	tree[T].ch=ch;
	tree[T].left=buildTree(T);
	tree[T].right=buildTree(T);
    return T;
}
void levelTraverse(int T)
{
    q.push(tree[T]);
    while(!q.empty())
    {
        node t=q.front();q.pop();
        cout<<t.ch;
        if(t.left) q.push(tree[t.left]);
        if(t.right) q.push(tree[t.right]);
    }
    return;
}
int main()
{
    int root=buildTree(0);
    levelTraverse(root);
    return 0;
}