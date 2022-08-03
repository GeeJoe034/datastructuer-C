#include<stdio.h>
int main()
{

    int money,a=1;

    while(a > 0)
    {
        printf("\n Enter your money : ");
        scanf("%d",&money);
        a=money;
        
        
        if(money>=10){ //เหรียญ 10
        printf("\n 10 Baht = %d",money/10);
        money=money%10;
        }else {
            printf("\n 10 baht = 0");
        }
        if(money>=5) { //เหรียญ 5
        printf("\n  5 Baht = %d",money/5);
        money=money%5;
        }else {
        printf("\n  5 baht = 0");
        }
        if(money>=2){ //เหรียญ 2
        printf("\n  2 Baht = %d",money/2);
        money=money%2;
        }else {
        printf("\n  2 baht = 0");
        }
        if(money>=1){ // เหรียญ 1
        printf("\n  1 Baht = %d",money/1);
        money=money%1;
        }else {
        printf("\n  1 baht = 0");
        }
     }
    return 0;
}
