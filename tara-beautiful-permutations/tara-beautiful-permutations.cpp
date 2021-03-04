#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <assert.h>
#define IOS ios::sync_with_stdio(false)
using namespace std;
#define inf (0x3f3f3f3f)
typedef long long int LL;


#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
const int MOD = 1e9 + 7;
LL quick_pow(LL a, LL b, LL MOD) {  //求解 a^b%MOD的值
    LL base = a % MOD;
    LL ans = 1; //相乘，所以这里是1
    while (b) {
        if (b & 1) {
            ans = (ans * base) % MOD; //如果这里是很大的数据，就要用quick_mul
        }
        base = (base * base) % MOD;    //notice。注意这里,每次的base是自己base倍
        b >>= 1;
    }
    return ans;
}

LL C(LL n, LL m, LL MOD) {
    if (n < m) return 0; //防止sb地在循环，在lucas的时候
    if (n == m) return 1;
    LL ans1 = 1;
    LL ans2 = 1;
    LL mx = max(n - m, m); //这个也是必要的。能约就约最大的那个
    LL mi = n - mx;
    for (int i = 1; i <= mi; ++i) {
        ans1 = ans1 * (mx + i) %MOD;
        ans2 = ans2 * i % MOD;
    }
    return (ans1 * quick_pow(ans2, MOD - 2, MOD) % MOD); //这里放到最后进行,不然会很慢
}
const int maxn = 2000 + 20;
int a[maxn];
map<int, int>book;
LL A(int n, int has, int MOD) {
    LL ans1 = 1;
    LL ans2 = 1;
    for (int i = 1; i <= n; ++i) {
        ans1 = ans1 * i % MOD;
    }
    for (int i = 1; i <= has; ++i) {
        ans2 = ans2 * 2 % MOD;
    }
    return (ans1 * quick_pow(ans2, MOD - 2, MOD) % MOD);
}
void work() {
    book.clear();
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        book[a[i]]++;
    }
    int all = 0;
    for (map<int, int> :: iterator it = book.begin(); it != book.end(); it++) {
        if (it->second == 2) {
            all++;
        }
    }
//    cout << all << endl;
    LL ans = A(n, all, MOD);
    if (all == 0) {
        cout << ans << endl;
        return;
    }
//    cout << ans << endl;
    for (int i = 1; i <= all; ++i) {
        if (i & 1) {
            ans = (ans + MOD - C(all, i, MOD) * A(n - i, all - i, MOD) % MOD) % MOD;
        } else {
            ans = (ans + C(all, i, MOD) * A(n - i, all - i, MOD) % MOD) % MOD;
        }
    }
    cout << ans << endl;
}

int main() {
#ifdef local
    freopen("data.txt", "r", stdin);
//    freopen("data.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) work();
    return 0;
}
