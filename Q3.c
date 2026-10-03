#include <stdio.h>

//fuction for checking palindrome number if not then giving sum of original and reverse
int palindrome_or_sum(int n){
    int original=n;
    int reverse= 0;
    
    

    while(n!=0){
        int lastDigit= n%10;
        reverse= reverse*10 + lastDigit;
        n/=10;
    }
    
    if(original==reverse && original >=0){
        return original;
    }
    else{
        return original + reverse;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", palindrome_or_sum(n));
    return 0;
}