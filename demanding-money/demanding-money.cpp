#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 35;
const int MAGIC = 20;

int weight[MAX_N];
bool adj[MAX_N][MAX_N];
pii dp[(1<<14)];

bool check(vector<int> v) {
    for (int i=0;v.size()>i;i++) {
        for (int j=0;v.size()>j;j++) {
            if (adj[v[i]][v[j]]) return false;
        }
    }
    return true;
}

int main () {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;n>i;i++) {
        scanf("%d",&weight[i]);
    }
    for (int i=1;m>=i;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        --a;
        --b;
        adj[a][b] = adj[b][a] = 1;
    }
    if (n <= 20) {
        int mx=0;
        int mx_cnt=0;
        for (int i=0;(1<<n)>i;i++) {
            vector<int> v;
            int tot=0;
            for (int j=0;n>j;j++) {
                if (((1<<j)&i) != 0) {
                    v.push_back(j);
                    tot += weight[j];
                }
            }
            if (check(v)) {
                if (tot > mx) {
                    mx=tot;
                    mx_cnt=1;
                }
                else if (tot==mx) {
                    mx_cnt++;
                }
            }
        }
        printf("%d %d\n",mx,mx_cnt);
    }
    else {
        int nn=n-MAGIC;
        for (int i=0;(1<<nn)>i;i++) {
            vector<int> v;
            for (int j=0;nn>j;j++) {
                if (((1<<j)&i) != 0) {
                    v.push_back(j+MAGIC);
                }
            }
            int nnn=v.size();
            for (int ii=0;(1<<nnn)>ii;ii++) {
                vector<int> vv;
                int tot=0;
                for (int jj=0;nnn>jj;jj++) {
                    if (((1<<jj)&ii) != 0) {
                        vv.push_back(v[jj]);
                        tot += weight[v[jj]];
                    }
                }
                if (check(vv)) {
                    if (tot > dp[i].first) {
                        dp[i].first = tot;
                        dp[i].second = 1;
                    }
                    else if (tot == dp[i].first) {
                        dp[i].second++;
                    }
                }
            }
        }
        int mx=0;
        LL mx_cnt=0;
        int nnnn=20;
        for (int i=0;(1<<nnnn)>i;i++) {
            vector<int> v;
            int tot=0;
            for (int j=0;nnnn>j;j++) {
                if (((1<<j)&i) != 0) {
                    v.push_back(j);
                    tot += weight[j];
                }
            }
            if (check(v)) {
                int mask=0;
                for (int j=MAGIC;n>j;j++) {
                    bool okayy=true;
                    for (int ii=0;v.size()>ii;ii++) {
                        if (adj[j][v[ii]]) okayy=false;
                    }
                    if (okayy == true) mask += (1<<(j-MAGIC));
                }
                LL cnt = max(1LL,dp[mask].second);
                tot += dp[mask].first;
                if (tot > mx) {
                    mx=tot;
                    mx_cnt=cnt;
                }
                else if (tot==mx) {
                    mx_cnt+=cnt;
                }
            }
        }
        printf("%d %lld\n",mx,mx_cnt);
    }
}
