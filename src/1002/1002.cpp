#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
/* END:SYSLIB */

/* user-defined libraries */
#include "../../include/util/common.h"

/* below is the main program */
#define MAXN 6

int N;
char map[MAXN][MAXN];
bool occupied_row[MAXN];
bool occupied_col[MAXN];

void dfs(int x, int y, int num, int *ans) {
    if (x == N) {
        if (num > *ans)
            *ans = num;
        return;
    } else if (map[x][y] == 'X') {
        occupied_row[x] = false;
        occupied_col[y] = false;
        if (y < N-1)
            dfs(x, y+1, num, ans);
        else
            dfs(x+1, 0, num, ans);
    } else {
        if (!occupied_row[x] && !occupied_col[y]) {
            occupied_row[x] = true;
            occupied_col[y] = true;
            if (y < N-1)
                dfs(x, y+1, num+1, ans);
            else
                dfs(x+1, 0, num+1, ans);
            occupied_row[x] = false;
            occupied_col[y] = false;
        }
        if (y < N-1)
            dfs(x, y+1, num, ans);
        else
            dfs(x+1, 0, num, ans);
    }
}

int main() {
    while (cin >> N && N) {
        for (int i=0; i<N; i++) {
            cin >> map[i];
        }

        for (int i=0; i<N; i++)
            occupied_row[i] = occupied_col[i] = false;

        int ans = 0;
        dfs(0, 0, 0, &ans);

        cout << ans << endl;
    }

    return 0;
}
