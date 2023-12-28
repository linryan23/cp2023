#include <stdio.h>

int main() {
char c; // 宣告一個字符型變數 c

// 提示用戶輸入一個字符
printf("輸入一個字符：");

// 檢查 scanf 的返回值，確保成功讀取了一個字符
if (scanf(" %c", &c) != 1) {
fprintf(stderr, "錯誤：無法讀取字符。\n");
return 1; // 返回錯誤碼
}

// 使用 switch 陳述式根據讀取的字符執行相應的分支
switch(c) {
case 'a':
printf("你按下了 'a'\n");
break;
case 'b':
printf("你按下了 'b'\n");
break;
case 'c':
printf("你按下了 'c'\n");
break;
default:
printf("不是 'a'、'b' 或 'c'\n");
break;
}

return 0;
}