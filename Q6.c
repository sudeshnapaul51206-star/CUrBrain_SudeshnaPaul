#include <stdio.h>

//Function for Digit Frequency Difference
int digit_frequency_difference(int n, int a, int b){
    int countA=0;
    int countB=0;

    if(n==0){
        if(a==0){
            countA++;
        }
        if(b==0){
            countB++;
        }
    }
    else{
        while(n != 0){
            int digit= n%10;
            if(digit==a){
                countA++;
            }
            if(digit==b){
                countB++;    
            }
            n=n/10;
        }
    }
    if(countA> countB){
        return countA-countB;
    }
    else{
        return countB-countA;
    }
}
int main(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", digit_frequency_difference(n, a, b));

    return 0;
}