//Leaky Bucket
#include<stdio.h>
int main(){
    int n,leak,left,storage=0, input,bs,i;
    printf("Enter bucket size: ");
    scanf("%d", &bs);
    printf("Enter no. of loops: ");
    scanf("%d",&n);
    printf("Enter leak:");
    scanf("%d", &leak);
    for(i = 0; i < n; i++){
        left = bs - storage;
        printf("Enter input: ");
        scanf("%d", &input);
        if(input <= left){
            printf("Frame is transmitted!");
            storage += input;
        }
        else{
            printf("Packet lost!");
        }
        printf("%d out of %d", storage, bs);
        storage -= leak;
    }
    return 0;
}
