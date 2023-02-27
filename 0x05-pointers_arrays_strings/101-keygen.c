#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 16

char* generate_password() {
    char* password = malloc(sizeof(char) * (PASSWORD_LENGTH + 1));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int charset_length = strlen(charset);
    srand(time(NULL));
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % charset_length];
    }
    password[PASSWORD_LENGTH] = '\0';
    return password;
}

int main() {
    char* password = generate_password();
    printf("Generated password: %s\n", password);
    free(password);
    return 0;
}

