#include <stdio.h>

int main() {
char id[10]; // 用於存儲員工ID的變數（最多10個字符）
int hour; // 用於存儲工作時數的變數
double value, salary; // 用於每小時薪資和總薪資的變數

// 提示使用者輸入員工ID
printf("輸入員工ID（最多10個字符）：");

// 檢查scanf的返回值
if (scanf("%9s", id) != 1) {
fprintf(stderr, "錯誤：無法讀取員工ID。\n");
return 1; // 返回錯誤碼
}

// 提示使用者輸入工作時數
printf("\n輸入工作時數：");

// 檢查scanf的返回值
if (scanf("%d", &hour) != 1) {
fprintf(stderr, "錯誤：無法讀取工作時數。\n");
return 1; // 返回錯誤碼
}

// 提示使用者輸入每小時薪資
printf("\n每小時薪資：");

// 檢查scanf的返回值
if (scanf("%lf", &value) != 1) {
fprintf(stderr, "錯誤：無法讀取每小時薪資。\n");
return 1; // 返回錯誤碼
}

// 計算總薪資
salary = value * hour;

// 印出員工ID和薪資
printf("\n員工ID = %s\n薪資 = U$ %.2lf\n", id, salary);

return 0;
}