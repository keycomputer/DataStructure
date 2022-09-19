#include<stdio.h>
int sum()
{
    int a,b;
    printf("enter 1st no.");
    printf("enter 2nd no.");
    scanf("%d%d",&a,&b);
    return(a+b);
}
int main()
{int result;
result=sum();
printf("%d",result);
return 0;}