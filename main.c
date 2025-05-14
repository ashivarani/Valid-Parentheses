#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stack[strlen(s)];
    int top = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        char temp = s[i];
        if (temp == '(' || temp == '{' || temp == '[') {
            stack[++top] = temp;
        } else {
            if ((top == -1) ||
                (temp == ')' && stack[top] != '(') ||
                (temp == '}' && stack[top] != '{') ||
                (temp == ']' && stack[top] != '[')) {
                return false;
            }
            top--;
        }
    }
    return top == -1;
}

int main() {
    char input[100];
    printf("Enter a string of brackets: ");
    scanf("%s", input);
    if (isValid(input)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is invalid.\n");
    }
    return 0;
}
