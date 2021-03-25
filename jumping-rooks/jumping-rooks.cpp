#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <ctime>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#define LL long long
#define Pr pair<int,int>
#define fread(ch) freopen(ch,"r",stdin)
#define fwrite(ch) freopen(ch,"w",stdout)

using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-8;
const int MAXK = 5511;
const int MAXM = 6255555;

struct Edge
{
    int v,cap,cost,next;
    Edge(){}
    Edge(int _v,int _cap,int _cost,int _next):v(_v),cap(_cap),cost(_cost),next(_next){}
};

Edge eg[MAXM];
char mp[55][55];
int head[MAXK];
int R[55][55],C[55][55];
int tp,s,t;
int pre[MAXK];
int dis[MAXK];
bool vis[MAXK];

void Add(int u,int v,int cap,int cost)
{
    eg[tp] = Edge(v,cap,cost,head[u]);
    head[u] = tp++;
    eg[tp] = Edge(u,0,-cost,head[v]);
    head[v] = tp++;
}

int spfa()
{
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    memset(pre,-1,sizeof(pre));
    queue <int> q;
    q.push(s);
    dis[s] = 0;

    int u,v,w,c;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        vis[u] = 0;

        for(int i = head[u]; i != -1; i = eg[i].next)
        {
            v = eg[i].v;
            c = eg[i].cost;

            if(eg[i].cap && dis[u]+c < dis[v])
            {
                dis[v] = dis[u]+c;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    u = t;

    while(u != s)
    {
        eg[pre[u]].cap--;
        eg[pre[u]^1].cap++;
        u = eg[pre[u]^1].v;
    }

    return dis[t];
}

int main()
{
    //fread("");
    //fwrite("");

    int n,k;

    scanf("%d%d",&n,&k);

    for(int i = 0; i < n; ++i)
        scanf("%s",mp[i]);

    memset(head,-1,sizeof(head));
    tp = 0;

    int id = 0;

    for(int i = 0; i < n; ++i)
    {
        int j = 0;
        while(j < n)
        {
            if(mp[i][j] == '#') ++j;
            else
            {
                id++;
                while(j < n && mp[i][j] != '#') R[i][j++] = id;
            }
        }
    }

    int cntr = id;

    for(int j = 0; j < n; ++j)
    {
        int i = 0;
        while(i < n)
        {
            if(mp[i][j] == '#') ++i;
            else
            {
                id++;
                while(i < n && mp[i][j] != '#') C[i++][j] = id;
            }
        }
    }

    s = 0;
    t = id+1;

    for(int i = 1; i <= cntr; ++i)
        for(int j = 0; j <= n; ++j)
            Add(0,i,1,j);


    for(int i = cntr+1; i <= id; ++i)
        for(int j = 0; j <= n; ++j)
            Add(i,t,1,j);


    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            if(mp[i][j] == '#') continue;
            Add(R[i][j],C[i][j],1,0);
        }

    int ans = 0;


    while(k--) ans += spfa();

    printf("%d\n",ans);

    return 0;
}
