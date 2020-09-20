#include <bits/stdc++.h>
using namespace std;

const int inf = (1 << 28);
const double pi = (2.0 * acos(0.0));
const double eps = 1e-9;

typedef long long lli;

#define _rep(i, a, b, x) for (i = (a); i <= (b); i += x)
#define rep(i, n) _rep(i, 0, n - 1, 1)

const int MX = 100;
int n;
struct PointF {
  lli x, y, v;
  void scan() { cin >> x >> y >> v; }
};
PointF P[MX + 10];
///+ ve => ac turns left from ab , - ve => ac turn right from ab , 0=> same
///direction or just reverse - 0 or pi
#define _direction2d(a, b, c)                                                  \
  ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y))
int main(void) {

  int i, j, k;
  while (cin >> n) {
    rep(i, n) P[i].scan();
    lli a, b, ans = 0;
    rep(i, n) rep(j, n) {
      if (i >= j)
        continue;
      a = b = 0;
      rep(k, n) {
      //Here, at first, you are keeping the two fixed points on the line.
        if (_direction2d(P[i], P[j], P[k]) > 0)
          a += P[k].v;
        if (_direction2d(P[i], P[j], P[k]) < 0)
          b += P[k].v;
      }
      
      //You can shift the line slightly and keep the 
      //points in one side of the line
      ans = max(ans, min(a + P[i].v + P[j].v, b));
      ans = max(ans, min(a, b + P[i].v + P[j].v));
      
      //You can rotate the line slightly and keep the 
      //points in opposite side.
      ans = max(ans, min(a + P[i].v, b + P[j].v));
      ans = max(ans, min(a + P[j].v, b + P[i].v));
      
    }
    printf("%lld\n", ans);
  }
  return 0;}
