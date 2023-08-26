#include<stdio.h>


void insertion(int z,int arr[])
{
    z=z+1;
    
    int x,y;
    printf("Enter the position to insert into:");
    scanf("%d",&x);
    printf("Enter the new element to insert:");
    scanf("%d",&y);
    //increasing the size of array
    for(int j=z-1;j>=x;j--)
    {
        arr[j]=arr[j-1];
    }
    arr[x-1]=y;
    for(int j=0;j<z;j++)
    {
        printf("%d",arr[j]);
    }
    printf("\n");
    
    
}


void deletion(int z,int arr[])
{
    int x,y;
    printf("Enter the position to delete:");
    scanf("%d",&x);
    for(int i=x-1;i<z-1;i++)
    {
        arr[i]=arr[i+1];
    }
    
    for(int j=0;j<z;j++)
    {
        printf("%d",arr[j]);
    }
    printf("\n");
    
}

void display(int z, int arr[])
{
    
    for(int i=0;i<z;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

int search(int arr[], int n)
{
    int x;
    printf("Enter the element to search:");
    scanf("%d",&x);  
    // Going through array sequencially
    for (int i=0;i<n;i++)
        if (arr[i]==x)
            return i;
          return -1;
}  

int binarySearch(int array[], int low, int high) 
{
    int x;
    printf("Enter the element to search:");
    scanf("%d",&x);
  // Repeat until the pointers low and high meet each other
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main(){
    int ele,i=0;
    printf("Enter the no. of elements for an array:");
    scanf("%d",&ele);
    int arr1[ele];
    while(i<ele)
    {
        printf("Enter the element:");
        scanf("%d",&arr1[i]);
        i++;
    }
    //Operations on array
    int a;
    int y=1;
    while(y==1)
    {   int size;
        
        
        printf("Choose an option:\n 1.Insert Element\n 2.Delete Element\n 3.Print Array\n 4.Search\n 5.Binary Search\n 6.Exit\n");    
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            {
                insertion(ele,arr1);
                ele=ele+1;
                printf("Done!");
                break;
            }
            
            case 2:
            {
               deletion(ele,arr1);
               ele=ele-1;
               break; 
            }
            
            case 3:
            {
                display(ele,arr1);
                break;
            }

            case 4:
            {
                int result = search(arr1,ele);
                (result == -1) ? printf("Element not found") : printf("Element found at index: %d", result);
                printf("\n");
                break;

            }

            case 5:
            {
                int result = binarySearch(arr1, 0, ele - 1);
                    if (result == -1)
                        printf("Not found");
                    else
                        printf("Element is found at index %d", result);
            }

            case 6:
            {
                y=2;
                break;
            }
        }
    }

    printf("Program Ended");
    return 0;


}