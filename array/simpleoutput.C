#include <stdio.h>
int main()
{
   char nm[20];
   printf("Enter your name:");
   scanf("%s",&nm);
   printf("Welcome to VsCode, %s",nm);
   fflush(stdout);

   return 0;
}