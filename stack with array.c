#include<stdio.h>
struct stack
{
        int stack[1000];
        int SP;
};
int pop(struct stack *mystack, int *status)
{   
    int elem = (*mystack).stack[(*mystack).SP-1];
    mystack->SP = mystack->SP-1;
    *status = *status-1;
    return elem;
}
int push(struct stack *mystack, int elem)
{   
    mystack->stack[mystack->SP] = elem;
    mystack->SP = mystack->SP +1;
    return 0;
}
int main()
{
        int n, i, elem, status;
        struct stack mystack;
        mystack.SP = 0;
        printf("Please enter the number of elements to stack: ");
        scanf("%d", &n);
        status = n;
        printf("Please enter the stack elements: ");
        for(i = 0; i < n; i++)
        {
                scanf("%d", &elem);
                push(&mystack, elem);
        }
        printf("The stack contents are :");
        /*for(i = 0; i < n; i++)
        {
                printf("%d", mystack.stack[i]);
                //push(&mystack, elem);
        }*/
        printf("\n");
        for(i = 0; i < n; i++)
        {
                elem = pop(&mystack, &status);
                printf("%d ", elem);
                if(status == 0)//should not happen as we know n here
                {
                        break;
                }
                
        }
        printf("\n");

}