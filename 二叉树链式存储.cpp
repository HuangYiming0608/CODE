#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int v;
	Node *l,*r;
	Node(int x):v(x),l(nullptr),r(nullptr) {}
};
vector<int> pre,in,post;
void trav(Node* r)
{
	if(!r) return;
	pre.push_back(r->v);
	trav(r->l);
	in.push_back(r->v);
	trav(r->r);
	post.push_back(r->v);
}
int main()
{
    int n;
    cin>>n;
    vector <Node*> ns(n+1);
    for(int i=1;i<=n;i++) ns[i]=new Node(i);
	for(int i=1;i<=n;i++)
	{
		int l,r;cin>>l>>r;
		if(l) ns[i]->l=ns[i];
		if(r) ns[i]->r=ns[r];
	}
	trav(ns[1]);
	for(int v:pre) cout<<v<<" ";
	cout<<endl;
	for(int v:in) cout<<v<<" ";
	cout<<endl;
	for(int v:post) cout<<v<<" ";
	cout<<endl;
}