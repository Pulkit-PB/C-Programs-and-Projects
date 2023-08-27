#include<stdio.h>
#include <stdlib.h>

typedef struct Linked_list
{
    int value;
    struct Linked_list *next;
}Node;

Node* createnode()
{
    Node* newnode;
    int val;
    printf("\nEnter a value:");
    scanf("%d",&val);
    newnode=(Node*)malloc(sizeof(Node*));
    newnode->value=val;
    newnode->next=NULL;
    return newnode;

}

Node* insertion(Node* head,int ltsize)
{
    Node* newnode;
    int ch,pos;
    Node* temp;

    newnode=createnode();

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        printf("\nChoose an option:\n 1.At Beginning\n 2.In the Middle\n 3.At End\n=>");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                newnode->next=head;
                head=newnode;
                break;
            }

            case 2:
            {
                temp=head;
                printf("Enter the position:");
                scanf("%d",&pos);
                if(pos>1 && pos<ltsize)
                {
                    for(int i=1;i<pos-1;i++)
                    {
                        temp=temp->next;
                    }

                    newnode->next=temp->next;
                    temp->next=newnode;
                    break;
                }
                
                else
                {
                    printf("Inavlid Position");
                }            
            }

            case 3:
            {
                temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                
                temp->next=newnode;
                newnode->next=NULL;
            }
        }
    }

    return head;
}

Node* deletion(Node* head,int ltsize){

    return head;
}


void display(Node* head)
{
    Node* temp=head;
    while(temp->next!=NULL)
    {
        printf("\n");
        printf("%d ",temp->value);
        temp=temp->next;
    }
    

}

int main()
{
    Node* head=NULL;
    int chz,lsize=0;
    while(1)
    {
        printf("Choose an option:\n 1.Insertion\n 2.Deletion\n 3.Display\n 4.Exit\n=>");
        scanf("%d",&chz);
        switch(chz)
        {
            case 1:
            {
                head=insertion(head,lsize);
                lsize++;
                break;
            }

            case 2:
            {
                head=deletion(head,lsize);
                lsize--;
                break;
            }

            case 3:
            {
                display(head);
                break;
            }

            case 4:
            {
                exit(0);
                break;
            }
        }

    }    
}