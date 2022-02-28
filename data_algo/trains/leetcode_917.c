//
// Created by eagle on 2022/2/23.
//
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int isAlpha(char c);

void swap(char *a, char *b);

char *reverseOnlyLetters(char *s);

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int main() {
    char s[] = "abb7_28]aaa";
    reverseOnlyLetters(s);
    printf("%s", s);
    int num[] = {1, 2, 4, 5, 6};
    int *res = NULL;
    int *rss = twoSum(num, 5, 9, res);
    for (int i = 0; i < 2; ++i) {
        printf("%d", rss[i]);
    }
    printf("%d", 70 % 10);
}


char *reverseOnlyLetters(char *s) {
    int len = strlen(s);
    int low = 0;
    int high = len - 1;
    for (int i = 0; i < len; i++) {
        if (low < high) {
            while (isAlpha(s[low]) < 0) low++;
            while (isAlpha(s[high]) < 0) high--;
            if (low < high) {
                swap(&s[low], &s[high]);
                low++;
                high--;
            }
        }
    }
    return s;
}

int isAlpha(char c) {
    if ((c > 64 && c < 91) || (c > 96 && c < 123)) {
        return 1;
    }
    return -1;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    returnSize = (int *) malloc(2 * sizeof(int));
    int b;
    for (int i = 0; i < numsSize; i++) {
        returnSize[0] = i;
        b = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == b) {
                returnSize[1] = j;
                return returnSize;
            }
        }
    }
    return returnSize;
}
