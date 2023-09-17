#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int pop(int *index);                      // Removes top element.
int push(int *index, int size, int *arr); // Adds element to stack.
int top(int *index, int *arr);            // Displays top element.
int display(int *index, int *arr);        // Displays whole stack.
int isEmpty(int *index);
int isFull(int *index, int size);
int menu();

int main()
{
    menu();
    return 0;
}

int menu()
{
    int size = 0;
    int index = -1;
    int option;
    printf("Enter the number of elements.\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter 1 for push. \nEnter 2 for pop. \nEnter 3 for disply. \nEnter 4 to return top element. \nEnter 5 to end.\n\n");
    while (option != 5)
    {
        printf("\nEnter an input.\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            push(&index, size, arr);
            break;

        case 2:
            pop(&index);
            break;

        case 3:
            display(&index, arr);
            break;

        case 4:
            top(&index, arr);
            break;

        case 5:
            return 0;

        default:
            printf("Enter a correct input.\n");
            break;
        }
    }
}

int isFull(int *index, int size)
{
    if ((size - 1) == *index)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(int *index)
{
    if ((*index) == (-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(int *index, int size, int *arr)
{

    if (isFull(index, size))
    {
        printf("Stack is full.\n");
    }
    else
    {
        int data;
        printf("Enter the element to be pushed.\n");
        scanf("%d", &data);
        (*index)++;
        // *(arr + *index) = data;
        arr[*index] = data;
    }
    return 0;
}

int pop(int *index)
{
    if (isEmpty(index))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        (*index)--;
        printf("Element is popped.\n");
        // printf("%d\n",*index);
    }
    return 0;
}

int display(int *index, int *arr)
{
    if (isEmpty(index))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        for (int i = 0; i <= *index; i++)
        {
            printf("%d  ", arr[i]);
        }
    }
    return 0;
}

int top(int *index, int *arr)
{
    if (isEmpty(index))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("%d", arr[*index]);
    }
    return 0;
}
