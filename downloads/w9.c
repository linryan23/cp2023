#include <stdio.h>
#include <string.h>

int main() {
    // 打開用戶文件以供讀取
    FILE* user_file = fopen("w9.c");
    if (user_file == NULL) {
        perror("Error opening user file");
        return 1;
    }

    char line[100]; // 假定每行最多100個字符

    char valid_users[100][20]; // 假定最多100個有效使用者，每個使用者ID長度為20個字符
    int valid_user_count = 0;

    // 從用戶文件讀取並儲存學號
    while (fgets(line, sizeof(line), user_file)) {
        line[strcspn(line, "\n")] = '\0'; // 移除換行符號
        strcpy(valid_users[valid_user_count], line);
        valid_user_count++;
    }

    // 關閉用戶文件
    fclose(user_file);

    // 打開CAD文件以供讀取
    FILE* cad_file = fopen("cad2023_2b_w8.txt", "r");
    if (cad_file == NULL) {
        perror("Error opening CAD file");
        return 1;
    }

    char unique_users[100][20]; // 假定最多100個獨特使用者，每個使用者ID長度為20個字符
    int unique_user_count = 0;

    // 逐行讀取CAD文件
    while (fgets(line, sizeof(line), cad_file)) {
        char* token = strtok(line, " "); // 以空格分割行
        if (token != NULL && strstr(token, "cad") == token) {
            // 提取學號（跳過"cad"前綴）
            char student_number[20]; // 假定學號最長20個字符
            strcpy(student_number, token + 3); // 跳過"cad"

            // 檢查學號是否在有效使用者列表中且不是重複的
            int is_valid = 0;
            for (int i = 0; i < valid_user_count; i++) {
                if (strcmp(valid_users[i], student_number) == 0) {
                    is_valid = 1;
                    break;
                }
            }

            // 如果是有效的且不是重複的，則將學號添加到unique_users列表中
            if (is_valid) {
                int is_duplicate = 0;
                for (int i = 0; i < unique_user_count; i++) {
                    if (strcmp(unique_users[i], student_number) == 0) {
                        is_duplicate = 1;
                        break;
                    }
                }

                if (!is_duplicate) {
                    strcpy(unique_users[unique_user_count], student_number);
                    unique_user_count++;
                }
            }
        }
    }

    // 反轉獨特學號的順序
    for (int i = 0; i < unique_user_count / 2; i++) {
        char temp[20];
        strcpy(temp, unique_users[i]);
        strcpy(unique_users[i], unique_users[unique_user_count - 1 - i]);
        strcpy(unique_users[unique_user_count - 1 - i], temp);
    }

    // 以相反的順序列印獨特學號
    for (int i = 0; i < unique_user_count; i++) {
        printf("%s\n", unique_users[i]);
    }

    // 關閉CAD文件
    fclose(cad_file);

    return 0;
}
