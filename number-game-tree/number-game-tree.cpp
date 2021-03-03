#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
int n,m,q;
const int MAXN=5e5+7;
const int mod=1e9+7;
vector<pair<int,ULL>>edge[MAXN];
map<ULL,int>num;
 
ULL Hash(ULL w)
{
    return w*747474747+447474747;
}
 
void dfs(int u,int fa,ULL w)
{
    num[w]++;
    for(auto it:edge[u])
    {
        int v=it.first;
        ULL ww=it.second;
        if(v==fa)continue;
        dfs(v,u,w^ww);
    }
}
int main()
{
    int i;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;++i)edge[i].clear();
        int u,v,w;
        for(i=0;i<n-1;++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            edge[u].push_back(make_pair(v,Hash(w)));
            edge[v].push_back(make_pair(u,Hash(w)));
        }
        ULL ans=(1ULL*n*(n-1))>>1;
        num.clear();
        dfs(1,0,0);
        for(auto it :num)
        {
            ans-=(1ULL*(it.second-1)*it.second)>>1;
        }
        cout<<ans<<endl;
    }
}
