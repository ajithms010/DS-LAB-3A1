#include<stdio.h>

#include<stdlib.h>
#define maxsize 5
void enqueue(int *Q,int *front, int *rear)
    {
    int ele;
    if(*rear>=maxsize-1)
        {
        printf("Queue is full.\n");
        return;
        }
    if(*front==-1)
        {
        (*front)++;
        }
    (*rear)++;
    printf("Enter the element to be inserted");
    scanf("%d",&ele);
    *(Q+*rear)=ele;
    }

void display(int *Q,int *front,int *rear)
    {
    if(*front==-1&&*rear==-1)
        printf("Queue is empty!!!!.\n");
    else
        {
        printf("Elements in Queue are:\n");
        for(int i=*front;i<=*rear;i++)
            {
            printf("%d ",*(Q+i));
            }
            printf("\n");
        }
    }

void dequeue(int *Q,int *front, int *rear)
    {
    int ele;
    if(*front==-1&&*rear==-1)
        {
        printf("Queue is empty!!!!\n");
        return;
        }
    else if(*front==*rear)
        {
        ele=*(Q+*front);
        *front=-1;
        *rear=-1;
        }
    else
        {
        ele=*(Q+*front);
        (*front)++;
        }
    printf("Deleted Element are: %d\n",ele);
    }

void main()
{
int front1=-1,rear1=-1;
int queue1[maxsize];
int choice;
    printf("1. Enqueue\n");
    printf("2. Dequque\n");
    printf("3. Display\n");
    printf("4. Exit\n");

do
    {
    printf("Enter your choice");
    scanf("%d",&choice);

    switch(choice)
        {
        case 1: enqueue(queue1,&front1,&rear1);
            break;
        case 2: dequeue(queue1,&front1,&rear1);
            break;
        case 3: display(queue1,&front1,&rear1);
            break;
        case 4:exit(0);
            break;
        default:printf("Please input correct choice\n");
            break;
        
        }
    }while(choice!=4);

}
