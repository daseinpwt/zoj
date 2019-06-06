#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
/* END:SYSLIB */

/* user-defined libraries */
#include "../../include/util/common.h"

/* below is the main program */
#define MAXV 1010
#define ACT_FILL_A 0
#define ACT_FILL_B 1
#define ACT_POUR_A_B 2
#define ACT_POUR_B_A 3
#define ACT_EMPTY_A 4
#define ACT_EMPTY_B 5

struct Status {
    int x, y;
    int pre;
    int pre_act;
} bfsq[MAXV * MAXV];
int head, tail;

bool inq[MAXV][MAXV];

void push(int x, int y, int pre, int pre_act) {
    if (inq[x][y]) return;
    inq[x][y] = true;
    tail++;
    bfsq[tail].x = x;
    bfsq[tail].y = y;
    bfsq[tail].pre = pre;
    bfsq[tail].pre_act = pre_act;
}

int pour(int x, int y, int cy) {
    return ds_min(cy-y, x);
}

void print_solution(int p) {
    if (p == -1) return;
    print_solution(bfsq[p].pre);
    switch (bfsq[p].pre_act) {
        case ACT_FILL_A: cout << "fill A" << endl; break;
        case ACT_FILL_B: cout << "fill B" << endl; break;
        case ACT_EMPTY_A: cout << "empty A" << endl; break;
        case ACT_EMPTY_B: cout << "empty B" << endl; break;
        case ACT_POUR_A_B: cout << "pour A B" << endl; break;
        case ACT_POUR_B_A: cout << "pour B A" << endl; break;
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    int CA, CB, N;
    while (cin >> CA >> CB >> N) {
        Status *s;
        int temp;

        fill2d(inq, MAXV, MAXV, false);
        head = tail = 0;
        push(0, 0, -1, -1);
        while (head < tail) {
            head++;
            s = &bfsq[head];
            if (s->x == N || s->y == N) break;
            push(CA, s->y, head, ACT_FILL_A);
            push(s->x, CB, head, ACT_FILL_B);
            push(0, s->y, head, ACT_EMPTY_A);
            push(s->x, 0, head, ACT_EMPTY_B);
            temp = pour(s->x, s->y, CB);
            push(s->x - temp, s->y + temp, head, ACT_POUR_A_B);
            temp = pour(s->y, s->x, CA);
            push(s->x + temp, s->y - temp, head, ACT_POUR_B_A);
        }
        print_solution(head);
        cout << "success" << endl;
    }

    return 0;
}
