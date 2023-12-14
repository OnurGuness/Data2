#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void bastir(struct node * r){
    struct node*iter =r;
    printf("%d ",r->data);
    iter=iter->next;
    while (iter!=r)
    {
        printf("%d ",r->data);
        iter=iter->next;
    }
    printf("\n");
}
void ekle(struct node*r,int data){
    struct node*iter=r;
    while (iter->next!=r){
        iter=iter->next;
    }
    iter->next =(struct node*)malloc(sizeof(struct node));
    iter->next->data=data;
    iter->next->next = r;
};
struct node *ekleSirali(struct node *r,int data){
    if(r==NULL){
        r=(struct node*)malloc(sizeof(struct node));
        r->next=r;
        r->data=data;
        return r;
    }
    if(r->data>data){
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next =r;
        struct node* iter=r;
        while(iter->next!=r){
            iter=iter->next;
        }
        iter->next=temp;
        return temp;
    }
    struct node *iter=r;
    while (iter->next!=r && iter->next->data < data)
    {
        iter=iter->next;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->next=iter->next;
    iter->next=temp;
    temp->data=data;
    }

struct node* sil(struct node *r,int data){
    struct node *temp;
    struct node*iter =r;
    if(r->data==data){
        while(iter->next!=r){
            iter = iter->next;
        }
        iter->next=r->next;
        free(r);
        return iter->next;
    }
    while (iter->next!=r && iter->next->data != data){
        iter = iter->next;
    }
    if(iter->next == r){
        printf("Sayi bulunamadi.\n");
        return r;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    return r;
}  
int main(){
    struct node *head;
    head=NULL;
    head=ekleSirali(head,400);
    head=ekleSirali(head,40);
    head=ekleSirali(head,4);
    head=ekleSirali(head,450);
    head=ekleSirali(head,50);
    bastir(head);
    head=sil(head,50);
    bastir(head);
    head=sil(head,999);
    bastir(head);
    head=sil(head,4);
    bastir(head);
    head=sil(head,450);
    bastir(head);


    return 0;
}