#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
/* END:SYSLIB */

/* user-defined libraries */
#include "util/common.h"

/* below is the main program */
#define MAXN 210

int f[MAXN];
int T, N;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> T;

test_case_begin:
    cin >> N;

    int ans = 0;
    fill1d(f, 201, 0);

    loop(i, 0, N) {
        int s, t;
        cin >> s >> t;
        if (s > t) swap(s, t);
        s = (s + 1) / 2;
        t = (t + 1) / 2;
        loop(j, s, t+1) f[j] += 1;
    }

    loop(i, 1, 201) ans = max(ans, f[i]);
    cout << ans * 10 << endl;

    if (--T) goto test_case_begin;

    return 0;
}
