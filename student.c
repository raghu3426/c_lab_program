#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[30];
    char reg_no[10];
    int marks[3];
    float avg;
};
typedef struct student STD;

int capacity;

void read(STD *st)
{
    int n, temp;
    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    if (n > capacity)
    {
        printf("Insufficient space\n");
        printf("Create space by reallocating memory 1(Yes) or 0(No): ");
        scanf("%d", &temp);
        if (temp == 1)
        {
            st = (STD *)realloc(st, n * sizeof(STD));
            if (st == NULL)
            {
                printf("Memory reallocation failed\n");
                return;
            }
            else
            {
                printf("Memory reallocated successfully\n");
                capacity = n;
            }
        }
        else
        {
            printf("Memory not reallocated\n");
            return;
        }
    }
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("Enter the details of student %d\n", i + 1);
        printf("Enter the name: ");
        scanf("%s", st[i].name);
        printf("Enter the reg_no: ");
        scanf("%s", st[i].reg_no);
        for (j = 0; j < 3; j++)
        {
            printf("Enter the marks of subject %d: ", j + 1);
            scanf("%d", &st[i].marks[j]);
        }
    }
}
void disp(STD *st,int size)
{
    int i,j;
    if(size==0)
    {
        printf("List is empty\n");
        return;
    }
    printf("The details of %d students are\n",size);
    printf("Name\tReg_no\tTest1\tTest2\tTest3\t\n");
    for(i=0;i<size;i++)
    {
        printf("%s\t%s\t",st[i].name,st[i].reg_no);
        for(j=0;j<3;j++)
        {
            printf("%d\t",st[i].marks[j]);
        }
        printf("\n");
    }
}

void avg(STD *st,int size)
{
    if(size==0)
    {
        printf("List is empty\n");
        return;
    }
    int i,j;
    for(i=0;i<size;i++)
    {
        int high1=0,high2=0;
        for(j=0;j<3;j++)
        {
            if (st[i].marks[j]>high1)
            {
                high2=high1;
                high1=st[i].marks[j];
            }
            else if(st[i].marks[j]>high2)
            {
                high2=st[i].marks[j];
            }
        }
        st[i].avg=(high1+high2)/2.0;
    }
    printf("The details of %d students are\n",size);
    printf("Name\tReg_no\tTest1\tTest2\tTest3\tavg\n");
    for(i=0;i<size;i++)
    {
        printf("%s\t%s\t",st[i].name,st[i].reg_no);
        for(j=0;j<3;j++)
        {
            printf("%d\t",st[i].marks[j]);
        }
        printf("%.2f\n",st[i].avg);
    }
}

void main()
{
    STD *st;
    int ch,n;
    printf("Enter size: ");
    scanf("%d",&capacity);
    st=(STD*)malloc(capacity*sizeof(STD));
    for(;;)
    {
        printf("\n1.Read\n2.Display\n3.AVG Calculate\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                read(st);
                break;
            case 2:
                disp(st,capacity);
                break;
            case 3: 
                avg(st,capacity);
                break;
            case 4:
                printf("Thank You:)");
                free(st);
                exit(0);
        }
    }
}
