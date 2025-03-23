#ifndef LIB_H_
#define LIB_H_

#define MAX_SIZE 100
#define MAX_TOKENS 100
#define NUM_STEPS 80
#define W 25
#define H 80

// Структура для хранения токенов
typedef struct {
    char *token;
    int type;  // 0 - число, 1 - оператор
} Token;

int isOperator(char c);
int isOperand(char c, char *infix, int i);
char res_char(char *infix, int i, char c);
int getPrecedence(char c);
void convertToPostfix(char *infix, char *postfix);
Token *parse_expression(char *expression, int *token_count, double x);
double switc_operator(char str, double operand1, double operand2);
double calculate_expression(Token *tokens, int token_count);

#endif