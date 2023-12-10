#include<stdio.h>
#include<string.h>
int main()
{
    char s[20], d[10], p[20];
    int i = 0, len, k;
    printf("Enter frame: ");
    scanf("%s", s);
    printf("Enter generative polynomial: ");
    scanf("%s", d);
    len = strlen(s);
    k = strlen(d) - 1;
    strcpy(p,s);
    for(i = len; i< len + k; i++){
        p[i] = '0';
    }
    printf("After adding zero at the end: %s", p);
    printf("Order of process: ");
    while(strlen(p) > k){
        if(p[0] == '1'){
            for(i = 0; i < strlen(d); i++){
                p[i] = (p[i] - '0') ^ (d[i] - '0') + '0';
            }
        }
        else{
            for(i = 0; i < strlen(p); i++){
                p[i] = p[i+1];
            }
            printf("%s\n",p);
        }
    }
    strcat(s,p);
    printf("Transmitted Frame is: %s", s);
    return 0;
}


Output:

Enter frame: 11010
Enter generative polynomial: 1011
After adding zero at the end: 11010000Order of process: 1100000
111000
10100
0010
010
Transmitted Frame is: 11010010
