#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#include "STD.h"

extern student* students;
void SDB_action (uint8 choice);
void printMenu();
int main()
{
    students = malloc(3*sizeof(student));
    while(1)
    {
        printMenu();
        uint8 choice;
        scanf("%d", &choice);
        if(choice >= 8 || choice <= 0)
            break;


        SDB_action(choice);
    }
}
void printMenu()
{
    printf("Welcome to SIS system \n");
    printf("1)Add entry:\n");
    printf("2)Get used size:\n");
    printf("3)Read through ID:\n");
    printf("4)Get list:\n");
    printf("5)Check if ID exists:\n");
    printf("6)Delete entry:\n");
    printf("7)Check if database is full:\n");

}
void SDB_action(uint8 choice)
{
    int ida[10];
    uint32 id;
    switch(choice)
    {
        case(1): SDB_AddEntry(); break;
        case(2): printf("%d",SDB_GetUsedSize()); break;
        case(3): scanf("%d", &id); SDB_ReadEntry(id); break;
        case(4): SDB_GetList(ida); break;
        case(5): scanf("%d", &id); printf("%d \n",SDB_IsIdExist(id)); break;
        case(6): scanf("%d", &id); SDB_DeletEntry(id); break;
        case(7): printf("%d \n",SDB_IsFull()); break;
    }
}
