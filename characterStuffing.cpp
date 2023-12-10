//Character stuffing and destuffing
#include <stdio.h>
#include<string.h>
void stuffing(char s[], char res[], char start, char end, char esc){
    int i = 0, ind = 0;
    res[ind++] = start;
    for(i = 0; i < strlen(s); i++){
        if(s[i] == start || s[i] == end || s[i] == esc){
            res[ind++] = esc;
        }
        res[ind++] = s[i];
    }
    res[ind++] = esc;
    res[ind++] = '\0';
    printf("After Stuffing: %s\n", res);
}

void destuffing(char res[], char s1[], char start, char end, char esc){
    int i = 1, ind = 0;
    s1[ind++] = res[i++];
    for(i = 2; i < strlen(res); i++){
        if(res[i] == start || res[i] == end || res[i] == esc){
            i++;
        }
        s1[ind++] = res[i];
    }
    res[ind++] = '\0';
    printf("After deStuffing: %s\n", s1);
}

int main()
{
    char s[20], res[20],s1[20];
    char start = '@', end = '$', esc = '#';
    printf("Enter string: ");
    scanf("%s", s);
    stuffing(s,res,start,end,esc);
    destuffing(res,s1,start,end,esc);
    return 0;
}
