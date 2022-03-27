//
// Created by eagle on 2022/3/26.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/*
 * 1. 根据声明一个二维数组，存储每个牌堆
 * 2. 取每个数组第一个元素比较大小，选取最大的元素
 * 3. 取每个数组最后个元素比较大小，选取最大的元素
 */
int main() {
    int n;
    scanf("%d", &n);
    int **card = (int **) malloc(n * sizeof(int *));
    int i, j, total = 0;
    for (i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        total += num;
        // 数组前三项存：长度，头指针，尾指针
        card[i] = (int *) malloc((num + 3) * sizeof(int));
        card[i][0] = num;
        card[i][1] = 3;
        card[i][2] = num + 2;
        for (j = 3; j <= num + 2; ++j) {
            scanf("%d", &card[i][j]);
        }
    }
    long long sumA = 0, sumB = 0;
    int a_num = (total + 1) / 2;
    int a;
    for (a = 0; a <= a_num; ++a) {
        int maxTop = 0, maxBottom = 0, topPos = 0, bottomPos = 0;
        //抽牌
        for (i = 0; i < n; i++) {
            if (card[i][1] <= card[i][2]) {
                int i_top = card[i][1];
                if (maxTop < card[i][i_top]) {
                    maxTop = card[i][i_top];
                    topPos = i;
                }
            }
        }
        card[topPos][1]++;
        for (i = 0; i < n; i++) {
            if (card[i][1] <= card[i][2]) {
                int i_bot = card[i][2];
                if (maxBottom < card[i][i_bot]) {
                    maxBottom = card[i][i_bot];
                    bottomPos = i;
                }
            }
        }
        card[bottomPos][2]--;
        sumA += maxTop;
        sumB += maxBottom;
    }
    printf("%lld %lld", sumA, sumB);
    return 0;
}
