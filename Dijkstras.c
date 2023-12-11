
// //dijkstra's Algo
#include <stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 6

int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;
    for(int i = 0; i < V; i++){
        if(sptSet[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printDistance(int dist[]){
    printf("Distance from source to other:\n");
    for(int i = 0; i < V; i++){
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool sptSet[V];
    for(int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for(int count = 0; count < V-1; count++){
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        
        for(int v= 0; v < V; v++)
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printDistance(dist);
}
int main()
{
    int graph[V][V] = {{0,2,0,0,1,5},{2,0,3,6,0,3},
                        {0,3,0,4,0,0},{0,6,4,0,1,5},
                        {1,0,0,1,0,2},{5,3,0,5,2,0}};
    // int graph[V][V] = {{0,2,4,0,0,0}, {0,0,1,7,0,0}, {0,0,0,0,3,0}, {0,0,0,0,0,1}, {0,0,0,2,0,5}, {0,0,0,0,0,0}};
    dijkstra(graph,0);
    return 0;
}

Output:


Distance from source to other:
0		0
1		2
2		5
3		2
4		1
5		3
