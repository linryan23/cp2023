#include <stdio.h>

int main() {
int i; // 宣告一個整數變數 i

// 提示用戶輸入一個整數
printf("輸入一個整數：");

// 檢查 scanf 的返回值，確保成功讀取了一個整數
if (scanf("%d", &i) != 1) {
fprintf(stderr, "錯誤：無法讀取整數。\n");
return 1; // 返回錯誤碼
}

// 根據 i 的值進行不同的判斷
if (i < 100) {
printf("i < 100\n");
} else {
if ((i >= 100) && (i < 200)) {
printf("i >= 100 and i < 200\n");
} else {
printf("i >= 200\n");
}
}

return 0;
}