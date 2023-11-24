#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int index = 0, tmp_index = 0;
    char *tmp = (char *)malloc(strlen(s) * sizeof(char));
    int op_parentheses = 0, op_brackets = 0, op_braces = 0;

    while (index < strlen(s)) {
        switch(s[index]) {
            // For Parentheses
            case '(':
                op_parentheses++; 
                tmp[tmp_index++] = '(';
                break;
            case ')':
                if (tmp_index == 0) return false;
                if (op_parentheses <= 0 || tmp[tmp_index - 1] != '(') return false;
                else {
                    op_parentheses--;
                    tmp_index--; }
                break;

            //For Brackets
            case '[':
                op_brackets++; 
                tmp[tmp_index++] = '[';
                break;
            case ']':
                if (tmp_index == 0) return false;
                if (op_brackets <= 0 || tmp[tmp_index - 1] != '[') return false;
                else {
                    op_brackets--;
                    tmp_index--; }
                break;

            //For Braces
            case '{':
                op_braces++; 
                tmp[tmp_index++] = '{';
                break;
            case '}':
                if (tmp_index == 0) return false;
                if (op_braces <= 0 || tmp[tmp_index - 1] != '{') return false;
                else {
                    op_braces--;;
                    tmp_index--; }
                break;

            default:
                return false;
                break;
        }
        index++;
    }
    printf("parentheses: %d, brackets: %d, braces: %d\n", op_parentheses, op_brackets, op_braces);
    return !(op_parentheses + op_brackets + op_braces);
}

int main(void) {
    char *input1 = "()";
    char *input2 = "()[]{}";
    char *input3 = "(]";
    char *input4 = "(([]){})";

    //printf("output1: %d\n", isValid(input1));
    //printf("output2: %d\n", isValid(input2));
    printf("output3: %d\n", isValid(input3));
    printf("output4: %d\n", isValid(input4));

    return 0;
}