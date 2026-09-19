#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct st
{
int rollno;
char name[20];
float percentage;
struct st *next;
}sll;
