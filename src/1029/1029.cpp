#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
/* END:SYSLIB */

/* user-defined libraries */
#include "util/common.h"
#include "util/qsort.h"

/* below is the main program */
#define MAXN 210
struct Plan {
    int s;
    int t;
    bool finished;
} plans[MAXN];

int f[MAXN];
int pre[MAXN];
int T, N;

int cmp(Plan A, Plan B) {
    if (A.t < B.t) return -1;
    if (A.t > B.t) return 1;
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> T;

test_case_begin:
    cin >> N;
    loop(i, 0, N) {
        int s, t;
        cin >> s >> t;
        s = (s + 1) / 2;
        t = (t + 1) / 2;
        plans[i].s = ds_min(s, t);
        plans[i].t = ds_max(s, t);
        plans[i].finished = false;
    }
    ds_qsort(plans, 0, N-1, cmp);
    plans[N].t = INF;
    plans[N].finished = false;

    for (int turn = 1; ; turn++) {
        int j = 0;
        loop(i, 1, 201) {
            pre[i] = -1;
            f[i] = f[i-1];
            while (true) {
                while (plans[j].finished) j++;
                if (plans[j].t > i) break;
                if (f[plans[j].s - 1] + 1 > f[i]) {
                    f[i] = f[plans[j].s - 1] + 1;
                    pre[i] = j;
                }
                j++;
            }
        }

        if (f[200] == 0) {
            cout << (turn-1) * 10 << endl;
            break;
        }

        j = 200;
        while (j != 0) {
            if (pre[j] != -1) {
                plans[pre[j]].finished = true;
                j = plans[pre[j]].s - 1;
            } else {
                j = j - 1;
            }
        }
    }

    if (--T) goto test_case_begin;

    return 0;
}
