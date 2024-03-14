// Implement a Stack using Array and develop functions to perform push and pop operations.
#include<stdio.h>
int stack[1000], max, top=-1, choice;
void push() {
    int value;
    if(top==max-1) {
        printf("Overflow\n");
    } else {
        printf("Push elements into stack :\n");
        while(top<max-1) {
            top++;
            printf("Enter the %d index value : \n", top);
            scanf("%d", &value);
            stack[top]=value;
        } 
    }
    printf("The elements in stack are :\n");
    for(int i=top; i>=0; i--) {
        printf("%d\n", stack[i]);
    }
}
void pop() {
    int value;
    if(top==-1) {
        printf("Underflow\n");
    } else {
        int popElements;
        printf("Enter the number of elements you want to pop\n");
        scanf("%d", &popElements);
        for(int i=0; i<popElements; i++) {
            value=stack[top];
            top--;
            printf("The popped element is : %d\n", value);
        }
    }
    printf("The stack is : \n");
    for(int i=top; i>=0; i--) {
        printf("%d\n", stack[i]);
    }
    printf("Do you want to pop more elements(Enter 1 for yes and 0 for no) : ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            pop();
            break;
        case 0:
            break;
        default:
            printf("Invalid choice");
    }
}
int main() {
    printf("Enter the size of the stack :\n");
    scanf("%d", &max);
    push();
    printf("Do you want to pop elements(Enter 1 for yes and 0 for no) : \n");
    scanf("%d", &choice);
    if(choice==1) {
        pop();
    }
    return 0;
}