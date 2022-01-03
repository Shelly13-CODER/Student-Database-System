#include<stdio.h>
#include<conio.h>
struct stu
{
int rn;
char name[20];
int marks;
}s;
FILE *p,*t;
void add();
void disp();
void edit();
void del();

int main()
{
int x;

do
{
printf("\nStudent Database Management System\n\n\n");
printf("\n\n1.Add data.");
printf("\n\n2.Display data.");
printf("\n\n3.Edit or Update data");
printf("\n\n4.Delete data");
printf("\n\n5.Exit from Database.");
printf("\n\n\nEnter option,What you wanna do:");
scanf("%d",&x);
switch(x)
{
case 1:
add();
break;

case 2:
disp();
break;

case 3:
edit();
break;

case 4:
del();
break;

case 5:
printf("\n\tExiting from application.....Bye");
break;

default:
printf("\n\t\tWrong choice...");
break;
}
getch();
}
while(x!=5);
return 0;
}

void add()
{

p = fopen("database.bin","a");
printf("\nAdding new data");
printf("\nEnter Roll number:");
scanf("%d",&s.rn);
fflush(stdin);
printf("\nEnter Name:");
gets(s.name);
printf("\nEnter marks:");
scanf("%d",&s.marks);
fwrite(&s,sizeof(s),1,p);
printf("\n\t\tRecord added to file...");
fclose(p);
}


void disp()
{

printf("\n\tDisplaying data");
p = fopen("database.bin","r");
printf("\nRoll number\tName\t\tMarks\n");
while(fread(&s,sizeof(s),1,p))
{
printf("\n%d\t\t%s\t\t%d",s.rn,s.name,s.marks);
}
fclose(p);
}


void edit()
{
int rln;
printf("Enter roll number you wanna update=");
scanf("%d",&rln);
p=fopen("database.bin","r");
if (p==NULL)
{
printf("\n Can not open file or file does not exist.");
return;
}
t=fopen("empty.bin","w");
while (fread(&s,sizeof(s),1,p))
if(rln!=s.rn)
{
fwrite(&s,sizeof(s),1,t);
}
else
{
printf("\nEnter Name:");
scanf("%s",&s.name);
printf("\nEnter marks:");
scanf("%d",&s.marks);
fwrite(&s,sizeof(s),1,t);
}
fclose(p);
fclose(t);
printf("Data update successfully");
remove("database.bin");
rename("empty.bin","database.bin");
}


void del()
{
int rln;
printf("Enter roll number you wanna delete=");
scanf("%d",&rln);
p=fopen("database.bin","r");
if (p==NULL)
{
printf("\n Can not open file or file does not exist.");
return;
}
t=fopen("empty.bin","w");
while (fread(&s,sizeof(s),1,p))
if(rln!=s.rn)
{
fwrite(&s,sizeof(s),1,t);
}
fclose(p);
fclose(t);
remove("database.bin");
rename("empty.bin","database.bin");
printf("Record of student deleted successfully");
}
