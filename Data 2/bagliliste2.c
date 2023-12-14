#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void bastir(struct node * r){
    while (r!=NULL)
    {
        printf("%d ",r->data);
        r=r->next;
    }
    
}
void ekle(struct node*r,int data){
    while (r->next!=NULL){
        r=r->next;
    }
    r->next =(struct node*)malloc(sizeof(struct node));
    r->next->data=data;
    r->next->next = NULL;
};
struct node *ekleSirali(struct node *r,int data){
    if(r==NULL){
        r=(struct node*)malloc(sizeof(struct node));
        r->next=NULL;
        r->data=data;
        
        
        return r;
    }
    if(r->data>data){
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next =r;
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
    temp->data=data;
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
   

    return 0;
}