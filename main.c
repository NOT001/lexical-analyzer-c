#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void analyzeCode(char *code) {
    // setup keyword
    char *keywords[10] = {"while", "if", "else", "return", "break", "continue", "int", "float", "void", "for"};

    // T?o danh sách các lexeme
    char *lexemes[MAX];
    int lexemeCount = 0;

    // Tách các lexeme t? do?n mã
    char *token = strtok(code, " ");
    while (token != NULL) {
        int isKeyword = 0;
        for (int i = 0; i < 10; i++) {
            if (strcmp(token, keywords[i]) == 0) {
                lexemes[lexemeCount++] = token;
                isKeyword = 1;
                break;
            }
        }
        if (!isKeyword) {
            if (isdigit(token[0])) {
                lexemes[lexemeCount++] = token;
            } else if (isalpha(token[0])) {
                lexemes[lexemeCount++] = token;
            } else {
                lexemes[lexemeCount++] = token;
            }
        }
        token = strtok(NULL, " ");
    }

    // In k?t qu?
    printf("Class : Lexeme\n");
    for (int i = 0; i < lexemeCount; i++) {
        printf("%s\n", lexemes[i]);
    }
}

int main() {
    FILE *file = fopen("./File/Input.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    char code[MAX];
    char ch;
    int index = 0;

    while ((ch = fgetc(file)) != EOF) {
        code[index++] = ch;
    }
    code[index] = '\0';

    printf("%s\n", code);
    
    analyzeCode(code);

    fclose(file);

    return 0;
}

