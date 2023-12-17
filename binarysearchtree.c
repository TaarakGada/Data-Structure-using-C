#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *leftChild;
    struct node *rightChild;
};
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = data;
    newNode->rightChild = NULL;
    newNode->leftChild = NULL;
    return newNode;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (root->value < data)
    {
        root->rightChild = insert(root->rightChild, data);
    }
    else if (root->value > data)
    {
        root->leftChild = insert(root->leftChild, data);
    }
    return root;
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->leftChild);
    printf("%d ", root->value);
    inorderTraversal(root->rightChild);
}

void postorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->leftChild);
    postorderTraversal(root->rightChild);
    printf("%d ", root->value);
}

void preorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->value);
    preorderTraversal(root->leftChild);
    preorderTraversal(root->rightChild);
}

void closestAncestor(int x, int y, struct node *root)
{
    if ((x <= root->value && y >= root->value) || (x >= root->value && y <= root->value))
    {
        printf("%d\n", root->value);
        return;
    }
    else if (x < root->value && y < root->value)
    {
        closestAncestor(x, y, root->leftChild);
        return;
    }
    else if (x > root->value && y > root->value)
    {
        closestAncestor(x, y, root->rightChild);
        return;
    }
}

void printBetweenXY(int x, int y, struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printBetweenXY(x, y, root->leftChild);
    if (x <= root->value && y >= root->value)
    {
        printf("%d ", root->value);
    }
    printBetweenXY(x, y, root->rightChild);
}

void findkthLargest(struct node *root, int *k, int *kthlargest)
{
    if (root == NULL || *k == 0)
    {
        return;
    }
    findkthLargest(root->rightChild, k, kthlargest);
    (*k)--;
    if (*k == 0)
    {
        *kthlargest = root->value;
        return;
    }
    findkthLargest(root->leftChild, k, kthlargest);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int calculateHeight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(calculateHeight(root->leftChild), calculateHeight(root->rightChild));
}

void isBalanced(struct node *root)
{
    int lsh = 0;
    lsh = lsh + calculateHeight(root->leftChild);
    int rsh = 0;
    rsh = rsh + calculateHeight(root->rightChild);
    printf("Height of left sub tree : %d\nHeight of right sub tree : %d\n", lsh, rsh);
    if ((lsh - rsh) == 0 || (lsh - rsh) == -1 || (lsh - rsh) == 1)
    {
        printf("The tree is balanced.\n");
    }
    else
    {
        printf("The tree is not balanced.\n");
    }
}

void main()
{
    int choice = 0;
    int data;
    int x, y, k, kthlargest;
    struct node *root = NULL;
    printf("Enter 1 to insert.\nEnter 2 for Inorder diaplay.\nEnter 3 for Postorder display.\nEnter 4 for Preorder display.\nEnter 5 to find the lowest common ancestor of 2 values.\nEnter 6 to find the kth largest element.\nEnter 7 to see if the bst is balanced.\nEnter 8 to print all the elements in the range k1 to k2.\nEnter 9 to end.\n");
    while (choice != 9)
    {
        printf("Enter an option.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be entered.\n");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            inorderTraversal(root);
            printf("\n");
            break;
        case 3:
            postorderTraversal(root);
            printf("\n");
            break;
        case 4:
            preorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Enter the 2 values whose closest ancestor you want to find.\n");
            printf("Enter the first value.\n");
            scanf("%d", &x);
            printf("Enter the second value.\n");
            scanf("%d", &y);
            closestAncestor(x, y, root);
            break;
        case 6:
            printf("Enter the value of k :\n");
            scanf("%d", &k);
            findkthLargest(root, &k, &kthlargest);
            printf("%d\n", kthlargest);
            break;
        case 7:
            isBalanced(root);
            break;
        case 8:
            printf("Enter the extremeties of the range to be printed.\n");
            printf("Enter the first value.\n");
            scanf("%d", &x);
            printf("Enter the second value.\n");
            scanf("%d", &y);
            printBetweenXY(x, y, root);
            printf("\n");
            break;
        case 9:
            isBalanced(root);
            break;
        default:
            printf("Enter a correct choice.\n");
            break;
        }
    }
}