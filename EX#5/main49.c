#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // 終止條件：只剩 1 個盤子時直接移動
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }

    // 第 1 步：將上面 n-1 個盤子從來源柱移到輔助柱
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // 第 2 步：將第 n 個盤子從來源柱移到目的柱
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);

    // 第 3 步：將輔助柱上的 n-1 個盤子移到目的柱
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3; // 盤子數量

    // 參數分別代表：盤子數、來源柱 (From)、目的柱 (To)、輔助柱 (Aux)
    towerOfHanoi(n, 'A', 'B', 'C'); 
    
    printf("\n");
    return 0;
}
