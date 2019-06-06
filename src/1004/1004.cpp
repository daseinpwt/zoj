#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
/* END:SYSLIB */

/* user-defined libraries */
#include "../../include/util/common.h"

/* below is the main program */
#define MAXL 100

string source, target;
char stack[MAXL];
char opt[MAXL];

void dfs(int p, int end, int nstack) {
    if (p == end) {
        string temp = "";
        int sp = 0;
        int maxlen = source.length();
        int nstack = 0;

        for (int i=0; i<end; i++) {
            if (opt[i] == 'i') {
                if (sp == maxlen) return;
                stack[nstack++] = source[sp++];
            } else {
                temp += stack[--nstack];
            }
        }

        if (temp == target) {
            for (int i=0; i<end; i++)
                cout << opt[i] << ' ';
            cout << endl;
        }
        return;
    }

    opt[p] = 'i';
    dfs(p+1, end, nstack+1);

    if (nstack > 0) {
        opt[p] = 'o';
        dfs(p+1, end, nstack-1);
    }
}

int main() {

    while (cin >> source >> target) {
        cout << '[' << endl;
        dfs(0, 2*source.length(), 0);
        cout << ']' << endl;
    }

    return 0;
}
