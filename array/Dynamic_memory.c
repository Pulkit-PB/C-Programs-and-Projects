#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, *arr1;
    int n1, n2;
    
    arr=(int*)malloc(sizeof(int));
    arr1=(int*)calloc(1,sizeof(int));
    
    if(arr==NULL)
    {
        printf("Memory allocation failed!");
    }
    else
    {
        if(arr1==NULL)
        {
            printf("Memory allocation failed!");
        }
        else
        {
            printf("Memory has been successfully allocated by "
            "using malloc\n");
            printf("\n array1 = %pc\n",arr);
            printf("\n array2 = %pc\n",arr1);
            //creating 2 arrays dynamically with user inputs
            n1=0;
            int a;
            do{
                printf("\nEnter an element into the array:\n");
                scanf("%d",&arr[n1]);
                printf("Do you want to enter more elements?[Y/N]");
                scanf("%d",&a);

                if(a==1)
                {
                    n1++;
                    arr=(int*)realloc(arr,(n1+1)*sizeof(int));

                    if(arr==NULL)
                    {
                        printf("Memory allocation failed!");
                        break;
                    }
                    else{
                        printf("Memory successfully reallocated using 'Realloc'");
                        printf("\nbase address of array1 are:%pc",arr);
                        
                    }

                }

            }while(a==1);

            n2=0;
            char b;
            do
            {
                printf("\nEnter an element into the array:");
                scanf("%d",&arr1[n2]);
                printf("Do you want to enter more elements?[Y/N]");
                scanf("%d",&b);

                if(b==1)
                {
                    n2++;
                    arr1=(int*)realloc(arr1,(n2+1)*sizeof(int));

                    if(arr1==NULL)
                    {    printf("Memory allocation failed!");
                        break;
                    }
                    else
                        printf("Memory successfully reallocated using 'Realloc'\n");
                    

                }

            }while(b==1);
            

    
        }
        //printing values of Arrays
        printf("\nArray 1 is: ");
        for(int i=0;i<=n1;i++)
        {
            printf("%d ",arr[i]);
        }

        printf("\n\nArray 2 is: ");
        for(int j=0;j<=n2;j++)
        {
            printf("%d ",arr1[j]);
        }
        //Freeing allocated memory
        free(arr);
        free(arr1);
    }
    return 0;
}
