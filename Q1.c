#include <stdio.h>

//Fuction for checking if the digit count of n is even or odd
int EvenOdd(int n){
    int count=0;
    if(n<0){
        n=-n;
    }
    if(n==0){
        count=1;
    }
    else{
        while(n!=0){
            count+=1;
            n/=10;
        }
    }
    return (count %2 == 0);
}

int main(){
    int n;
    scanf("%d", &n);
    if(EvenOdd(n)){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    return 0;
}