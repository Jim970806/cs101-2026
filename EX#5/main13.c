#include <stdio.h>

void multi(int i, int j) {
    // 當被乘數 i 超過 9 時全部結束
    if (i > 9) {
        return;
    }

    // 當乘數 j 超過 9 時換行，並將被乘數 +1、乘數重設為 1
    if (j > 9) {
        printf("\n");
        multi(i + 1, 1);
        return;
    }

    // 印出當前的乘法式子
    printf("%d*%d=%-2d\t", i, j, i * j);

    // 遞迴呼叫下一個 j
    multi(i, j + 1);
}

int main() {
    // 從 1*1 開始執行
    multi(1, 1);
    return 0;
}
