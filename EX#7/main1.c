x#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 檢查數字是否已存在於陣列中
int is_duplicate(int arr[], int count, int num) {
    for (int i = 0; i < count; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

// 氣泡排序（將前 6 個號碼由小到大排序，符合範例格式）
void sort_numbers(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    // 1. 開機畫面與輸入
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    // 確保輸入範圍在 1 <= n <= 5
    while (n < 1 || n > 5) {
        printf("請輸入 1 到 5 之間的數字：");
        scanf("%d", &n);
    }

    // 2. 開啟輸出檔案 lotto.txt
    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法建立 lotto.txt 檔案\n");
        return 1;
    }

    // 3. 取得目前系統時間並移除 ctime() 結尾的換行符號
    time_t curtime;
    time(&curtime);
    char *time_str = ctime(&curtime);
    time_str[strcspn(time_str, "\n")] = '\0';

    // 設定亂數種子
    srand((unsigned)time(NULL));

    // 4. 寫入標頭與動態時間
    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_str);

    // 5. 產生 5 組輸出內容（前 n 組為亂數，其餘補 --）
    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "[%d]:", i);
        if (i <= n) {
            int lotto[7];
            // 產生 7 個 01 ~ 69 不重複的數字
            for (int j = 0; j < 7; j++) {
                int num;
                do {
                    num = rand() % 69 + 1;
                } while (is_duplicate(lotto, j, num));
                lotto[j] = num;
            }

            // 依範例格式將前 6 個號碼由小到大排序
            sort_numbers(lotto, 6);

            for (int j = 0; j < 7; j++) {
                fprintf(fp, " %02d", lotto[j]);
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, " -- -- -- -- -- -- --\n");
        }
    }

    // 6. 寫入結尾
    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
