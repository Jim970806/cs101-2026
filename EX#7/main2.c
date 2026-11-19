#include <stdio.h>
#include <string.h>

typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

// 計算並輸出所有書籍的總價錢
void total_price(book_t books[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += books[i].price;
    }
    printf("Total Price: %d\n", total);
}

// 輸出所有書籍資料至螢幕
void list_books(book_t books[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s (Price: %d)\n", books[i].id, books[i].title, books[i].price);
    }
}

int main() {
    // 1. 建立 6 筆書籍資料
    book_t books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300,  "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550,  "Killers of the Flower Moon"},
        {5, 870,  "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };
    int n = 6;

    // 2. 將書籍結構資料寫入二進位檔 Book.bin
    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        printf("無法建立 Book.bin 檔案\n");
        return 1;
    }
    fwrite(books, sizeof(book_t), n, fp);
    fclose(fp);

    // 3. 呼叫函式輸出書籍資料與總價錢
    list_books(books, n);
    total_price(books, n);

    return 0;
}
