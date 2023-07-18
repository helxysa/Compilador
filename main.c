#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    IF_TOKEN,
    IDENTIFICADOR_TOKEN,
    SIMBOLO_PONTUACAO_TOKEN,
    SIMBOLO_MAIOR_QUE_TOKEN,
    SIMBOLO_MENOR_QUE_TOKEN,
    SIMBOLO_MAIOR_OU_IGUAL_QUE_TOKEN,
    SIMBOLO_MENOR_OU_IGUAL_QUE_TOKEN,
    SIMBOLO_IGUALDADE_TOKEN,
    SIMBOLO_DIFERENCA_TOKEN,
    OPERADOR_ATRIBUICAO_TOKEN,
    OPERADOR_ADICAO_TOKEN,
    OPERADOR_SUBTRACAO_TOKEN,
    OPERADOR_MULTIPLICACAO_TOKEN,
    OPERADOR_DIVISAO_TOKEN,
    OPERADOR_RESTO_TOKEN,
    NUMERO_TOKEN
} TokenType;

void printToken(TokenType tokenType, char ch) {
    switch (tokenType) {
        case IF_TOKEN:
            printf("IF: Operador Condicional\n");
            break;
        case IDENTIFICADOR_TOKEN:
            printf("Identificador: ");
            break;
        case SIMBOLO_PONTUACAO_TOKEN:
            printf("Simbolo Pontuacao: ");
            break;
        case SIMBOLO_MAIOR_QUE_TOKEN:
            printf("Simbolo Maior Que: %c\n", ch);
            break;
        case SIMBOLO_MENOR_QUE_TOKEN:
            printf("Simbolo Menor Que: %c\n", ch);
            break;
        case SIMBOLO_MAIOR_OU_IGUAL_QUE_TOKEN:
            printf("Simbolo Maior ou Igual Que: %c%c\n", ch, ch);
            break;
        case SIMBOLO_MENOR_OU_IGUAL_QUE_TOKEN:
            printf("Simbolo Menor ou Igual Que: %c%c\n", ch, ch);
            break;
        case SIMBOLO_IGUALDADE_TOKEN:
            printf("Simbolo de Igualdade: %c\n", ch);
            break;
        case SIMBOLO_DIFERENCA_TOKEN:
            printf("Simbolo de Diferenca: %c%c\n", ch, ch);
            break;
        case OPERADOR_ATRIBUICAO_TOKEN:
            printf("Operador de Atribuicao: %c\n", ch);
            break;
        case OPERADOR_ADICAO_TOKEN:
            printf("Operador de Adicao: %c\n", ch);
            break;
        case OPERADOR_SUBTRACAO_TOKEN:
            printf("Operador de Subtracao: %c\n", ch);
            break;
        case OPERADOR_MULTIPLICACAO_TOKEN:
            printf("Operador de Multiplicacao: %c\n", ch);
            break;
        case OPERADOR_DIVISAO_TOKEN:
            printf("Operador de Divisao: %c\n", ch);
            break;
        case OPERADOR_RESTO_TOKEN:
            printf("Operador de Resto da Divisao: %c\n", ch);
            break;
        case NUMERO_TOKEN:
            printf("Numero: ");
            break;
        default:
            printf("Token desconhecido\n");
            break;
    }
}

int main() {
    char input[100];
    printf("Digite um comando IF da linguagem C: ");
    fgets(input, sizeof(input), stdin);

    // Converter a entrada para letras maiúsculas
    for (int i = 0; input[i]; i++) {
        input[i] = toupper(input[i]);
    }

    int length = strlen(input);
    int i = 0;

    while (i < length) {
        if (isspace(input[i])) {
            i++; // Ignorar espaços em branco
        } else if (isalpha(input[i])) {
            // Identificadores começam com uma letra
            char temp[10];
            int k = 0;
            while (isalpha(input[i]) && k < 9) {
                temp[k] = input[i];
                k++;
                i++;
            }
            temp[k] = '\0';
            i--;

            if (strcmp(temp, "IF") == 0) {
                printf("IF: Operador Condicional\n");
            } else {
                printf("Identificador: %s\n", temp);
            }
            i++;
        } else if (isdigit(input[i])) {
            // Números
            printf("Numero: %c", input[i]);
            i++;
            while (isdigit(input[i])) {
                printf("%c", input[i]);
                i++;
            }
            printf("\n");
        } else if (input[i] == '>') {
            // Simbolo >
            printf(input[i + 1] == '=' ? "Simbolo Maior ou Igual Que: %c%c\n" : "Simbolo Maior Que: %c\n", input[i], input[i + 1]);
            i += (input[i + 1] == '=') ? 2 : 1;
        } else if (input[i] == '<') {
            // Simbolo <
            printf(input[i + 1] == '=' ? "Simbolo Menor ou Igual Que: %c%c\n" : "Simbolo Menor Que: %c\n", input[i], input[i + 1]);
            i += (input[i + 1] == '=') ? 2 : 1;
        } else if (input[i] == '=') {
            // Operador de Atribuição ou de Igualdade
            printf(input[i + 1] == '=' ? "Simbolo de Igualdade: %c%c\n" : "Operador de Atribuicao: %c\n", input[i], input[i + 1]);
            i += (input[i + 1] == '=') ? 2 : 1;
        } else if (input[i] == '!') {
            // Simbolo de Diferenca
            printf(input[i + 1] == '=' ? "Simbolo de Diferenca: %c%c\n" : "Token não reconhecido: %c\n", input[i], input[i + 1]);
            i += (input[i + 1] == '=') ? 2 : 1;
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%') {
            // Operadores aritméticos
            switch (input[i]) {
                case '+':
                    printf("Operador de Adicao: %c\n", input[i]);
                    break;
                case '-':
                    printf("Operador de Subtracao: %c\n", input[i]);
                    break;
                case '*':
                    printf("Operador de Multiplicacao: %c\n", input[i]);
                    break;
                case '/':
                    printf("Operador de Divisao: %c\n", input[i]);
                    break;
                case '%':
                    printf("Operador de Resto da Divisao: %c\n", input[i]);
                    break;
            }
            i++;
        } else if (input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || input[i] == ';') {
            // Outros símbolos de pontuação
            printf("Simbolo Pontuacao: %c\n", input[i]);
            i++;
        } else {
            printf("Token não reconhecido: %c\n", input[i]);
            i++;
        }
    }

    return 0;
}
