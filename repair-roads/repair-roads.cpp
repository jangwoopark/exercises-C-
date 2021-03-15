#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 10000

int memo[MAXN][3];
vector<int> E[MAXN];

int solve(int x, int froot, int p) {
  int& ref = memo[x][froot];
  if(ref != -1) return ref;
  
  ref = froot == 1 ? 0 : 1;

  int children = 0;
  vector<int> C;
  for(int i = 0; i < E[x].size(); i++) {
    int v = E[x][i];
    if(v == p) continue;

    int res = solve(v, 0, x);
    ref += res;
    C.push_back(solve(v, 1, x) - res);
    children++;
  }
  sort(C.begin(), C.end());


  int r1 = ref;
  int charge = (froot == 1 ? 1 : 2);
  for(int i = 0; i < C.size(); i++) {
    r1 += C[i];
    if(i == charge) {
      r1++;
      charge += 2;
    }
    ref = min(ref, r1);
  }
  if(children == 0 && froot != 2) {
    ref = 0;
  }

//cout << x << ", " << froot << ", " << ref  << " (" << C.size() << ")" << endl;
  if(froot == 0) {
    int r2 = 0;
    for(int i = 0; i < E[x].size(); i++) {
      int v = E[x][i];
      if(v == p) continue;
      r2 += solve(v, 2, x);
    }
    ref = min(ref, r2);
  }

  return ref;
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int N; cin >> N;

    for(int i = 0; i < N; i++) E[i].clear();
    for(int i = 1; i < N; i++) {
      int u, v; cin >> u >> v;
      E[u].push_back(v);
      E[v].push_back(u);
    }

    memset(memo, -1, sizeof(memo));
    cout << solve(0, false, -1) << endl;
  }
}
