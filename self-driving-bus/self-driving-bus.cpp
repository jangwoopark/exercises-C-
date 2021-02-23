#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int maxn=200000+10;
int h[maxn],go[maxn*2],nxt[maxn*2],size[maxn],a[maxn],fa[maxn],b[maxn][2],c[maxn][2];
int d[maxn];
bool bz[maxn];
int i,j,k,l,r,t,n,m,tot,top,cnt,num;
ll ans;
int read(){
 int x=0,f=1;
 char ch=getchar();
 while (ch<'0'||ch>'9'){
 if (ch=='-') f=-1;
 ch=getchar();
 }
 while (ch>='0'&&ch<='9'){
 x=x*10+ch-'0';
 ch=getchar();
 }
 return x*f;
}
void add(int x,int y){
 go[++tot]=y;
 nxt[tot]=h[x];
 h[x]=tot;
}
void travel(int x,int y){
 int t=h[x];
 size[x]=1;
 while (t){
 if (!bz[go[t]]&&go[t]!=y){
 travel(go[t],x);
 size[x]+=size[go[t]];
 }
 t=nxt[t];
 }
}
void dfs(int x,int y){
 fa[x]=y;
 a[++top]=x;
 int t=h[x];
 while (t){
 if (!bz[go[t]]&&go[t]!=y) dfs(go[t],x);
 t=nxt[t];
 }
}
void calc(int x){
 int i,j,k,t,l,r;
 fo(i,1,top) d[a[i]]=1;
 l=r=x;
 while (l>1&&d[l-1]) l--;
 while (r<n&&d[r+1]) r++;
 fa[x]=x;
 cnt=0;
 t=n+1;k=0;
 fd(i,x,l){
 t=min(t,fa[i]);
 k=max(k,fa[i]);
 if (t>=i){
 b[++cnt][0]=i;
 b[cnt][1]=k;
 }
 }
 num=0;
 t=n+1;k=0;
 fo(i,x,r){
 t=min(t,fa[i]);
 k=max(k,fa[i]);
 if (k<=i){
 c[++num][0]=i;
 c[num][1]=t;
 }
 }
 j=k=1;
 fo(i,1,cnt){
 while (j<=num&&c[j][0]<b[i][1]) j++;
 while (k<num&&c[k+1][1]>=b[i][0]) k++;
 if (j<=k) ans+=(ll)(k-j+1);
 }
 fo(i,1,top) d[a[i]]=0;
}
void solve(int x){
 travel(x,0);
 int j=x,k=0,t;
 while (1){
 t=h[j];
 while (t){
 if (!bz[go[t]]&&go[t]!=k&&size[go[t]]>top/2){
 k=j;
 j=go[t];
 break;
 }
 t=nxt[t];
 }
 if (!t) break;
 }
 top=0;
 dfs(j,0);
 calc(j);
 bz[j]=1;
 t=h[j];
 while (t){
 if (!bz[go[t]]) solve(go[t]);
 t=nxt[t];
 }
}
int main(){
 n=read();
 fo(i,1,n-1){
 j=read();k=read();
 add(j,k);add(k,j);
 }
 solve(1);
 printf("%lld\n",ans);
}
