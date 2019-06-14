#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int stack[1000];
    int SP;
};
int pop(struct stack *mystack, int *status)
{
    if(mystack -> SP < 1)
    {
        *status = 0;
        return 0;//we cannot return 0 and know stack empty condition as 0 can be a valid stack element
    }
    *status = 1;
    return mystack -> stack[--(mystack -> SP)];
}
int push(struct stack *mystack, int elem)
{
    if(mystack -> SP < 1000)
    {
        mystack -> stack[mystack -> SP++] = elem;
        return 0;
    }
    return -1;
}

struct queue
{
    struct stack mystack;
    struct stack temp;
};
void enqueue(struct queue * myqueue, int elem)
{
    push(&(myqueue->mystack),elem);
    printf("element enqueued is :%d\n",elem);
}
int dequeue(struct queue *myqueue, int *status)
{   
    int n = myqueue->mystack.SP;
    for(int i=0;i<n;i++)
    push(&(myqueue->temp),pop(&(myqueue->mystack),status));
    //printf("in dequeue fun");
    int ret = pop(&(myqueue->temp),status);
    for(int i=0;i<n;i++)
    push(&(myqueue->mystack),pop(&(myqueue->temp),status));
    
    
    *status=1;
    return ret;
}
void init(struct queue *myqueue)
{
    (myqueue -> mystack).SP = 0;
    (myqueue -> temp).SP = 0;
}
int main()
{
    int elem;
    struct queue myqueue;
    init(&myqueue);
    int choice;
    int val, status;
    while(-100)//any non-zero value makes condition true
    {
        printf("\nEnter:\n\t1 - to Insert to Queue\n\t2 - to Delete from Queue\n\t0 - to Exit: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Please enter the element: ");
                scanf("%d", &elem);
                enqueue(&myqueue, elem);
                break;
            case 2:
                val = dequeue(&myqueue, &status);
                if(status  == 1)
                {
                    printf("Removed element is %d: \n", val);
                }
                break;
            case 0: exit(0);
        }
    }
    printf("\n");

}