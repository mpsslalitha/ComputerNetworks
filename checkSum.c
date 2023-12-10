#include<stdio.h>
int senderCheck(int a[], int n){
    int sum = 0,i, check = 0;
    for(i = 0; i < n; i++){
        sum += a[i];
    }
    check = ~sum;
    printf("Check sum is: %d\n",check);
    return check;
}

int receiverCheck(int a[], int n, int checksum){
    int sum = 0,i, check;
    for(i = 0; i < n; i++){
        sum += a[i];
    }
    sum += checksum;
    check = ~sum;
    printf("Check sum is: %d\n",check);
    return check;
}
int main(){
    int a[10], i, n;
    printf("Enter no.of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ",n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int sender = senderCheck(a,n);
    int receiver = receiverCheck(a,n,sender);
    if(receiver == 0){
        printf("\nData is transmitted without any errors!");
    }
    else{
        printf("Error in data transmission!");
    }
}


Output:

Enter no.of elements: 4
Enter 4 elements: 10110001
10101011
00110101
10100001
Check sum is: -30421115
Check sum is: 0

Data is transmitted without any errors!
