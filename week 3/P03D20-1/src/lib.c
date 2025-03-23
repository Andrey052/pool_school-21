#include "lib.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is an operator
int isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); }

int isOperand(char c, char *infix, int i) {  //проерка на вхождение оператора в выражение
    return ((c == 's' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'i' && infix[i + 2] == 'n') ||
            (c == 'c' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'o' && infix[i + 2] == 's') ||
            (c == 't' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'a' && infix[i + 2] == 'n') ||
            (c == 'c' && i + 2 < (int)strlen(infix) && infix[i + 1] == 't' && infix[i + 2] == 'g') ||
            (c == 's' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'q' && infix[i + 2] == 'r' &&
             infix[i + 3] == 't') ||
            (c == 'l' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'n'));
}

char res_char(char *infix, int i, char c) {  //возвращение результатов сокращенно
    char res;
    if (c == 's' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'i' && infix[i + 2] == 'n') {
        res = 's';
    } else if (c == 'c' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'o' && infix[i + 2] == 's') {
        res = 'c';
    } else if (c == 't' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'a' && infix[i + 2] == 'n') {
        res = 't';
    } else if (c == 'c' && i + 2 < (int)strlen(infix) && infix[i + 1] == 't' && infix[i + 2] == 'g') {
        res = 'C';
    } else if (c == 's' && i + 3 < (int)strlen(infix) && infix[i + 1] == 'q' && infix[i + 2] == 'r' &&
               infix[i + 3] == 't') {
        res = 'S';
    } else if (c == 'l' && i + 1 < (int)strlen(infix) && infix[i + 1] == 'n') {
        res = 'l';
    } else {
        res = c;
    }
    return res;
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// Function to convert infix to postfix
void convertToPostfix(char *infix, char *postfix) {
    int i, j = 0, top = -1;
    char stack[MAX_SIZE] = {'0'}, num[MAX_SIZE];
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (c == ' ') continue;
        if (c == 'x') {
            postfix[j++] = 'x';
            postfix[j++] = ' ';
            continue;
        }
        if ((c >= '0' && c <= '9') || c == '-') {
            int k = 0;
            if (c == '-') {
                num[k++] = c;
                c = infix[++i];
            }
            while (c >= '0' && c <= '9') {
                num[k++] = c;
                c = infix[++i];
            }
            num[k] = '\0';
            for (int l = 0; l < k; l++) postfix[j++] = num[l];
            postfix[j++] = ' ';
            i--;  // откатываемся на предыдущий символ
        } else if (isOperator(c) || isOperand(c, infix, i)) {
            while (top != -1 && isOperator(stack[top]) && getPrecedence(stack[top]) >= getPrecedence(c)) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            char res = res_char(infix, i, c);
            if (res != '0') {
                stack[++top] = res;
                i++;
            }
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if (top != -1 && stack[top] == '(') top--;
        }
    }
    while (top != -1) {
        postfix[j++] = stack[top--];
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

// Функция для разбора выражения на токены
Token *parse_expression(char *expression, int *token_count, double x) {
    Token *tokens = malloc(MAX_TOKENS * sizeof(Token));
    char *token = expression;
    int count = 0;
    while (*token != '\0') {
        if (*token == ' ') {
            token++;
            continue;
        }
        if ((*token >= '0' && *token <= '9') || *token == '.') {
            char *num_str = malloc(20 * sizeof(char));
            int num_len = 0;
            while ((*token >= '0' && *token <= '9') || *token == '.') {
                num_str[num_len++] = *token;
                token++;
            }
            num_str[num_len] = '\0';
            tokens[count].token = num_str;
            tokens[count].type = 0;
            count++;
            // free(num_str);
        } else if (*token == 'x') {
            token++;
            tokens[count].token = malloc(20 * sizeof(char));
            sprintf(tokens[count].token, "%f", x);
            tokens[count].type = 0;
            count++;
        } else {
            tokens[count].token = malloc(2 * sizeof(char));
            tokens[count].token[0] = *token;
            tokens[count].token[1] = '\0';
            tokens[count].type = 1;
            count++;
            token++;
        }
    }

    *token_count = count;
    return tokens;
}

double switc_operator(char str, double operand1, double operand2) {
    double result = 0;
    switch (str) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                printf("Ошибка: деление на ноль\n");
                return 0;
            }
            break;
    }
    return result;
}

double calculate_expression(Token *tokens, int token_count) {
    double stack[token_count];
    stack[0] = 0;
    double operand2 = 0;
    double operand1 = 0;
    int stack_index = 0;
    for (int i = 0; i < token_count; i++) {
        if (tokens[i].type == 0) {
            stack[stack_index++] = atof(tokens[i].token);
        } else {
            if (tokens[i].token[0] == '+' || tokens[i].token[0] == '-' || tokens[i].token[0] == '*' ||
                tokens[i].token[0] == '/') {
                operand2 = stack[--stack_index];
                operand1 = stack[--stack_index];
                stack[stack_index++] = switc_operator(tokens[i].token[0], operand1, operand2);
            }
            switch (tokens[i].token[0]) {
                case 's':
                    stack[stack_index - 1] = sin(stack[stack_index - 1]);
                    break;
                case 'c':
                    stack[stack_index - 1] = cos(stack[stack_index - 1]);
                    break;
                case 't':
                    stack[stack_index - 1] = tan(stack[stack_index - 1]);
                    break;
                case 'C':
                    stack[stack_index - 1] = 1 / tan(stack[stack_index - 1]);
                    break;
                case 'S':
                    stack[stack_index - 1] = sqrt(stack[stack_index - 1]);
                    break;
                case 'l':
                    stack[stack_index - 1] = log(stack[stack_index - 1]);
                    break;
            }
        }
    }
    return stack[0];
}