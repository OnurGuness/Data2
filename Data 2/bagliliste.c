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

int main(){
    struct node *head=NULL;
    head =(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data=20;
    head->next->next = (struct node *)malloc(sizeof(struct node));
    head->next->next->data =30;
    head->next->next->next=NULL;
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    printf("%d",temp->data);
    temp = temp->next;
    printf("%d\n",temp->data);

    temp=head;
    int i=0;
    while (temp->next!=NULL)
    { 
        i++;
        printf("%dinci eleman: %d\n",i,temp->data);
        temp=temp->next;
    }
    for (i = 0; i < 5; i++)
    {
        temp->next=(struct node *)malloc(sizeof(struct node));
        temp=temp->next;
        temp->data=i*10;
        temp->next = NULL;
    }
    bastir(head);

    return 0;
}