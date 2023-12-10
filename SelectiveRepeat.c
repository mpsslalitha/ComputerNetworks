//Selective repeat
#include<stdio.h>
int main(){
    int n,ws,i,ack,c,v, f[10],w[5];
    printf("Enter no.of frames: ");
    scanf("%d", &n);
    printf("Enter window size: ");
    scanf("%d",&ws);
    for(i = 0; i < n; i++){
        f[i] = i;
    }
    for(i = 0; i < ws; i++){
        printf("Frame %d transmitted!\n", i);
        w[i] = i;
    }
    c = ws;
    while(c < n){
        printf("Frame %d received? 0 - NACK, 1 - ACK: ", w[0]);
        scanf("%d", &ack);
        if(ack == 1){
            printf("Frame %d transmitted!\n", f[c]);
            for(i = 0; i < ws; i++){
                w[i] = w[i+1];
            }
            w[ws-1] = f[c];
            c++;
        }
        else{
            printf("Frame %d transmitted!\n", w[0]);
            v = w[0];
            for(i = 0; i < ws; i++){
                w[i] = w[i+1];
            }
            w[ws-1] = v;
        }
        printf("Window is:\n");
        for(i = 0; i < ws; i++){
            printf("%d  ", w[i]);
        }
    }
    while(ws > 0){
        printf("Frame %d received? 0 - NACK, 1 - ACK: ", w[0]);
        scanf("%d", &ack);
        if(ack == 1){
            for(i = 0; i < ws; i++){
                w[i] = w[i+1];
            }
            ws -= 1;
        }
        else{
            printf("Frame %d transmitted!\n", w[0]);
            v = w[0];
            for(i = 0; i < ws; i++){
                w[i] = w[i+1];
            }
            w[ws-1] = v;
        }
        printf("Window is:\n");
        for(i = 0; i < ws; i++){
            printf("%d  ", w[i]);
        }
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
Frame 0 received? 0 - NACK, 1 - ACK: 1
Frame 4 transmitted!
Window is:
1  2  3  4  Frame 1 received? 0 - NACK, 1 - ACK: 0
Frame 1 transmitted!
Window is:
2  3  4  1  Frame 2 received? 0 - NACK, 1 - ACK: 1
Frame 5 transmitted!
Window is:
3  4  1  5  Frame 3 received? 0 - NACK, 1 - ACK: 1
Window is:
4  1  5  Frame 4 received? 0 - NACK, 1 - ACK: 0
Frame 4 transmitted!
Window is:
1  5  4  Frame 1 received? 0 - NACK, 1 - ACK: 1
Window is:
5  4  Frame 5 received? 0 - NACK, 1 - ACK: 1
Window is:
4  Frame 4 received? 0 - NACK, 1 - ACK: 0
Frame 4 transmitted!
Window is:
4  Frame 4 received? 0 - NACK, 1 - ACK: 0
Frame 4 transmitted!
Window is:
4  Frame 4 received? 0 - NACK, 1 - ACK: 1
Window is:
