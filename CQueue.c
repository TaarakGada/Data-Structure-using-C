#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int menu();
int insert(int *front_index, int *back_index, int size, int *arr);
int delete(int *front_index, int *back_index, int size);
int peek_back(int *front_index, int *back_index, int *arr);
int peek_front(int *front_index, int *back_index, int *arr);
int display(int *front_index, int *back_index, int *arr, int size);
int isEmpty(int *front_index, int *back_index);
int isFull(int *front_index, int *back_index, int size);

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
    printf("Enter 1 for insert. \nEnter 2 for delete. \nEnter 3 for display. \nEnter 4 to peek front element. \nEnter 5 to peek back element. \nEnter 6 to end.\n\n");
    while (option != 6)
    {
        printf("\nEnter an input.\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert(&front_index, &back_index, size, arr);
            break;

        case 2:
            delete (&front_index, &back_index, size);
            break;

        case 3:
            display(&front_index, &back_index, arr, size);
            break;

        case 4:
            peek_front(&front_index, &back_index, arr);
            break;

        case 5:
            peek_back(&front_index, &back_index, arr);
            break;

        case 6:
            return 0;

        default:
            printf("Enter a correct input.\n");
            break;
        }
    }
}

int insert(int *front_index, int *back_index, int size, int *arr)
{
    int data;
    if (isFull(front_index, back_index, size))
    {
        printf("Queue is full.\n");
    }
    else if (isEmpty(front_index, back_index))
    {
        printf("Enter the element to be inserted.\n");
        scanf("%d", &data);
        (*front_index) = ((*front_index) + 1) % size;
        (*back_index) = ((*back_index) + 1) % size;
        arr[*back_index] = data;
    }
    else
    {
        printf("Enter the element to be inserted.\n");
        scanf("%d", &data);
        (*back_index) = ((*back_index) + 1) % size;
        arr[*back_index] = data;
    }
    return 0;
}

int delete(int *front_index, int *back_index, int size)
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
        (*front_index) = ((*front_index) + 1) % size;
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

int display(int *front_index, int *back_index, int *arr, int size)
{
    if (isEmpty(front_index, back_index))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        if ((*front_index) <= (*back_index))
        {
            for (int i = (*front_index); i <= (*back_index); i++)
            {
                printf("%d ", arr[i]);
            }
        }
        else
        {
            for (int i = (*front_index); i < size; i++)
            {
                printf("%d ", arr[i]);
            }
            for (int i = 0; i <= (*back_index); i++)
            {
                printf("%d ", arr[i]);
            }
        }
    }
    printf("\n");
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

int isFull(int *front_index, int *back_index, int size)
{
    if ((*front_index) == (((*back_index) + 1) % size))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// debug
// printf("%d \n", (*front_index));
// printf("%d \n", (*back_index));
