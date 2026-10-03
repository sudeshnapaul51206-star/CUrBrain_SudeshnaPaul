#include <stdio.h>

//Fuction to replace even digits with zero
int count_Digit(int n){
    int count=0;
    if(n==0){
        count=1;
    }
    else{
        while(n!=0){
            count+=1;
            n/=10;
        }
    }
    return count;
}
void EvenReplace(int n){
    int len= count_Digit(n);
    int arr[len];
    for(int i=len-1;i>=0;i--){
        int lastdigit= n%10;
        if(lastdigit % 2 ==0){
            lastdigit=0;
        }
        arr[i]=lastdigit;
        n/=10;
    }
    printf("[ ");
    for(int j=0;j<len;j++){
        printf("%d", arr[j]);
        if(j<len-1){
            printf(", ");
        }
    }
    printf(" ]");
}
int main(){
    int n;
    scanf("%d", &n);
    EvenReplace(n);
    return 0;
}