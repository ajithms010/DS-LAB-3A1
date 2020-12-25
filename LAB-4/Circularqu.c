#include<stdio.h>
#include<stdlib.h>
#define QUE_SIZE 5
int item, front=0, rear=-1, q[QUE_SIZE],count=0;
void insertrear()
{
    if(count == QUE_SIZE)
    {
        printf("QUEUE OVERFLOW \n");
        return ;
    }

    rear= (rear+1)%QUE_SIZE;
    q[rear]= item;
    count++;
}

int deletefront()
{
    if(count==0)
        {return -1;
    }
  item=q[front];
  front=(front+1)%QUE_SIZE;
  count=count-1;
    return item;
}

void display()
{
    int i,f;
    if(count==0)
    {
        printf("QUEUE IS EMPTY \n");
        return;
    }
    f=front;

    printf("CONTENTS OF QUEUE \n");
    for(i=1; i<=count; i++)
    {
        printf("%d \n", q[f]);
        f=(f+1)%QUE_SIZE;
    }
}

void main()
{
    int choice ;
    for(;;)
    {
        printf("ENTER 1.insert rear 2.delete front  3.DISPLAY \n");
        printf("ENTER CHOICE \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("ENTER ITEM TO BE ENTERED \n");
                    scanf("%d", &item);
                    insertrear();
                    break;
            case 2: item= deletefront();
                    if(item == -1)
                        printf("QUEUE EMPTY \n");
                    else
                        printf("ITEM DELETED IS %d", item);
                    break;
            case 3: display();
                    break;
            default: exit(0);
        }
    }
}
