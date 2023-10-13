#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct node *head1,*head2,*temp2,*temp1,*newnode;
int count1=0,count2=0;

struct node* create1(struct node *head1){
    int choice=1;
    while (choice!=0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head1==0){
            head1=newnode;
            temp1=newnode;
        }
        else
        {
            temp1->next=newnode;
            temp1=newnode; 
        }
        printf("Do you want to continue:");
        scanf("%d",&choice);  
        count1++; 
    }
    return head1;
}

void print(struct node *temp1){
    printf("\nThe list is\n");
    while(temp1!=0){
        printf("%d\t",temp1->data);
        temp1=temp1->next;
    }
}

struct node* reverse(struct node *head){
    struct node *temp,*prevnode,*nextnode;
    prevnode=0;
    temp=head;
    nextnode=head;
    while (nextnode!=0)
    {
        nextnode=nextnode->next;
        temp->next=prevnode;
        prevnode=temp;
        temp=nextnode;
    }
    head=prevnode;
    return head;
}

struct node *add_nodes(struct node *head1 ,struct node *head2){
    temp1=head1;
    temp2=head2;
//    struct node *o=reverse(temp1);
//    print(o);
    temp1=reverse(temp1);
    temp2=reverse(temp2);
    struct node *t,*h=0;
    int carry=0;
    while (temp1!=0 && temp2!=0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        int sum=0;
        if (carry==1)
        {
            sum=temp1->data +temp2->data +carry;
            carry=0;
        }
        else{
            sum=temp1->data+temp2->data;
        }
        if(sum>9){
            carry=1;
            sum=sum%10;
            newnode->data=sum;
            newnode->next=NULL;
            if (h==0)
            {
                h=newnode;
                t=newnode;
            }
            else{
                t->next=newnode;
                t=newnode;
            }   
        }
        else{
            newnode->data=sum;
            if (h==0)
            {
                h=newnode;
                t=newnode;
            }
            else{
                t->next=newnode;
                t=newnode;
            } 
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if (carry==1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=carry;
        newnode->next=NULL;
        t->next=newnode;
        t=newnode;
    }
//    h->next=NULL;
    h=reverse(h);
    return h;
}

int main(){
    head1=0;
    head2=0;
    head1=create1(head1);
    head2=create1(head2);
    temp1=head1;
    print(temp1);
    temp2=head2;
    print(temp2);
    head1=add_nodes(head1,head2);
//    temp1=head1;
    print(head1);
    return 0;
}