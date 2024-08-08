#include <bits/stdc++.h>
#define N 1000'0010
using namespace std;
char S[N],T[N];int _next[N],n,m,cnt=0;
void kmp()
{
    _next[1]=0;int j=0;
    for(int i=2;i<=m;i++)
    {
        while(j>0&&S[j+1]!=S[i]) j=_next[j];
        if(S[j+1]==S[i]) j++;
        _next[i]=j;
    }
    j=0;
    for(int i=1;i<=n;i++)
    {
        while(j>0&&S[j+1]!=T[i]) j=_next[j];
        if(S[j+1]==T[i]) j++;
        if(j==m) {cnt++,j=_next[j];printf("%d\n",i-m+1);}
    }
}
int main()
{
    scanf("\n%s",T+1);
    scanf("\n%s",S+1);
    m=strlen(S+1),n=strlen(T+1);
    kmp();
    for(int i=1;i<=m;i++) printf("%d ",_next[i]);
}