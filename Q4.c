#include <stdio.h>

//Function for Product - Sum (of digits of a number)
int product_sum(int n){
    int product=1;
    int sum=0;
    if(n<=0){
        printf("Invalid input, n must be greater than 0.\n");
        return 0;
    }
    while(n>0){
        int lastDigit= n%10;
        product*=lastDigit;
        sum+=lastDigit;
        n/=10;
    }
    return (product-sum);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", product_sum(n));
    return 0;
}