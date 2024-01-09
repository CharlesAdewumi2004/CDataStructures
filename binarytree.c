#include <stdio.h>
#include <stdlib.h>
struct binarytree
{
    int data;
    struct binarytree *pLeftNode;
    struct binarytree *pRightNode;
    struct binarytree *pPrevNodecd;
};
typedef struct binarytree binarytree;
int addNode(binarytree **pRootNodePointer, int newElement);
void preOrderTraversal(binarytree *pRootNodePointer);
void postOrderTraversal(binarytree *pRootNodePointer);
void inOrderTraversal(binarytree *pRootNodePointer);
int searchTree(binarytree *pRootNodePointer, int searchValue);
int main()
{
    int resultOfOperation;
    int run = 1;
    int operation;
    binarytree *pRootNodePointer = NULL;
    while (run)
    {
        printf("Enter the operation you would like to preform\n(1)Add node to binary tree\n(2)Prefrom preorder traverasal on binary tree\n(3)Preform postorder traversal\n(4)Preform inorder traversal\n(5)Search binary tree\n");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            int newElement;
            printf("enter the data you want to add to binary tree:\t");
            scanf("%d", &newElement);
            int resultOfOperation = addNode(&pRootNodePointer, newElement);
            if (resultOfOperation == 1)
            {
                printf("the elemnet was added successfully\n");
            }
            else
            {
                printf("the element could not be added\n");
            }
            break;
        case 2:
            preOrderTraversal(pRootNodePointer);
            break;
        case 3:
            postOrderTraversal(pRootNodePointer);
            break;
        case 4:
            inOrderTraversal(pRootNodePointer);
            break;
        case 5:
            int searchValue;
            printf("enter value you want to search from:\t");
            scanf("%d", &searchValue);
            if (searchTree(pRootNodePointer, searchValue) == 1)
            {
                printf("value found\n");
            }
            else
            {
                printf("value not found\n");
            }

        default:
            printf("Invalid input");
            break;
        }
    }
}
int searchTree(binarytree *pRootNodePointer, int searchValue)
{
    if (pRootNodePointer == NULL)
    {
        printf("List is empty");
        return 0;
    }
    else
    {
        binarytree *pCurrentNode = pRootNodePointer;
        while (pCurrentNode->pLeftNode != NULL || pCurrentNode->pRightNode != NULL)
        {
            if (pCurrentNode->data == searchValue)
            {
                return 1;
            }
            else if (pCurrentNode->data > searchValue)
            {
                pCurrentNode = pCurrentNode->pLeftNode;
            }
            else
            {
                pCurrentNode = pCurrentNode->pRightNode;
            }
        }
        if (pCurrentNode->data == searchValue)
        {
            return 1;
        }
        return 0;
    }
}
int addNode(binarytree **pRootNodePointer, int newElement)
{
    binarytree *pNewNode = (binarytree *)malloc(sizeof(binarytree));
    if (pNewNode == NULL)
    {
        perror("malloc failed");
        return -1;
    }
    pNewNode->data = newElement;
    pNewNode->pLeftNode = NULL;
    pNewNode->pPrevNodecd = NULL;
    pNewNode->pRightNode = NULL;
    if (*pRootNodePointer == NULL)
    {
        *pRootNodePointer = pNewNode;
        return 1;
    }
    else
    {
        binarytree *pCurrentNode = *pRootNodePointer;
        while (1)
        {
            if (pCurrentNode->data == pNewNode->data)
            {
                printf("Element is already present in binary tree");
                free(pNewNode);
                return -1;
            }
            else if (pNewNode->data > pCurrentNode->data)
            {
                if (pCurrentNode->pRightNode == NULL)
                {
                    pCurrentNode->pRightNode = pNewNode;
                    return 1;
                }
                pCurrentNode = pCurrentNode->pRightNode;
            }
            else
            {
                if (pCurrentNode->pLeftNode == NULL)
                {
                    pCurrentNode->pLeftNode = pNewNode;
                    return 1;
                }
                pCurrentNode = pCurrentNode->pLeftNode;
            }
        }
    }
}
void preOrderTraversal(binarytree *pRootNodePointer) {
    if (pRootNodePointer == NULL) {
        return;
    }
    printf("%d->", pRootNodePointer->data); 
    preOrderTraversal(pRootNodePointer->pLeftNode); 
    preOrderTraversal(pRootNodePointer->pRightNode); 
}
void postOrderTraversal(binarytree *pRootNodePointer)
{
    if (pRootNodePointer == NULL)
    {
        return;
    }
    postOrderTraversal(pRootNodePointer->pLeftNode);
    postOrderTraversal(pRootNodePointer->pRightNode);
    printf("%d->", pRootNodePointer->data);
    
}
void inOrderTraversal(binarytree *pRootNodePointer)
{
    if (pRootNodePointer == NULL){
        return;
    }
    inOrderTraversal(pRootNodePointer->pLeftNode);
    printf("%d->", pRootNodePointer->data);
    inOrderTraversal(pRootNodePointer->pRightNode);
}