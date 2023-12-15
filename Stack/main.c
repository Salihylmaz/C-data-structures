#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4

struct stack{
    int data[MAX_SIZE];
    int top;
};


void push(struct stack *stk,int data){
    if(stk->top==MAX_SIZE-1){
        printf("Stack doluyken islem yapamazsiniz");
        return;
    }
    else{
        stk->top++;
        stk->data[stk->top]=data;
    }
}

int pop(struct stack *stk){
    int x;
    if(stk->top==-1){
        printf("stack bos \n");
        return;
    }
    else{
        x = stk->data[stk->top];
        stk->top--;
    }
    return x;
}

void print(struct stack *stk){
    if(stk->top==-1){
        printf("Stack bos");
        return;
    }
    int temp = stk->top;
    while(temp != -1){
        printf("%d",stk->data[temp]);
        temp--;
    }
}

void reset(struct stack *stk){
    stk->top =-1;
}


int main() {
    int secim,data;
    struct stack stk;
    stk.top=-1;
    while(1){
    printf("1)Push\n2)Pop\n3)Print\n4)Reset\n5)Exit\nYapmak istediginiz islem hangisi : ");
    scanf("%d",&secim);
    switch(secim){
    case 1:
        printf("Eklemek istediginiz eleman");
        scanf("%d",&data);
        push(&stk,data);
        break;
    case 2:
        pop(&stk);
        break;
    case 3:
        print(&stk);
        break;
    case 4:
        reset(&stk);
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }
}
    return 0;
}
