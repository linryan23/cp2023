#include <stdio.h>

int main() {
char ch; // 宣告一個字符型變數 ch

// 提示用戶輸入一個字符
printf("輸入一個字符：");

// 檢查 scanf 的返回值，確保成功讀取了一個字符
if (scanf("%c", &ch) != 1) {
fprintf(stderr, "錯誤：無法讀取字符。\n");
return 1; // 返回錯誤碼
}

// 檢查輸入的字符是否為 'a'
if (ch == 'a') {
printf("你輸入的是 'a'\n"); // 如果是 'a'，則印出相應的消息
} else {
printf("你輸入的不是 'a'\n"); // 如果不是 'a'，則印出相應的消息
}

return 0;
}