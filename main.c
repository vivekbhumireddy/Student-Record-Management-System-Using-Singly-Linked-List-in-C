#include"header.h"

void main()
{
sll *head=0;
unsigned char op;
while(1)
{
printf("***** STUDENT RECORD MENU *****\n");
printf("a/A : add new record\nd/D : delete a record\ns/S : show the list\nm/M : modify a record\nv/V : save\ne/E : exit\nt/T : sort the list\nl/L : delete all the records\nr/R : reverse the list\n");
printf("Enter your choice:\n");
scanf(" %c",&op);
switch(op)
{
case 'a': stud_add(&head);break;
case 'A': stud_add(&head);break;
case 's': stud_show(head);break;
case 'S': stud_show(head);break;
case 'e': exit(0);
case 'E': exit(0);
case 'd': stud_del(&head);break;
case 'D': stud_del(&head);break;
case 'l': stud_del_all(&head);break;
case 'L': stud_del_all(&head);break;
case 'v': stud_save(head);break;
case 'V': stud_save(head);break;
case 't': stud_sort(&head);break;
case 'T': stud_sort(&head);break;
case 'r': stud_rev(&head);break;
case 'R': stud_rev(&head);break;
case 'm': stud_mod(&head);break;
case 'M': stud_mod(&head);break;
default : printf("Unknown Option\n");
}
}
}

void stud_add(sll **ptr)
{
int a;
sll *new,*last=*ptr;
new=malloc(sizeof(sll));
printf("Enter name and percentage\n");
scanf("%s%f",new->name,&new->percentage);
a=stud_roll(*ptr);
new->rollno=a;
new->next=0;
if(*ptr==0)
*ptr=new;
else
{
while(last->next!=0)
last=last->next;
last->next=new;
}
printf("\033[35mNode Added\n\033[0m");
}

int stud_roll(sll *ptr)
{
int i,f;
for(i=1;i;i++)
{
f=0;
sll *pos=ptr;
while(pos)
{
if(pos->rollno==i)
f++;
pos=pos->next;
}
if(f==0)
return i;
}
}

void del_rollno(sll **p,int n)
{
        sll *d=*p,*pre=0;
        while(d)
        {
                if(d->rollno==n)
                {
                        if(0==pre)
                        {
                                *p=d->next;
                        }
                        else
                                pre->next=d->next;
                        free(d);
                        return;
                        d=pre->next;
                }
                if(d)
                {
                        pre=d;
                        d=d->next;
                }
        }
}
void stud_del(sll **ptr)
{
        if(*ptr==0)
        {
                printf("No Nodes\n");
                return;
        }
        char choice;
        printf("R/r:del based on rollno\nN/n:del based on name\n");
        printf("Enter your choice\n");
        scanf(" %c",&choice);
        if((choice=='R')||(choice=='r'))
        {
                sll *del=*ptr;
                int num;
                printf("Enter rollno\n");
                scanf("%d",&num);
                while(del)
                {
                        if(num==del->rollno)
                                del_rollno(ptr,del->rollno);
                        del=del->next;
                }
                printf("\033[33mNode Deleted\033[0m\n");
        }
        else if((choice=='N')||(choice=='n'))
        {
                sll *del=*ptr;
                int flag=0;
                char s[20];
                printf("Enter name\n");
                scanf(" %s",s);
                while(del)
                {
                        if(strcmp(s,del->name)==0)
                        {
                                printf("%d %s %f\n",del->rollno,del->name,del->percentage);
                                flag++;
                        }
                        del=del->next;
                }
                if(flag==1)
                {
                        del=*ptr;
                        while(del)
                        {
                                if(strcmp(s,del->name)==0)
                                        del_rollno(ptr,del->rollno);
                                del=del->next;
                        }
                }
                else if(flag>1)
                {
                        int num;
                        printf("\033[33mThere are %d no.of identical names present in the record\033[0m\n",flag);
                        printf("Enter rollno to delete the node\n");
                        scanf("%d",&num);
                        del_rollno(ptr,num);
                }
                printf("\033[33mNode Deleted\033[0m\n");
        }
        else
                printf("Unknown choice\n");
}

void stud_del_all(sll **ptr)   /// del all
{
sll *del;
if(*ptr==0)
{
printf("\033[32mNo Records\033[0m\n");
return;
}
while(*ptr)
{
del=*ptr;
*ptr=del->next;
free(del);
}
printf("\033[30mAll Nodes Deleted\033[0m\n");
}

void stud_rev(sll **ptr)
{
if(*ptr==0)
{
printf("No Nodes\n");
return;
}
int c=stud_count(*ptr);
if(c>1)
{
sll **a=malloc(sizeof(sll *)*c);
sll *p=*ptr;
int i=0;
while(p)
{
a[i++]=p;
p=p->next;
}
for(i=c-1;i>=0;i--)
a[i]->next=a[i-1];
a[0]->next=0;
*ptr=a[c-1];
}
printf("\033[33mData is Reversed\033[0m\n");
}

void stud_sort(sll **ptr)
{
char ch;
printf("N/n: sort with name\nP/p: sort with percentage\n");
printf("Enter your choice:\n");
scanf(" %c",&ch);
if((ch=='n')||(ch=='N'))
{
if(*ptr==0)
{
printf("No Nodes\n");
return;
}
sll *a,*b,t;
a=*ptr;
int i,j;
for(i=0;a;i++)
{
b=a->next;
for(j=0;b;j++)
{
if(strcmp(a->name,b->name)>0)
{
t.rollno=a->rollno;
strcpy(t.name,a->name);
t.percentage=a->percentage;
a->rollno=b->rollno;
strcpy(a->name,b->name);
a->percentage=b->percentage;
b->rollno=t.rollno;
strcpy(b->name,t.name);
b->percentage=t.percentage;
}
b=b->next;
}
a=a->next;
}
printf("\033[33mData is sorted based on name\n\033[0m");
}
else if((ch=='p')||(ch=='P'))
{
if(*ptr==0)
{
printf("\033[32mNo Nodes\033[0m\n");
return;
}
sll *a,*b,t;
a=*ptr;
int i,j;
for(i=0;a;i++)
{
b=a->next;
for(j=0;b;j++)
{
if(b->percentage>a->percentage)
{
t.rollno=a->rollno;
strcpy(t.name,a->name);
t.percentage=a->percentage;
a->rollno=b->rollno;
strcpy(a->name,b->name);
a->percentage=b->percentage;
b->rollno=t.rollno;
strcpy(b->name,t.name);
b->percentage=t.percentage;
}
b=b->next;
}
a=a->next;
}
printf("\033[33mData is sorted based on percentage\n\033[0m");
}
else
printf("\033[33mUnknown choice for sorting\033[0m\n");
}

void stud_mod(sll **ptr)
{
        sll *p=*ptr;
        if(*ptr==0)
        {
                printf("\033[32mNo Records\033[0m\n");
                return;
        }
        int flag=0;
        char ch;
        printf("\033[34mSearch to Modify a Record \n");
        printf("R/r:based on roll no \nN/n:based on name\nP/p:based on percentage\n");
        printf("Enter your choice\033[0m\n");
        scanf(" %c",&ch);
        if((ch=='r')||(ch=='R'))
        {
                int num;
                printf("Enter rollno for search\n");
                scanf("%d",&num);
                mod_rollno(*ptr,num);
        }
        else if((ch=='n')||(ch=='N'))
        {
                char s[10];
                printf("Enter name for search\n");
                scanf("%s",s);
                while(p){
                        if(strcmp(s,p->name)==0){
                                printf("\033[35m%d %s %f\n\033[0m",p->rollno,p->name,p->percentage);
                                flag++;
                        }
                        p=p->next;
                }
                if(flag==1)
                {
int rn;
                        p=*ptr;
                        while(p)
                        {
                                if(strcmp(s,p->name)==0)
                                 rn=p->rollno;
p=p->next;
                        }
mod_rollno(*ptr,rn);
                }
                else if(flag>1)
                {
                        printf("\033[35mThere are %d no.of records present based on your input\n",flag);
                        int num;
                        printf("Enter rollno of the record to modify\033[0m\n");
                        scanf("%d",&num);
                        mod_rollno(*ptr,num);
                }
        }
        else if((ch=='p')||(ch=='P'))
        {
                float f;
                printf("Enter percentage for search\n");
                scanf("%f",&f);
                while(p){
                        if(f==p->percentage){
                                printf("\033[35m%d %s %f\n\033[0m",p->rollno,p->name,p->percentage);
                                flag++;
                        }
                        p=p->next;
                }
                if(flag==1)
                {
int rn;
                        p=*ptr;
                        while(p)
                        {
                                if(f==p->percentage)
                                        rn=p->rollno;
p=p->next;
                        }
mod_rollno(*ptr,rn);
                }
                else if(flag>1)
                {
                        printf("\033[35mThere are %d no.of records present based on your input\n",flag);
                        int num;
                        printf("Enter rollno of the record to modify\n\033[0m");
                        scanf("%d",&num);
                        mod_rollno(*ptr,num);
                }
        }
}

void mod_rollno(sll *p,int n)
{
while(p){
if(n==p->rollno)
{
printf("\033[36mSelected record:%d %s %f\n",p->rollno,p->name,p->percentage);
        char d;
        printf("N/n:modify name\nP/p:modify percentage\n");
        printf("Enter which you want to modify\n");
        scanf(" %c",&d);
        if((d=='n')||(d=='N'))
        {
                char st[20];
                printf("Enter new name\033[0m\n");
                scanf("%s",st);
                strcpy(p->name,st);
                printf("\033[33mModified Record\n%d %s %f\n\033[0m",p->rollno,p->name,p->percentage);
        }
        else if((d=='p')||(d=='P'))
        {
                float fl;
                printf("Enter new percentage\033[0m\n");
                scanf("%f",&fl);
                p->percentage=fl;
                printf("\033[33mModified Record\033[0m\n%d %s %f\n",p->rollno,p->name,p->percentage);
        }
        else
                printf("Unknown option\033[0m\n");
}
p=p->next;
}
}

void stud_save(sll *ptr)
{
FILE *fp;
fp=fopen("student.dat","w");
if(ptr==0)
{
printf("\033[32mNo Data Present\033[0m\n");
return;
}
while(ptr)
{
fprintf(fp,"%d %s %f \n",ptr->rollno,ptr->name,ptr->percentage);
ptr=ptr->next;
}
printf("\033[30mFile Saved\033[0m\n");
}

void stud_show(sll *ptr)
{
if(ptr==0)
{
printf("\033[35mNo Data Present\n\033[0m");
return;
}
printf("\033[35mRollno\tName\tPercentage\n");
while(ptr)
{
printf("%d\t%s\t%f\n\033[0m",ptr->rollno,ptr->name,ptr->percentage);
ptr=ptr->next;
}
}

int stud_count(sll *ptr)
{
int c=0;
while(ptr)
{
c++;
ptr=ptr->next;
}
return c;
}
