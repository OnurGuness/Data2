#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void bastir(struct node * r){
    while (r!=NULL)
    {
        printf("%d ",r->data);
        r=r->next;
    }
    printf("\n");
}
struct node *ekleSirali(struct node *r,int data){
    if(r==NULL){
        r=(struct node*)malloc(sizeof(struct node));
        r->next=NULL;
        r->prev=NULL;
        r->data=data; 
        return r;
    }
    if(r->data>data){
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next =r;
        r->prev=temp; 
        return temp; 
    }
    struct node *iter=r;
    while (iter->next!=NULL && iter->next->data < data)
    {
        iter=iter->next;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->next=iter->next;
    iter->next=temp;
    temp->prev=iter;
    if(temp->next!=NULL)
        temp->next->prev=temp;
    temp->data=data;
    return r;
    }

struct node* sil(struct node *r,int data){
    struct node *temp=NULL;
    struct node*iter =r;
    if(r->data==data){
        temp=r;
        r=r->next;
        free(temp);
        return r;
    }
    while (iter->next!=NULL && iter->next->data != data)
    {
        iter = iter->next;
    }
    if(iter->next == NULL){
        printf("Sayi bulunamadi.\n");
        return r;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    if(iter->next != NULL)
        iter->next->prev =iter;
    return r;
}  
int main(){
    struct node *head=NULL;
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