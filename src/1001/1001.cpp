#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
/* END:SYSLIB */

/* user-defined libraries */
#include "../../util/common.h"

/* below is the main program */
int main() {
    std::ios::sync_with_stdio(false);

    int x, y;

    while (cin >> x >> y) {
        cout << x + y << endl;
    }

    return 0;
}
