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
int stud_count(sll *);
void stud_rev(sll **);
int stud_roll(sll *);
void stud_add(sll **);
void stud_sort(sll **);
void stud_save(sll *);
void stud_del_all(sll **);
void del_rollno(sll **,int );
void stud_del(sll **);
void stud_show(sll *);
void stud_mod(sll **);
void mod_rollno(sll *,int n);
