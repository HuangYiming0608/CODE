#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(b>=c)
    {
        if(a<c||a>b) cout<<"No";
        else cout<<"Yes";
    }
    else
    {
        if((b<=a&&a<=c)||(b>=a&&a>=c)) cout<<"No";
        else cout<<"Yes";
    }
}