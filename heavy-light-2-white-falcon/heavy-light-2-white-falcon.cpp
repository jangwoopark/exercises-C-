#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

template<int MOD>
struct mod_int {
    static const int Mod = MOD;
    unsigned x;
    mod_int() : x(0) { }
    mod_int(int sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
    mod_int(long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
    int get() const { return (int)x; }

    mod_int &operator+=(mod_int that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    mod_int &operator-=(mod_int that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    mod_int &operator*=(mod_int that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    mod_int &operator/=(mod_int that) { return *this *= that.inverse(); }

    mod_int operator+(mod_int that) const { return mod_int(*this) += that; }
    mod_int operator-(mod_int that) const { return mod_int(*this) -= that; }
    mod_int operator*(mod_int that) const { return mod_int(*this) *= that; }
    mod_int operator/(mod_int that) const { return mod_int(*this) /= that; }

    mod_int inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        return mod_int(u);
    }
};

using mint = mod_int<mod>;

struct RS {
    using type = mint;
    static type id() { return 0; }
    static type op(const type& l, const type & r) {
        return l + r;
    }
};

class lct_node {
    using M = RS;
    using T = typename M::type;
    using U = pair<mint, mint>;

    lct_node *l, *r, *p;
    bool rev;
    T val, all;
    int size;
    bool flag;
    U lazy;

    int pos() {
        if (p && p->l == this) return 1;
        if (p && p->r == this) return 3;
        return 0;
    }
    void update() {
        size = (l ? l->size : 0) + (r ? r->size : 0) + 1;
        all = M::op(l ? l->all : M::id(), M::op(val, r ? r->all : M::id()));
    }
    void update_lazy(const U& v) {
        if (!flag) lazy = make_pair(0, 0);
        int ls = !rev ? (l ? l->size : 0) : (r ? r->size : 0);
        val += v.first + v.second * ls;
        all += v.first * size + ((v.second * (size - 1)) * size) / 2;
        lazy = make_pair(M::op(lazy.first, v.first), M::op(lazy.second, v.second));
        flag = true;
    }
    void rev_data() {
        lazy = make_pair(lazy.first + lazy.second * (size - 1), mint(0) - lazy.second);
    }
    void push() {
        if (pos()) p->push();
        if (rev) {
            swap(l, r);
            if (l) l->rev ^= true, l->rev_data();
            if (r) r->rev ^= true, r->rev_data();
            rev = false;
        }
        if (flag) {
            if (l) l->update_lazy(lazy);
            if (r) r->update_lazy(make_pair(lazy.first + lazy.second * (l ? l->size + 1 : 1), lazy.second));
            flag = false;
        }
    }
    void rot() {
        lct_node *par = p;
        lct_node *mid;
        if (p->l == this) {
            mid = r;
            r = par;
            par->l = mid;
        }
        else {
            mid = l;
            l = par;
            par->r = mid;
        }
        if (mid) mid->p = par;
        p = par->p;
        par->p = this;
        if (p && p->l == par) p->l = this;
        if (p && p->r == par) p->r = this;
        par->update();
        update();
    }
    void splay() {
        push();
        while (pos()) {
            int st = pos() ^ p->pos();
            if (!st) p->rot(), rot();
            else if (st == 2) rot(), rot();
            else rot();
        }
    }

public:
    lct_node() : l(nullptr), r(nullptr), p(nullptr), rev(false), val(M::id()), all(M::id()), size(1), flag(false) {}
    void expose() {
        for (lct_node *x = this, *y = nullptr; x; y = x, x = x->p) x->splay(), x->r = y, x->update();
        splay();
    }
    void link(lct_node *x) {
        x->expose();
        expose();
        p = x;
    }
    void evert() {
        expose();
        rev = true;
        rev_data();
    }
    T find() {
        expose();
        return all;
    }
    void update(U v) {
        expose();
        update_lazy(v);
    }
};

const int MAX = 5e4;
lct_node lct[MAX];

void build(int v, int prev, const vector<vector<int>>& G) {
    for (int to : G[v]) if (to != prev) {
        lct[to].link(&lct[v]);
        build(to, v, G);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    build(0, -1, G);
    while (Q--) {
        int com, u, v;
        cin >> com >> u >> v;
        if (com == 1) {
            int x;
            cin >> x;
            lct[u].evert();
            lct[v].update(make_pair(mint(x), mint(x)));
        }
        else {
            lct[u].evert();
            printf("%d\n", lct[v].find().get());
        }
    }
    return 0;
}
