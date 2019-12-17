#include <bits/stdc++.h> 
using namespace std; 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FORU(i, a, b) for (int i = a, nn = int(b); i <= nn; ++i) 
#define FORD(i, a, b) for (int i = a, nn = int(b); i >= nn; --i) 
#define REP(i, b) for (int i = 0, nn = int(b); i < nn; ++i) 
#define sz(x) (int)(x).size()
#define mmst(a, x) memset(a, x, sizeof(a))
#define DEBUG(x) cout << #x << " : " << (x) << endl; 
#define LOOK(x, a, b) {cout << #x << " : ";FORU(i, a, b) cout << x[i] << ' '; cout << endl; }
typedef long long ll; 
typedef double ff; 
typedef vector<int> vi; 
typedef pair<int, int> pii; 
const int N = 602, K = 1024, p = 1E9 + 7;
int dp[N][K], nwdp[N][K], m, n, k, sg[N];
bool can[K];
int main() {
    cin >> m >> n >> k;
    if (k == 2) {
		FORU(i, 1, 600)
            if (i % 2 == 1) sg[i] = 0;
            else sg[i] = 1;
    }
    if (k == 3) {
        sg[1] = 0;
		FORU(i, 1, 600) {
            memset(can, 0, sizeof(can) );
			FORU(j, 1, i-1) {
                int cur = sg[j] ^ sg[i - j];
                can[cur] = true;
            }
			FORU(j, 1, i - 2) {
                for (int l = 1; j + l < i; l++) {
                    int cur = sg[j] ^ sg[l] ^ sg[i - j - l];
                    can[cur] = true;
                }
            }
            REP(j, K)
                if (can[j] == false) {
                    sg[i] = j; break;
                }
        }

    }
    if (k > 3) FORU(i, 1, 600) sg[i] = i - 1;
    dp[0][0] = 1;
    REP(i, n) {
        memset(nwdp, 0, sizeof(nwdp) );
		REP(j, m) REP(gr, K) {
			if (dp[j][gr] == 0) continue;
			for (int nxt = 1; nxt + j <= m; nxt++) {
				nwdp[j + nxt][gr^sg[nxt] ] += dp[j][gr];
				if (nwdp[j + nxt][gr^sg[nxt] ] >= p)
					nwdp[j + nxt][gr^sg[nxt] ] -= p;
			}
        }
        swap(dp, nwdp);
    }
    int s = 0;
	FORU(i, 1, K-1){
        s += dp[m][i];
        if (s >= p) s -= p;
    }
    cout << s << endl;
    return 0;
}
