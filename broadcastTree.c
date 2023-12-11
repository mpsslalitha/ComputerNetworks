//krushkals
#include<stdio.h>
int i,j,p,q,u,v,min = 99, mincost = 0,n;
int t[20][2], parent[20], edge[20][20];
int find(int i){
    if(parent[i] > 0){
        i = parent[i];
    }
    return i;
}
void sunion(int p, int q){
    parent[p] = q;
}
int main()
{
    printf("Enter no.of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n;i++){
        printf("%c\t", 65+i);
        parent[i] = -1;
    }
    for(i = 0; i < n; i++){
        printf("%c ",65+i);
        for(j = 0; j < n; j++){
            scanf("%d",&edge[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(edge[i][j] != 99){
                if(min > edge[i][j]){
                    min = edge[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        p = find(u);
        q = find(v);
        if(p!= q){
            t[i][0] = u;
            t[i][1] = v;
            mincost += edge[u][v];
            sunion(p,q);
        }
        else{
            t[i][0] = -1;
            t[i][1] = -1;
        }
        min = 99;
    }
    printf("mincost: %d\n", mincost);
    printf("spanning tree\n");
    for(i = 0; i < n; i++){
        if(t[i][0] != -1 && t[i][1] != -1){
            printf("%c  %c  %d\n", 65+t[i][0], 65+t[i][1], edge[t[i][0]][t[i][1]]);
        }
    }
}

Output:

Enter no.of nodes: 4
A	B	C	D	A 1 3 5 6
B 6 7 8 9
C 2 3 5 6
D 1 2 9 7
mincost: 9
spanning tree
B  A  6
C  A  2
D  A  1
