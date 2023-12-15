#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node*next;
};

struct stack{
struct node *top;
int count;
};

void push(struct stack *stk,int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=stk->top;
    stk->top=temp;
    stk->count++;
}

int pop(struct stack *stk){
    int x;
    if(stk->top==NULL){
        printf("Stack bos");
        return;
    }
    else{
        struct node *temp= stk->top;
        stk->top=stk->top->next;
        int x =temp->data;
        free(temp);
        stk->count--;
    }
    return x;
}

void print(struct stack *stk){
    if(stk->count==0){
        printf("Stack bos");
        return;
    }
    else{
        struct node *temp=stk->top;
        int count = stk->count;
        while(count!=0){
            printf("%d \n",temp->data);
            temp= temp->next;
            count--;
        }
    }

}

void reset(struct stack *stk){
    while(stk->count!=0){
        int x = pop(stk);
    }
}

int main()
{
    int secim,data;
    struct stack stk;
    stk.top=NULL;
    stk.count=0;

    while(1){
    printf("1)Push\n2)Pop\n3)Print\n4)Reset\n5)Exit\nHangi islemi yapmak istersiniz : ");
    scanf("%d",&secim);
    switch(secim){
    case 1:
        printf("Hangi sayiyi girmek istersiniz");
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
        }
    }
    return 0;
}
