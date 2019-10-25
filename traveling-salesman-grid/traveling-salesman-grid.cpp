#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <cstdio>
#define MAXN 10

using namespace std;

typedef bitset<MAXN*MAXN>  bs;

int gx, gy;
int g[MAXN][MAXN][4];
const int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

struct Comp {
    bool operator () (const bs &i, const bs &j) const {
        return i.to_string() < j.to_string();
    }
};

map<bs, int, Comp> was;

bs w(1);



inline int getPosition(int x, int y) {
    return (y * MAXN + x);
}

int compute(int cx=0, int cy=0) {
    //cout << cx << " " << cy << endl;

    if(w.count() == (gy*gx)) {
        if(cy == cx || max(cx, cy) > 1)
            return 1000002;

        if(cy == 1)
            return g[0][0][1];
        return g[0][0][0];
    }

    if(was.find(w) != was.end())
        return was[w];

    int minimum = 1000002;

    for(int i = 0; i < 4; ++i) {

        int y = cy + dy[i];
        int x = cx + dx[i];
        int pos = getPosition(x, y);

        if(g[cy][cx][i] == -1 || w.test(pos))
            continue;
        //  cout << cx << " " << cy << ", to " <<x << " " << y << " pos: " << pos << endl;

        w.set(pos, true);
        minimum = min(minimum, g[cy][cx][i] + compute(x, y));
        w.set(pos, false);
    }

    was[w] = minimum;

    // cout << minimum << endl;
    // cout << "------------------" << endl;
    return minimum;
}


int main() {
    
    cin >> gy >> gx;

    fill(&g[0][0][0], &g[MAXN-1][MAXN-1][3], -1);

    for(int i = 0; i < gy; ++i)
        for(int j = 0; j < gx - 1; ++j) {
            cin >> g[i][j][0];
            g[i][j+1][2] = g[i][j][0];
        }

    for(int j = 0; j < gx; ++j)
        for(int i = 0; i < gy-1; ++i) {
            cin >> g[i][j][1];
            g[i+1][j][3] = g[i][j][1];
        }

    // cout << g[1][1][2] << endl;
    int answer = compute();

    if(answer > 1000000)
        cout << 0 << endl;
    else
        cout << answer << endl;

}
