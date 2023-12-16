#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 4

struct queue{
    int front;
    int rear;
    int count;
    int arr[QUEUE_SIZE];
};

void initialize(struct queue *q){
    q->front=0;
    q->rear =-1;
    q->count=0;
}

void enqueue(struct queue *q,int x){
    if(q->count == QUEUE_SIZE){
        printf("Sira dolu");
        return;
    }
    if(q->rear!=QUEUE_SIZE-1){
        q->rear++;
    }
    else{
        q->rear=0;
    }
    q->count++;
    q->arr[q->rear]=x;
}

int dequeue(struct queue *q){
    if(q->count==0){
        printf("Sira bos");
        return;
    }
    if(q->front !=QUEUE_SIZE-1){
        q->front++;
    }
    else{
        q->front=0;
    }
    q->count--;
    return q->arr[q->front];
}

void print_queue(struct queue *q){
    if(q->count==0){
        printf("Sira bos");
        return;
    }
    int temp=q->front;
    for(int i=0;i<q->count;i++){
        printf("%d\n",q->arr[temp]);
        //q->count--;
        temp++;
        if(temp==QUEUE_SIZE){
            temp=0;
        }
    }
}

int main(int argc,const char * argv[])
{
    int secim,data;
    struct queue q;
    initialize(&q);
    while(1){
    printf("1-)Enqueue \n2-)Dequeue \n3-)Reset \n4-)Liste \n5-)Exit \nHangi islemi yapmak istersiniz");
    scanf("%d",&secim);
    switch(secim){
    case 1:
            printf("Eklemek istediginiz sayiyi giriniz");
            scanf("%d",&data);
            enqueue(&q,data);
            break;
    case 2:
            dequeue(&q);
            break;
    case 3:
            initialize(&q);
            break;
    case 4:
            print_queue(&q);
            break;
    case 5:
            exit(0);
            break;
    default:
            printf("Hatali islem secimi");
            break;
        }
    }
    return 0;
}
