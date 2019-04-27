#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
/* END:SYSLIB */

/* user-defined libraries */
#include "../../util/common.h"

/* below is the main program */
typedef unsigned char addr_t;
typedef unsigned char data_t;

char memory[257];

void str_to_mem(char* memory) {
    for (int i=0; i<256; i++) {
        if ('A' <= memory[i] && memory[i] <= 'F') {
            memory[i] = memory[i] - 'A' + 10;
        } else {
            memory[i] = memory[i] - '0';
        }
    }
}

void mem_to_str(char* memory) {
    for (int i=0; i<256; i++) {
        if (0 <= memory[i] && memory[i] <= 9) {
            memory[i] = '0' + memory[i];
        } else {
            memory[i] = 'A' + memory[i] - 10;
        }
    }
}

void fetch(char* memory, addr_t& PC, data_t& inst_code, addr_t& addr) {
    inst_code = memory[PC];
    if (inst_code == 0 || inst_code == 1 || inst_code == 6 || inst_code == 7) {
        addr = memory[PC+1] << 4 | memory[PC+2];
        PC += 2;
    }
    PC += 1;
}

void decode(char* memory, const data_t& inst_code, const addr_t& addr, data_t& data) {
    if (inst_code == 0) {
        data = memory[addr];
    }
}

void execute(
    char* memory, const data_t& inst_code, const addr_t& addr, const data_t& data,
    data_t& A, data_t& B, addr_t& PC, bool& stop_flag
) {
    data_t C;

    switch (inst_code) {
        case 0: A = data; break;
        case 1: memory[addr] = A; break;
        case 2: A = A ^ B; B = A ^ B; A = A ^ B; break;
        case 3: C = A + B; A = C & 0xF; B = (C & ~(0xF)) >> 4; break;
        case 4: if (A == 0xF) A = 0; else A = A + 1; break;
        case 5: if (A == 0) A = 0xF; else A = A - 1; break;
        case 6: if (A == 0) PC = addr; break;
        case 7: PC = addr; break;
        case 8: stop_flag = true; break;
    }
}

void run(char* memory) {
    addr_t PC = 0;
    data_t A, B;
    addr_t addr;
    data_t data;
    data_t inst_code;
    bool stop_flag = false;

    do {
        fetch(memory, PC, inst_code, addr);
        decode(memory, inst_code, addr, data);
        execute(memory, inst_code, addr, data, A, B, PC, stop_flag);
    } while (!stop_flag);
}

int main() {
    std::ios::sync_with_stdio(false);

    while (scanf("%s", memory) && memory[0] != '8') {
        str_to_mem(memory);
        run(memory);
        mem_to_str(memory);
        printf("%s\n", memory);
    }

    return 0;
}
