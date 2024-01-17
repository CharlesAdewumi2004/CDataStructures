#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct student
{
    char name[50];
    int age, studentId;
};
typedef struct student student;

int hash(const char *name, int sizeOfHashTable);
student *createNode(char *name, int age, int studentId);
void displayHashTable(student **pHashTable, int sizeOfHashTable);
student *searchHashTable(char *name, int sizeOfHashTable, student **pHashTable);

int main()
{
    int sizeOfHashTable;
    student **pHashTable;
    printf("How long do you want your hash table\n");
    scanf("%d", &sizeOfHashTable);
    pHashTable = malloc(sizeof(student *) * sizeOfHashTable);
    if (pHashTable == NULL)
    {
        perror("malloc failed");
        return 1;
    }
    pHashTable[hash("charlie", sizeOfHashTable)] = createNode("charlie", 10, 1488);
    pHashTable[hash("forsen", sizeOfHashTable)] = createNode("forsen", 18, 1765);
    pHashTable[hash("kappa", sizeOfHashTable)] = createNode("kappa", 12, 9543);
    pHashTable[hash("trihard", sizeOfHashTable)] = createNode("trihard", 99, 1348);
    student *kappa = searchHashTable("charlie", sizeOfHashTable, pHashTable);
    printf("age:%d\n", kappa->age);
    printf("student id:%d\n", kappa->studentId);
    displayHashTable(pHashTable, sizeOfHashTable);
    return 0;
}
student *searchHashTable(char *name, int sizeOfHashTable, student **pHashTable){
    return pHashTable[hash(name, sizeOfHashTable)];
}
int hash(const char *name, int sizeOfHashTable)
{
    int key = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        key += name[i];
        key *= name[i];
        key = key % sizeOfHashTable;
    }
    return key;
}
student *createNode(char *name, int age, int studentId)
{
    student *pNewNode = malloc(sizeof(student));
    if (pNewNode == NULL)
    {
        perror("malloc failed");
        return NULL;
    }
    pNewNode->age = age;
    strcpy(pNewNode->name, name);
    pNewNode->studentId = studentId;
    return pNewNode;
}
void displayHashTable(student **pHashTable, int sizeOfHashTable)
{
    for (int i = 0; i < sizeOfHashTable; i++)
    {
        if (pHashTable[i] != NULL)
        {
            printf("%s, %d, %d\n", pHashTable[i]->name, pHashTable[i]->age, pHashTable[i]->studentId);
        }
        else
        {
            printf("Empty slot\n");
        }
    }
}
