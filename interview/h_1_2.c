//
// Created by eagle on 2022/3/23.
//

#include "stdio.h"

// 0 - 未知 1 - 真 -1 - 假
void set_flag(int flag, int verify[], int bal[]);

int main() {
    int balance[8][14] = {{1,  2,  7,  8,  13, 14, 19, 20, 25, 26, 31, 32, 37, 38},
                          {0,  4,  5,  10, 11, 16, 17, 22, 23, 28, 29, 34, 35, 40},

                          {0,  3,  6,  11, 13, 14, 16, 21, 24, 29, 31, 32, 34, 39},
                          {2,  4,  5,  7,  12, 15, 20, 22, 23, 25, 30, 33, 38, 40},


                          {5,  7,  9,  11, 13, 14, 16, 18, 20, 22, 33, 35, 37, 39},
                          {0,  6,  8,  10, 12, 15, 17, 19, 21, 32, 34, 36, 38, 40},

                          {0,  15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39},
                          {14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40}};

    char str[4];
    int verify[41] = {0};
    verify[0] = 1;
    // scanf("%s",str)!=EOF
    while (gets(str)) {
        if (str[0] == '\0') break;
        int b_i = 0;
        for (int i = 0; i < 4; ++i) {
            switch (str[i]) {
                case '=':
                    set_flag(1, verify, balance[b_i]);
                    set_flag(1, verify, balance[b_i + 1]);
                    break;
                case '>':
                    set_flag(1, verify, balance[b_i]);
                    set_flag(-1, verify, balance[b_i + 1]);
                    break;
                case '<':
                    set_flag(-1, verify, balance[b_i]);
                    set_flag(1, verify, balance[b_i + 1]);
                    break;
            }
            b_i += 2;
        }
//        printf("%s",str);
    }
    return 0;
}

void set_flag(int flag, int verify[], int bal[]) {
    for (int i = 0; i < 14; ++i) {
        if (verify[bal[i]] != 1) {
            verify[bal[i]] = flag;
        }
    }
}