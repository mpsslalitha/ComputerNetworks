//stop and wait
#include<stdio.h>
int main(){
    int n, i , ack;
    printf("Enter no.of frames: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        printf("Frame %d has been transmitted!",i);
        printf("Frame received? 0 NACK, 1 ACk");
        scanf("%d", &ack);
        if(ack == 0) i -= 1;
    }
    return 0;
}

Output:

Enter no.of frames: 6
Frame 1 has been transmitted!Frame received? 0 NACK, 1 ACk1
Frame 2 has been transmitted!Frame received? 0 NACK, 1 ACk0
Frame 2 has been transmitted!Frame received? 0 NACK, 1 ACk1
Frame 3 has been transmitted!Frame received? 0 NACK, 1 ACk1
Frame 4 has been transmitted!Frame received? 0 NACK, 1 ACk1
Frame 5 has been transmitted!Frame received? 0 NACK, 1 ACk9
Frame 6 has been transmitted!Frame received? 0 NACK, 1 ACk0
Frame 6 has been transmitted!Frame received? 0 NACK, 1 ACk0
Frame 6 has been transmitted!Frame received? 0 NACK, 1 ACk1
