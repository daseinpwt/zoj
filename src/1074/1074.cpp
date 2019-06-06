#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
/* END:SYSLIB */

/* user-defined libraries */
#include "../../include/util/common.h"

/* below is the main program */
#define MAXN 120

int a[MAXN][MAXN];
int sum[MAXN][MAXN];

int main() {
    std::ios::sync_with_stdio(false);

    int N;
    int ans = -INF;

    cin >> N;
    loop(i, 1, N+1)
        loop(j, 1, N+1)
            cin >> a[i][j];

    fill2d(sum, N+1, N+1, 0);
    loop(i, 1, N+1)
        loop(j, 1, N+1) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
            loop(i2, 1, i+1)
                loop(j2, 1, j+1) {
                    ans = ds_max(ans, sum[i][j] - sum[i2-1][j] - sum[i][j2-1] + sum[i2-1][j2-1]);
                }
        }

    cout << ans << endl;
    return 0;
}
