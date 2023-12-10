#include<stdio.h>
int main(){
    int data[10], i, data1[10], num;
    printf("Enter data:");
    scanf("%d", &data[0]);
    scanf("%d", &data[1]);
    scanf("%d", &data[2]);
    scanf("%d", &data[4]);
    data[6] = data[0] ^ data[2] ^ data[4];
    data[5] = data[0] ^ data[1] ^ data[4];
    data[3] = data[0] ^ data[1] ^ data[2];
    printf("Transmitted data is:\n");
    for(i = 0; i < 7; i++){
        printf("%d ", data[i]);
    }
    
    printf("Enter data received by receiver: ");
    for(i = 0; i < 7; i++){
        scanf("%d",&data[i]);
    }
    
    data1[6] = data[0] ^ data[2] ^ data[4] ^ data[6];
    data1[5] = data[0] ^ data[1] ^ data[4] ^ data[5];
    data1[3] = data[0] ^ data[1] ^ data[2] ^ data[3];
    num = (4 * data1[3]) + (2 * data1[5]) + data1[6];
    if(num == 0){
        printf("No error!");
    }
    else{
        printf("Error at %d",num);
    }
    return 0;
}

Output:

Enter data:1
0
1
0
Transmitted data is:
1 0 1 0 0 1 0 Enter data received by receiver: 1
1
1
0
0
1
0
Error at 6
