#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MIN_LENGTH 8
#define MAX_INPUT 100

/**
 * @brief パスワードの強度をチェックし、結果を出力します。
 *
 * @param password チェックする文字列（パスワード）
 */
void check_password_strength(const char *password) {
    int length = strlen(password);
    bool is_strong = true;
    
    // 基準 1: 長さのチェック
    if (length < MIN_LENGTH) {
        printf("- ① パスワードの長さが%d文字未満です。%d文字以上にしてください。\n", MIN_LENGTH, MIN_LENGTH);
        is_strong = false;
    }

    // 基準 2: 大文字・小文字の両方を含むかのチェック
    bool has_upper = false;
    bool has_lower = false;
    
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_upper = true;
        }
        if (islower(password[i])) {
            has_lower = true;
        }
        // 両方見つかったらループを終了（最適化）
        if (has_upper && has_lower) {
            break;
        }
    }

    if (!has_upper) {
        printf("- ② 大文字が含まれていません。少なくとも1文字以上の大文字を使用してください。\n");
        is_strong = false;
    }
    
    if (!has_lower) {
        printf("- ② 小文字が含まれていません。少なくとも1文字以上の小文字を使用してください。\n");
        is_strong = false;
    }

    // 総合判定の出力
    printf("\n--- 総合判定 ---\n");
    if (is_strong) {
        printf("強力なパスワードです！\n");
    } else {
        printf("パスワードの強度に問題があります。上記の点を改善してください。\n");
    }
}

int main() {
    char password[MAX_INPUT];

    printf("--- C言語 パスワード強度チェックプログラム ---\n");
    printf("チェックしたいパスワードを入力してください (最大%d文字): ", MAX_INPUT - 1);

    // ユーザー入力の取得
    // fgetsを使用して、安全に文字列を読み込みます
    if (fgets(password, MAX_INPUT, stdin) == NULL) {
        fprintf(stderr, "エラー: 入力の読み込みに失敗しました。\n");
        return 1;
    }
    
    // fgetsは末尾に改行文字('\n')を含めるため、削除します
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }

    printf("\n【判定結果と改善点】\n");
    
    // パスワード強度のチェック実行
    check_password_strength(password);
    
    printf("--------------------------------------------\n");
    
    // 追加のヒント (一般的に強度を高める要素)
    printf("\n さらなるセキュリティ向上のためのヒント:\n");
    printf("- 数字や記号を含めると、パスワードはさらに強固になります。\n");
    
    return 0;
}