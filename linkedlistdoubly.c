#include <stdio.h>
#include <stdlib.h>
// struct of data user wants to input into the linked list
typedef struct testData
{
    int age;
    int height;
    char letter;
} testData;

// struct contain the pointers and the data of the linked list
typedef struct node
{
    void *data;
    struct node *pPreviousNode, *pNextNode;
} node;

// start of list
typedef struct list
{
    node *pHead;
} list;

void addNode(list *pStartPointer, void (*pCreateNode)(node *));
void deleteNode(list *pStartPointer);
void searchList(list *pStartPointer, list *pStorageSpace, void (*pSearchconditions)(node *pCurrentNode, list *pStorageSpace), void (*pCreateNode)(node *));
void printList(list *pStartPointer, void (*printNode)(testData *));
int sizeOfList(list *pStartPointer);
void targetedAddition(list *pStartPointer, node *pNodeToBeDeleted);
void targetedDeletion(list *pStartPointer, node *pNodeToBeDeleted);
int isListEmpty(list *pStartPointer);
void deleteList(list *pStartPointer);

void createNode(node *pNode);
void printNode(testData *pNode);
void pSearchconditions(node *pCurrentNode, list *pStorageSpace, void (*pCreateNode)(node *));

int main()
{
    list *pList1 = (list *)malloc(sizeof(list));
    int run = 1;
    int operation; 
    if (pList1 == NULL)
    {
        printf("Couldn't allocate memory");
        exit(-1);
    }
    pList1->pHead = NULL;
    while (run)
    {
        printf("Which operation would you like to preform\n(1)Add Node\n(2)Delete Node\n(3)Print List\n(4)Get Size Of List\n(5)Is List Empty\n(6)Delete List");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            addNode(pList1, createNode);
            break;
        case 2:
            deleteNode(pList1);
            break;
        case 3:
            printList(pList1, printNode);
            break;
        case 4:
            int lengthOfList = sizeOfList(pList1);
            printf("%d", lengthOfList);
            break;
        case 5:
            int isEmpty = isListEmpty(pList1);
            if (isEmpty == 1)
            {
                printf("List is empty");
            }
            else{
                printf("list isn't empty");
            }
            break;
        case 6:
            deleteList(pList1);
            break;
        default:
            break;
        }
    }
    addNode(pList1, createNode);
    addNode(pList1, createNode);
    printList(pList1, printNode);
    printf("%d", sizeOfList(pList1));
    deleteNode(pList1);
    printList(pList1, printNode);
    printf("%d", sizeOfList(pList1));
    return 0;
}

void printNode(testData *pTestData)
{
    printf("(age:%d ", pTestData->age);
    printf(",height:%d ", pTestData->height);
    printf(",letter:%c )", pTestData->letter);
    printf("->");
}

void createNode(node *pNode)
{
    if (pNode->data == NULL)
    {
        pNode->data = (testData *)malloc(sizeof(testData));
        if (pNode->data == NULL)
        {
            printf("Couldn't allocate memory");
            exit(-1);
        }
    }

    int age, height;
    char letter;
    printf("Enter age, height and letter");
    scanf("%d %d %c", &age, &height, &letter);

    ((testData *)pNode->data)->age = age;
    ((testData *)pNode->data)->height = height;
    ((testData *)pNode->data)->letter = letter;
}

void addNode(list *pStartPointer, void (*pCreateNode)(node *))
{
    node *pNewNode = (node *)malloc(sizeof(node));
    if (pNewNode == NULL)
    {
        printf("Couldn't allocate memory");
        exit(-1);
    }

    pNewNode->data = NULL;

    if (pStartPointer->pHead == NULL)
    {
        pStartPointer->pHead = pNewNode;
        pNewNode->pPreviousNode = NULL;
        pNewNode->pNextNode = NULL;
    }
    else
    {
        pNewNode->pNextNode = pStartPointer->pHead;
        pNewNode->pPreviousNode = NULL;
        pStartPointer->pHead->pPreviousNode = pNewNode;
        pStartPointer->pHead = pNewNode;
    }

    (*pCreateNode)(pNewNode);
}

void printList(list *pStartPointer, void (*printNode)(testData *))
{
    node *pCurrentPointer = pStartPointer->pHead;
    if (pStartPointer->pHead == NULL)
    {
        printf("Empty list");
        return;
    }
    while (pCurrentPointer != NULL)
    {
        (*printNode)((testData *)(pCurrentPointer->data));
        pCurrentPointer = pCurrentPointer->pNextNode;
    }
    printf("NULL\n");
}

void deleteNode(list *pStartPointer)
{
    if (pStartPointer->pHead == NULL)
    {
        printf("Empty list");
        return;
    }
    node *pCurrentNode = pStartPointer->pHead;
    pStartPointer->pHead = pCurrentNode->pNextNode;
    (pStartPointer->pHead)->pPreviousNode = NULL;
    free(pCurrentNode);
}

void deleteList(list *pStartPointer)
{
    while (isListEmpty(pStartPointer) != 1)
    {
        deleteNode(pStartPointer);
    }
    free(pStartPointer);
}

int isListEmpty(list *pStartPointer)
{
    if (pStartPointer->pHead == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pSearchconditions(node *pCurrentNode, list *pStorageSpace, void (*pCreateNode)(node *))
{
    int ageWanted, heightWanted;
    char letterWanted;
    printf("Enter age, height and letter you want");
    scanf("%d %d %c", &ageWanted, &heightWanted, &letterWanted);
    if (ageWanted == ((testData *)pCurrentNode->data)->age && heightWanted == ((testData *)pCurrentNode->data)->height && letterWanted == ((testData *)pCurrentNode->data)->letter)
    {
    }
}

void searchList(list *pStartPointer, list *pStorageSpace, void (*pSearchconditions)(node *pCurrentNode, list *pStorageSpace), void (*pCreateNode)(node *))
{
    node *pCurrentPointer = pStartPointer->pHead;
    while (pCurrentPointer != NULL)
    {

        (*pSearchconditions)(pCurrentPointer, pStorageSpace);
        pCurrentPointer = pCurrentPointer->pNextNode;
    }
}

int sizeOfList(list *pStartPointer)
{
    node *pCurrentNode = pStartPointer->pHead;
    int count = 0;
    while (pCurrentNode != NULL)
    {
        count++;
        pCurrentNode = pCurrentNode->pNextNode;
    }
    return count;
}
void targetedAddition(list *pHead, node *pNodeToBeDeleted)
{
}
void targetedDeletion(list *pHead, node *pNodeToBeDeleted)
{
}
