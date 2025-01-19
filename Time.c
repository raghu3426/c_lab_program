#include <stdio.h>
#include <stdlib.h>
struct Time
{
    int hrs;
    int min;
    int sec;
};
typedef struct Time TM;

void normalize(TM *t)
{
    if(t->sec>=60)
    {
        t->min+=t->sec/60;
        t->sec%=60;
    }
    if(t->min>=60)
    {
        t->hrs+=t->min/60;
        t->min%=60;
    }
    if(t->hrs>=24)
    {
        t->hrs%=24;
    }
}

void read(TM *t)
{
    printf("\nEnter the Hourse, Minutes and Seconds: ");
    scanf("%d:%d:%d",&t->hrs,&t->min,&t->sec);
    normalize(t);
}

void display(TM *t)
{
    printf("%02d:%02d:%02d\n",t->hrs,t->min,t->sec);
}

void update(TM *t)
{
    t->sec++;
    normalize(t);
}

void add(TM *t1,TM *t2,TM *Res)
{
    Res->sec=t1->sec+t2->sec;
    Res->min=t1->min+t2->min;
    Res->hrs=t1->hrs+t2->hrs;
    normalize(Res);
}



int main()
{
    TM t,t1,t2,Res;
    int ch;
    for(;;)
    {
        printf("\nMenu\n1.Read\n2.Display\n3.Update Time\n4.Add Two Times\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: read(&t);break;
            case 2: display(&t);break;
            case 3: update(&t);display(&t);break;
            case 4: 
                printf("Enter Time 1= ");
                read(&t1);
                printf("Enter Time 2=");
                read(&t2);
                add(&t1,&t2,&Res);
                printf("Time 1= ");
                display(&t1);
                printf("Time 2= ");
                display(&t2);
                printf("Adding two times= ");
                display(&Res);
                break;

            case 5: printf("Thank You:)");exit(0);
        }
    }
}
