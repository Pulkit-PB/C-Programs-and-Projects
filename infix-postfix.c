#include <stdio.h>
#include <string.h>
int Top=-1;


void Push(char arr[],char x,int size)
{
    
    if(Top==size-1)
    {
        printf("Overflow!");
    }
    else
    {
        Top=Top+1;
        arr[Top]=x;
    }
}


int Pop()
{
    if(Top<0)
    {
        printf("underflow");
        return Top;
    }
    else
    {
        Top=Top-1;
        return Top+1;
    }

    
}

int check(char x)
{
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    if(x=='^')
        return 3;
    if(x==')')
        return 4;
}



char in_post(char s)
{
    char strfn[100]="";
    char strfin[100]="";
    char str = s;
    int size=strlen(str);
    char arr[size];

    Push(arr,'(',size);

    for(int i=0;i<size;i++)
    {
        char ch=str[i];
        if(ch!='+'||ch!='*'||ch!='-'||ch!='/'||ch!='^')
        {
            strfin=strcat(strfn,ch);
            strfn=strfin;
        }
        else
        {
            char z=arr[Top];
            int a=check(ch);
            int b=check(z);
            if(b<a)
            {
                Push(arr,ch,size);
            }
            else if(b>=a)
            {
                if(b==4)
                {
                    char op[]="";
                    while(op!='(')
                    {
                        char f=arr[Pop()];
                        strfin=strcat(strfn,f);
                        strfn=strfin;
                        op=arr[Top];
                    }

                }
                
                else
                {
                    strfin=strcat(strfn,arr[Pop()]);
                    strfn=strfin;
                }
               

            }

            
        }
    }

    return strfn;    

}


void main()
{   
    char string[100];
    char strfin[100];
    printf("Enter an infix statement within parenthesis:\n");
    scanf("%s",&string);
    strfin=in_post(string);
    printf("The postfix expression for given statement is =>\n");
    printf("%s",strfin);
}
}