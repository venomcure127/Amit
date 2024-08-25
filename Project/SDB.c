#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#include "STD.h"


extern student* students;
extern uint8 siz;
extern uint8 studentCount;

void inreaseSize(student** ptr)
{
    siz++;

    student* buffer = malloc(siz * sizeof(student));

    for(int i = 0; i < siz - 1; i++)
    {
        buffer[i] = (*ptr)[i];
        printf("%d \n", (*ptr)[i].Student_ID);
        printf("id:%d \n", i);
    }
    free(*ptr);
    *ptr = buffer;
}

void decreaseSize(student** ptr)
{
    siz--;
    student* buffer = malloc(siz  * sizeof(student));

    for(int i = 0; i < studentCount; i++)
    {
        buffer[i] = (*ptr)[i];
    }
    free(*ptr);
    *ptr = buffer;
}

bool SDB_IsFull()
{
    if(siz == 10)
        return true;
    else
        return false;
}
uint8 SDB_GetUsedSize()
{
    return studentCount;
}
bool SDB_AddEntry()
{
    student buffer;
    printf("ID: \n");
    scanf("%d", &buffer.Student_ID);
    printf("Year: \n");
    scanf("%d", &buffer.Student_year);
    printf("1st Course ID: \n");
    scanf("%d", &buffer.Course1_ID);
    printf("1st Course grade: \n");
    scanf("%d", &buffer.Course1_grade);
    printf("2nd Course ID: \n");
    scanf("%d", &buffer.Course2_ID);
    printf("2nd Course grade: \n");
    scanf("%d", &buffer.Course2_grade);
    printf("3rd Course ID: \n");
    scanf("%d", &buffer.Course3_ID);
    printf("3rd Course grade: \n");
    scanf("%d", &buffer.Course3_grade);

    int check = 0;

    while(check == 0)
    for(int i = 0; i < studentCount; i++)
    {
        if(buffer.Student_ID == students[i].Student_ID)
        {
            check = i;
            break;
        }
    }


    if(siz == 10)
    {
        printf("FULL\n");
        return false;
    }


    if(studentCount == siz)
    {
        inreaseSize(&students);
    }
    students[studentCount] = buffer;
    studentCount++;
}
void SDB_DeletEntry(uint32 id)
{
    int check = -1;
    for(int i = 0; i < studentCount; i++)
    {
        if(id == students[i].Student_ID)
        {
            check = i;
            break;
        }
    }

    if(check == -1)
        return;

    for(int i = check; i < studentCount; i++)
    {
        students[i] = students[i+1];
    }
    studentCount--;
    if(siz > 3)
        decreaseSize(&students);
}
bool SDB_ReadEntry(uint32 id)
{
    int check = -1;
    for(int i = 0; i < studentCount; i++)
    {
        if(id == students[i].Student_ID)
        {
            check = i;
            break;
        }
    }
    if(check == - 1)
        return false;


    printf("%d \n", students[check].Student_ID);
    printf("%d \n", students[check].Student_year);
    printf("%d \n", students[check].Course1_ID);
    printf("%d \n", students[check].Course1_grade);
    printf("%d \n", students[check].Course2_ID);
    printf("%d \n", students[check].Course2_grade);
    printf("%d \n", students[check].Course3_ID);
    printf("%d \n", students[check].Course3_grade);
}
void SDB_GetList(uint32 * lis)
{
    for(int i =0; i< studentCount; i++)
    {
        lis[i] = students[i].Student_ID;
        printf("%d \n",students[i].Student_ID);
    }
}
bool SDB_IsIdExist(uint32 id)
{
    for(int i =0; i< studentCount; i++)
    {
        if(students[i].Student_ID == id)
            return true;
    }
    return false;
}
