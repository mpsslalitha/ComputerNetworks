//go back n
#include<stdio.h>
int main(){
    int n,ws,i,ack, f = 0, sent;
    printf("Enter no.of frames: ");
    scanf("%d", &n);
    printf("Enter window size: ");
    scanf("%d",&ws);
    while(f != 1){
        for(i = 0; i < ws; i++){
            printf("Frame %d transmitted!\n", sent);
            sent++;
            if(sent == n + 1) break;
        }
        printf("Enter frame no. which is received: ");
        scanf("%d", &ack);
        if(ack == n) f = 1;
        sent = ack + 1;
    }
    return 0;
}

Output:

Enter no.of frames: 6
Enter window size: 4
Frame 0 transmitted!
Frame 1 transmitted!
Frame 2 transmitted!
Frame 3 transmitted!
Enter frame no. which is received: 1
Frame 2 transmitted!
Frame 3 transmitted!
Frame 4 transmitted!
Frame 5 transmitted!
Enter frame no. which is received: 3
Frame 4 transmitted!
Frame 5 transmitted!
Frame 6 transmitted!
Enter frame no. which is received: 5
Frame 6 transmitted!
Enter frame no. which is received: 6
