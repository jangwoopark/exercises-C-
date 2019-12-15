#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
#include <cstdio>
#include <ctype.h>
#include <time.h>
using namespace std;

#define PI acos(-1.0)
#define EPS 1e-8
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
#define go(i, a, b) for(int i = a; i <= b; ++i)
#define gorev(i, a, b) for(int i = a; i >= b; --i)

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
    return os << "(" << P.fi << "," << P.se << ")";
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
    os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, map<L, R> M){
    os << "["; for (auto pr: M) os << pr.fi << "->" << pr.se << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, unordered_map<L, R> M){
    os << "["; for (auto pr: M) os << pr.fi << "->" << pr.se << ","; return os << "]";
}

struct Matrix {
    vvi data;
    int r, c;
    Matrix(int row, int col, bool identity = false) : r(row), c(col) {
        data.assign(row, vector<int>(col, 0));
        if (identity) {
            for (int i = 0; i < r; ++i) {
                data[i][i] = 1;
            }
        }
    }
    Matrix operator * (Matrix& other) {
        int m = r, n = c, p = other.c;
        Matrix res(m, p);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < n; ++k) {
                    res.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return res;
    }
};

vector<int> extendGcd(int a, int b) {
    if (b == 0) {
        return {1, 0, a};
    } else {
        vector<int> tmp = extendGcd(b, a % b);
        return {tmp[1], tmp[0] - (a / b) * tmp[1], tmp[2]};
    }
}

Matrix matrix_power(Matrix base, ll exp) {
    int n = base.r;
    Matrix res(n, n, true);
    while (exp) {
        if (exp & 1) {
            res = res * base;
        }
        base = base * base;
        exp >>= 1;
    }
    return res;
}

/******************************** template ********************************/
#define N 50010
int c[N];
vi edges[N];
int n, q, u, v;
int level[N], p[N][17], odd[N], even[N];

void dfs(int cur, int pa) {
    level[cur] = level[pa] + 1;
    p[cur][0] = pa;
    for (int i = 1; i < 17; ++i) {
        p[cur][i] = p[p[cur][i - 1]][i - 1];
    }
    if (level[cur] % 2) {
        odd[cur] = c[cur];
    } else {
        even[cur] = c[cur];
    }
    for (int next : edges[cur]) {
        if (next == pa) continue;
        dfs(next, cur);
        even[cur] ^= even[next];
        odd[cur] ^= odd[next];
    }
}

int climb(int a, int d) {
    for (int i = 0; i < 17; ++i) {
        if (d & (1 << i)) {
            a = p[a][i];
        }
    }
    return a;
}

int lca(int a, int b) {
    if (level[a] != level[b]) {
        if (level[a] < level[b]) {
            return lca(b, a);
        }
        a = climb(a, level[a] - level[b]);
    }
    if (a == b) return a;
    for (int i = 16; i >= 0; --i) {
        if (p[a][i] == p[b][i]) continue;
        a = p[a][i];
        b = p[b][i];
    }
    return p[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef ZYC_LOCAL
    freopen("input.txt", "rt", stdin);
#endif
    cin >> n;
    go(i, 1, n) cin >> c[i];
    go(i, 1, n - 1) {
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    level[0] = -1;
    dfs(1, 0);

    cin >> q;
    while(q--) {
        cin >> u >> v;
        if (lca(u, v) == u) {
            cout << "INVALID" << endl;
            continue;
        }
        bool res;
        if (level[u] % 2 != level[v] % 2) {
            res = odd[1];
        } else {
            res = odd[1] ^ odd[u] ^ even[u];
        }
        cout << (res ? "YES" : "NO") << endl;
    }

#ifdef ZYC_LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
