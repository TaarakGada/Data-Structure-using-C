#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    char expression[100];
    double stack[40];
    double result = 0;
    int j = -1;
    double num1 = 0, num2 = 0;
    printf("Enter the postfix expression.\n");
    gets(expression);
    // printf("The postfix expression is : %s.\n", expression);
    for (int i = 0; i < strlen(expression); i++)
    {
        char c = expression[i];
        if (isdigit(c))
        {
            j++;
            stack[j] = (double)(c - '0');
        }
        else
        {
            switch (c)
            {
            case '+':
                num2 = stack[j];
                num1 = stack[j - 1];
                result = num1 + num2;
                stack[j - 1] = result;
                break;
            case '-':
                num2 = stack[j];
                num1 = stack[j - 1];
                result = num1 - num2;
                stack[j - 1] = result;
                break;
            case '*':
                num2 = stack[j];
                num1 = stack[j - 1];
                result = num1 * num2;
                stack[j - 1] = result;
                break;
            case '/':
                num2 = stack[j];
                num1 = stack[j - 1];
                result = num1 / num2;
                stack[j - 1] = result;
                break;
            case '^':
                num2 = stack[j];
                num1 = stack[j - 1];
                result = pow(num1, num2);
                stack[j - 1] = result;
                break;
            default:
                printf("Enter a valid postfix expression.\n");
                break;
            }
            j--;
        }
    }
    printf("The final answer is : %.2f", result);
    return 0;
}