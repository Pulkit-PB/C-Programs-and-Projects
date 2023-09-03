#include<stdio.h>
#include<stdlib.h>

typedef struct dblist
{
    int value;
    struct dblist* next;
    struct dblist* prev;
    
}node;

node* createnode()
{
    int val;
    node* newnode;
    printf("\nEnter a value:");
    scanf("%d",&val);
    newnode=(node*)malloc(sizeof(node*));
    
    newnode->value=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    return newnode;
}

node* insertion(node* head, int lsize)
{
    int ch,pos;
    node* temp,*NN;
 
    node* newnode=createnode();

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
                head->prev=newnode;
                newnode->next=head;
                head=newnode;
                break;
            }

            case 2:
            {
                MID:
                {
                    temp=head;
                    printf("\nEnter the position:");
                    scanf("%d",pos);
                    if(pos>1 && pos<=lsize)
                    {
                        for(int i=1;i<pos-1;i++)
                        {
                            temp=temp->next;
                        }
                        NN=temp->next;
                        newnode->next=NN;
                        newnode->prev=temp;
                        NN->prev=newnode;
                        temp->next=newnode;
                        
                    } 
                    else
                    {
                        printf("Invalid Position!");
                        goto MID;
                    
                    }
                }
                break;
            }

            case 3:
            {
                temp=head;
                
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->prev=temp;
                break;
            }

        }
    }
    return head;

}

node * lastnode(node* head)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    return temp;
}


node* deletion(node* head, int lsize)
{
    node* temp; node* lnode;
    int val;
    temp=head;
    lnode=lastnode(head);
    if(head!=NULL)
    {
        printf("\nEnter the value to be deleted:");
        scanf("%d",&val);
        if(val!=temp->value && val!=lnode->value)
        {    
            while(temp->value!=val)
            {
                temp=temp->next;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
        else if(val==temp->value)
        {
            temp->next->prev=head;
            head=temp->next;

        }
    }
    else
    {
        printf("Invalid Operation!");
    
    }
    return head;

}


void display(node* head)
{   
    
    node* temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d  ", temp->value);
        temp=temp->next;

    }

}

//MAIN

int main()
{
    int chz;
    node* head=NULL;
    int ltsize=0;

    

    while(1)
    {

        printf("\nChoose an option:\n 1.Insertion\n 2.Deletion\n 3.Display\n 4.Exit\n=>");
        scanf("%d",&chz);

        switch(chz)
        {
            case 1:
            {
                head=insertion(head,ltsize);
                ltsize++;
                break;
            }

            case 2:
            {
                head=deletion(head,ltsize);
                ltsize--;
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

            default:
                printf("\nInvalid Choice!\n");
        }
    }
    
    return 0;
}

