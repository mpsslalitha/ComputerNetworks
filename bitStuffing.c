//Bit Stuffing and destuffing
#include<stdio.h>
#include<string.h>
void stuffing(char s[], char res[]){
    int i, count = 0, ind = 0;
    for(i = 0; i < strlen(s); i++){
        if(count == 5){
            res[ind++] = '0';
            count = 0;
        }
        else if(s[i] == '1'){
            count++;
        }
        else{
            count = 0;
        }
        res[ind++] = s[i];
    }
    printf("After stuffing: %s\n", res);
}

void destuffing(char res[], char s1[]){
    int i, count = 0, ind = 0;
    for(i = 0; i < strlen(res); i++){
        if(count == 5){
            i++;
            count = 0;
        }
        else if(res[i] == '1'){
            count++;
        }
        else{
            count = 0;
        }
        s1[ind++] = res[i];
    }
    printf("After destuffing: %s\n", s1);
}
int main(){
    char s[20], res[20], s1[20];
    int i;
    printf("Enter bit string: ");
    scanf("%s",s);
    stuffing(s,res);
    destuffing(res,s1);
    return 0;
}
