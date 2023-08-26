#include<stdio.h>
int x;
int fact(int n){
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}
void main(){
    printf("enter a no.");
    scanf("%d",&x);
    int fac;
    fac=fact(x);
    printf("%d",fac);
    printf("%d is the factorial",fact(x));
}