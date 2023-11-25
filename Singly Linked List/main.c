#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;

};

struct node* BasaEkle(struct node *head,int data)
{
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
    return head;
};

void SonaEkle(struct node *head,int data)
{
    if(head==NULL)
    {
        printf("Liste bos\n");
        return;
    }
    struct node*temp=(struct node *)malloc(sizeof(struct node));

    temp->data=data;
    temp->next=NULL;
    struct node*temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
     temp2->next=temp;

}

void OrtaEkle(struct node*head,int data,int index)
{
    if(head ==NULL)
    {
        printf("Liste bos");
        return;
    }
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    struct node*temp2=head;
    while(temp2->data!=index)
    {
        temp2=temp2->next;
    }
    temp->data=data;
    temp->next=temp2->next;
    temp2->next=temp;

}

void ElemanlariGoster(struct node*head)
{

    struct node *temp = head;
    if(head==NULL)
    {
        printf("Liste bos");
        return;
    }


    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

}

void ElemanDuzenle(struct node *head,int data,int index)
{
    if(head==NULL)
    {
        printf("Liste bos");
        return;
    }
    struct node *temp=head;

    while(temp->data!=index)
    {
        temp=temp->next;
    }
    //temp->data=data; oldugu zaman
    temp->data=data;
    //free(temp);

}

struct node* ElemanSil(struct node *head,int data)
{
    if(head==NULL)
    {
        printf("Liste bos");
        return head;
    }
    struct node* temp=head;
    if(head->data==data)
    {
        head=head->next;
        free(temp);
    }
    else{
         while(temp->next->data!=data)
         {
             if(temp->next->next==NULL)
             {
                 printf("Silmek istediginiz veri bulunamadi");
                 return head;
             }
             temp=temp->next;
         }
        struct node*temp2=temp->next;
        temp->next=temp->next->next;//temp->next(mesela 4)=temp->next->next(mesela 6) 4 olan düðümü atýp 6 olan düðüm koyduk.Yerine koyduk.
        free(temp2);
    }
    return head;
}

struct node* ListeSil(struct node*head)
{
    if(head==NULL)
    {
        printf("Liste zaten bos");
        return;
    }
    struct node* temp;
    while(head!=NULL)
    {
       temp=head;
       head=head->next;
       free(temp);
    }
    return head;
}

int ElemanSayisi(struct node* head)
{
    int sayac=0;
   /* if(head==NULL)
    {
        printf("Liste bos");
        return;
    }*/
   // struct node*temp=head;
    while(head!=NULL)
    {
        head=head->next;
        sayac++;
    }
    return sayac;
}

//Yapýlacak
void ListeyiTersBasma(struct node*head)
{
    if(head==NULL)
    {
        printf("Liste bos");
        return;
    }
    struct node*temp=head;
    while(head!=NULL)
    {
        head=head->next;
    }

    while(head!=temp)
    {
        printf("%d",head->data);

    }

}
//Listedeki eleman bilgileri

void kunyem(struct node*head)
{
    int sayac=1;
    if(head==NULL)
    {
        printf("Liste bos");
        return;
    }
    struct node*temp=head;

    while(temp!=NULL)
    {
        printf("Listedeki sirasi %d. olan elemanin adresi: %p\n",sayac,temp);
        printf("%d. elemanin degeri %d\n ",sayac,temp->data);
        printf("Listede %d. olan elemanin %d\n ",sayac,temp->data);
        sayac++;
        temp = temp->next;
    }

}

int main()
{
    int secim,data,index;
    struct node *head = NULL;

    while(1)
    {
        printf("1-Listenin Basina Eleman Ekle\n");
        printf("2-Listenin Sonuna Eleman Ekle\n");
        printf("3-Listenin Ortasina Eleman Ekle\n");
        printf("4-Elemanlari listele\n");
        printf("5-Elemanlari Duzenleme Gorme\n");
        printf("6-Listeden verilen bir degere sahip dugum silmek\n");
        printf("7-Listeyi silin\n");
        printf("8-Listedeki eleman sayisi\n");
        printf("9-Listenin tum  eleman bilgileri\n");
        printf("10-Listeyi tersten yazdirma\n");
        printf("11-Listeyi sirala\n");
        printf("12-Listeyi listeye ekle\n");
        printf("13-Programdan cik\n");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:printf("Eklemek istediginiz degeri giriniz");
            scanf("%d",&data);
           head = BasaEkle(head,data);
           break;
        case 2:printf("Eklemek istediginiz sayiyi giriniz");
             scanf("%d",&data);
            SonaEkle(head,data);
            break;
        case 3:printf("Eklemek istediginiz sayi");
            scanf("%d",&data);
            printf("Kacinci eleman");
            scanf("%d",&index);
            OrtaEkle(head,data,index);
            break;
        case 4:
            ElemanlariGoster(head);
            printf("\n");
            break;
        case 5:
            printf("Degismek istedigin yeni deger");
            scanf("%d",&data);
            printf("Hangi siradaki sayiyi degistireceksin");
            scanf("%d",&index);
            ElemanDuzenle(head,data,index);
            break;
        case 6:printf("Hangi degeri silmek istiyorsunuz");
            scanf("%d",&data);
            head= ElemanSil(head,data);
            break;
        case 7:
            head= ListeSil(head);
            break;
        case 8:
            printf("Listedeki eleman sayisi: %d",ElemanSayisi(head));
            printf("\n");
            break;
        case 9:
            kunyem(head);
            break;
        case 13:
            break;
        }
        if(secim==13)
        {
            break;
        }
    }

    return 0;
}
