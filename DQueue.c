#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int menu();
int insert_front(int *front_index, int *back_index, int size, int *arr);
int insert_back(int *front_index, int *back_index, int size, int *arr);
int delete_front(int *front_index, int *back_index);
int delete_back(int *front_index, int *back_index);
int peek_back(int *front_index, int *back_index, int *arr);
int peek_front(int *front_index, int *back_index, int *arr);
int display(int *front_index, int *back_index, int *arr);
int isEmpty(int *front_index, int *back_index);
int isFullB(int *back_index, int size);
int isFullF(int *front_index);

int main()
{
    menu();
}

int menu()
{
    int size = 0;
    int front_index = -1;
    int back_index = -1;
    int option;
    printf("Enter the number of elements.\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter 1 to insert in front.\nEnter 2 to insert in back.\nEnter 3 to delete from front.\nEnter 4 to delete from rear.\nEnter 5 to display the Queue.\nEnter 6 to peek front element.\nEnter 7 to peek back element.\nEnter 8 to end.\n\n");
    while (option != 6)
    {
        printf("\nEnter an input.\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert_front(&front_index, &back_index, size, arr);
            break;

        case 2:
            insert_back(&front_index, &back_index, size, arr);
            break;

        case 3:
            delete_front(&front_index, &back_index);
            break;

        case 4:
            delete_back(&front_index, &back_index);
            break;

        case 5:
            display(&front_index, &back_index, arr);
            break;

        case 6:
            peek_front(&front_index, &back_index, arr);
            break;

        case 7:
            peek_back(&front_index, &back_index, arr);
            break;

        case 8:
            return 0;

        default:
            printf("Enter a correct input.\n");
            break;
        }
    }
}

int insert_front(int *front_index, int *back_index, int size, int *arr)
{
    int data;
    if (isFullF(front_index))
    {
        printf("Queue is full.\n");
    }
    else if (isEmpty(front_index, back_index))
    {
        printf("Enter the element to be inserted.\n");
        scanf("%d", &data);
        (*front_index)++;
        (*back_index)++;
        arr[*back_index] = data;
    }
    else
    {
        printf("Enter the element to be inserted.\n");
        scanf("%d", &data);
        (*front_index)--;
        arr[*front_index] = data;
    }
    return 0;
}

int insert_back(int *front_index, int *back_index, int size, int *arr)
{
    int data;
    if (isFullB(back_index, size))
    {
        printf("Queue is full.\n");
    }
    else if (isEmpty(front_index, back_index))
    {
        printf("Enter the element to be inserted.\n");
        scanf("%d", &data);
        (*front_index)++;
        (*back_index)++;
        arr[*back_index] = data;
    }
    else
    {
        printf("Enter the element to be inserted.\n");
        scanf("%d", &data);
        (*back_index)++;
        arr[*back_index] = data;
    }
    return 0;
}

int delete_front(int *front_index, int *back_index)
{
    if (isEmpty(front_index, back_index))
    {
        printf("Queue is empty.\n");
    }
    else if ((*front_index) == (*back_index))
    {
        (*front_index) = -1;
        (*back_index) = -1;
        printf("Element is deleted & queue is empty.\n");
    }
    else
    {
        (*front_index)++;
        printf("Element is deleted.\n");
    }
    return 0;
}

int delete_back(int *front_index, int *back_index)
{
    if (isEmpty(front_index, back_index))
    {
        printf("Queue is empty.\n");
    }
    else if ((*front_index) == (*back_index))
    {
        (*front_index) = -1;
        (*back_index) = -1;
        printf("Element is deleted & queue is empty.\n");
    }
    else
    {
        (*back_index)--;
        printf("Element is deleted.\n");
    }
    return 0;
}

int peek_back(int *front_index, int *back_index, int *arr)
{
    if (isEmpty(front_index, back_index))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("%d\n", arr[*back_index]);
    }
    return 0;
}

int peek_front(int *front_index, int *back_index, int *arr)
{
    if (isEmpty(front_index, back_index))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("%d\n", arr[*front_index]);
    }
    return 0;
}

int display(int *front_index, int *back_index, int *arr)
{
    if (isEmpty(front_index, back_index))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        for (int i = (*front_index); i <= (*back_index); i++)
        {
            printf("%d  ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}

int isEmpty(int *front_index, int *back_index)
{
    if ((*front_index) == -1 && (*back_index) == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFullB(int *back_index, int size)
{
    if ((*back_index) == (size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFullF(int *front_index)
{
    if ((*front_index) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
