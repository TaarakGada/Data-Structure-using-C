#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct node *insertBeginning(struct node *Head)
{
    int data;
    printf("Enter the value to be entered.\n");
    scanf("%d", &data);
    struct node *newNode = createNode(data);
    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    }
    return Head;
}

struct node *insertEnd(struct node *Head)
{
    int data;
    printf("Enter the value to be entered.\n");
    scanf("%d", &data);
    struct node *newNode = createNode(data);
    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        struct node *ptr = Head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newNode->prev = ptr;
        ptr->next = newNode;
    }
    return Head;
}

struct node *insertPosition(struct node *Head)
{
    int data, position;
    printf("Enter the value to be entered.\n");
    scanf("%d", &data);
    printf("Enter the position.\n");
    scanf("%d", &position);
    struct node *newNode = createNode(data);
    if (Head == NULL)
    {
        Head = newNode;
    }
    else if (position == 1)
    {
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    }
    else
    {
        struct node *ptr = Head;
        for (int i = 0; i < position - 2; i++)
        {
            ptr = ptr->next;
        }
        newNode->prev = ptr;
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    return Head;
}

struct node *deleteBeginning(struct node *Head)
{
    if (Head == NULL)
    {
        printf("Linked List is Empty!\n");
    }
    else if (Head->next == NULL)
    {
        Head = NULL;
        printf("Item is deleted and linked list is empty.\n");
    }
    else
    {
        Head = Head->next;
        Head->prev = NULL;
        printf("Item is deleted.\n");
    }
    return Head;
}

struct node *deleteEnd(struct node *Head)
{
    if (Head == NULL)
    {
        printf("Linked List is Empty!\n");
    }
    else if (Head->next == NULL)
    {
        Head = NULL;
        printf("Item deleted. Linked List is empty.\n");
    }
    else
    {
        struct node *ptr = Head;
        while ((ptr->next)->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NULL;
        printf("Item is deleted.\n");
    }
    return Head;
}

struct node *deleteValue(struct node *Head)
{
    int value;
    printf("Enter the value to be deleted.\n");
    scanf("%d", &value);
    if (Head == NULL)
    {
        printf("Linked List is Empty!\n");
    }
    else if (Head->data == value)
    {
        if (Head->next == NULL)
        {
            Head = NULL;
            printf("Item is deleted and linked list is empty.\n");
        }
        else
        {
            Head = Head->next;
            Head->prev = NULL;
            printf("Item is deleted.\n");
        }
    }
    else
    {
        struct node *ptr1 = Head;
        struct node *ptr2 = Head;
        while (ptr1->data != value)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = ptr1->next;
        printf("Item is deleted.\n");
    }
    return Head;
}

void display(struct node *Head)
{
    if (Head == NULL)
    {
        printf("Linked list is empty.");
    }
    else
    {
        struct node *ptr = Head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void main()
{
    struct node *Head = NULL;
    int choices;
    while (choices != 8)
    {
        printf("1. Insertion at beginning.\n2. Insertion at end.\n3. Insertion at a certain position.\n4. Deleting first element.\n5. Deleting last element.\n6. Deleting element with certain value.\n7. Display the linked list.\n8. Quit.\n");
        scanf("%d", &choices);
        switch (choices)
        {
        case 1:
            Head = insertBeginning(Head);
            break;
        case 2:
            Head = insertEnd(Head);
            break;
        case 3:
            Head = insertPosition(Head);
            break;
        case 4:
            Head = deleteBeginning(Head);
            break;
        case 5:
            Head = deleteEnd(Head);
            break;
        case 6:
            Head = deleteValue(Head);
            break;
        case 7:
            display(Head);
            break;
        case 8:
            break;
        default:
            printf("Enter a correct option.\n");
        }
    }
}