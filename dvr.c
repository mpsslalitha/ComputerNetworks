//dvr
#include<stdio.h>
int temp[20][20], dist[20][20],i,j,k,n;
void dvr();
int main(){
    printf("Enter no.of nodes: ");
    scanf("%d", &n);
    printf("Enter distance matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &dist[i][j]);
            dist[i][i] = 0;
            temp[i][j] = j;
        }
    }
    dvr();
    return 0;
}
void dvr()
{
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            for(k = 0; k < n; k++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    temp[i][j] = k;
                }
            }
        }
    }
    
    for(i = 0; i < n; i++){
        printf("Routing table for %d\n", i+1);
        printf("To\tCost\tNext\n");
        for(j = 0; j < n; j++){
            if(temp[i][j] + 1== j+1){
                printf("%d\t%d\t--\n", j+1,dist[i][j]);
            }
            else{
                printf("%d\t%d\t%d\n",j+1,dist[i][j],temp[i][j]+1);
            }
        }
    }
}

Output:


Enter no.of nodes: 5
Enter distance matrix:
0 5 2 3 99
5 0 4 99 3
2 40    0 99 4
3 99 99 0 99
99 3 4 99 0
Routing table for 1
To	Cost	Next
1	0	--
2	5	--
3	2	--
4	3	--
5	6	3
Routing table for 2
To	Cost	Next
1	5	--
2	0	--
3	4	--
4	8	1
5	3	--
Routing table for 3
To	Cost	Next
1	2	--
2	4	--
3	0	--
4	5	1
5	4	--
Routing table for 4
To	Cost	Next
1	3	--
2	8	1
3	5	1
4	0	--
5	9	1
Routing table for 5
To	Cost	Next
1	6	3
2	3	--
3	4	--
4	9	1
5	0	--
