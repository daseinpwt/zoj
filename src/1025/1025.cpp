#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
/* END:SYSLIB */

/* user-defined libraries */
#include "../../util/common.h"
#include "../../util/qsort.h"

/* below is the main program */
#define MAXN 5010

struct Stick {
  int l, w;

  static int cmp(Stick a, Stick b) {
    if (a.l == b.l && a.w == b.w) return 0;
    if (a.l < b.l || (a.l == b.l && a.w < b.w)) return -1;
    return 1;
  }
} sticks[MAXN];

int f[MAXN];

int main() {
    std::ios::sync_with_stdio(false);

    int T;
    
    cin >> T;
    while (T--) {
      int N, ans;

      cin >> N;
      loop(i, 0, N) cin >> sticks[i].l >> sticks[i].w;
      ds_qsort(sticks, 0, N-1, Stick::cmp);
      fill1d(f, N+1, 1);
      sticks[N].w = -1;

      loop(i, 0, N+1)
        loop(j, 0, i)
          if (sticks[i].w < sticks[j].w && f[j] + 1 > f[i]) {
            f[i] = f[j] + 1;
          }

      ans = f[N] - 1;
      cout << ans << endl;
    }

    return 0;
}
