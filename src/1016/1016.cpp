#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
/* END:SYSLIB */

/* user-defined libraries */
#include "../../util/common.h"

/* below is the main program */
int T, N;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> N;
        string temp = "";
        int last = 0;
        int t;
        for (int i=0; i<N; i++) {
            cin >> t;
            for (int i=last+1; i<=t; i++) {
                temp += '(';
            }
            temp += ')';
            last = t;
        }

        int cnt, level;
        bool first = true;
        for (int i=0; i<temp.length(); i++) {
            if (temp[i] == ')') {
                cnt = level = 0;
                for (int j=i; j>=0; j--) {
                    if (temp[j] == ')') {
                        ++cnt;
                        ++level;
                    }
                    if (temp[j] == '(') {
                        if (--level == 0) break;
                    }
                }
                if (first) {
                    first = false;
                    cout << cnt;
                } else {
                    cout << ' ' << cnt;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
