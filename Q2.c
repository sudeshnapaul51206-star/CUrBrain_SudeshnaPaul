#include <stdio.h>

//Fuction for reverse an integer and returning double
int r_d(int n){
    int reverse=0;
    int sign=1;
    if(n==0){
        return 0;
    }
    if(n<0){
        sign= -1;
        n= -n;
        
    }
    if(n>0){
        while(n!=0){
            int lastDigit= n%10;
            reverse= reverse*10 + lastDigit;
            n/=10;
        }
        return (sign * reverse * 2);
    }
    
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", r_d(n));
    return 0;
}