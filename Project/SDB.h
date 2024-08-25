#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD.h"
#include "SDB.c"


student* students;
uint8 siz = 3;
uint8 studentCount = 0;

void inreaseSize(student** ptr);
bool SDB_IsFull();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint32* lis);
bool SDB_IsIdExist(uint32 id);


#endif // SDB_H_INCLUDED
