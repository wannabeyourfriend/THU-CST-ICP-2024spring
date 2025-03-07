#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define INF 99999

int graph[MAX_NODES][MAX_NODES];
char nodes[MAX_NODES][2]; // Assuming node names are single characters
int dist[MAX_NODES];
int prev[MAX_NODES];

int minDistance(int dist[], int sptSet[], int n) {
    int min = INF;
    int min_index;

    for (int v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int j) {
    if (prev[j] == -1) {
        printf("%c ", nodes[j]);
        return;
    }

    printPath(prev[j]);
    printf("%c ", nodes[j]);
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int src, int dest, int n) {
    int sptSet[MAX_NODES];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
        prev[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    //printf("Shortest path from %c to %c is: ", nodes[src], nodes[dest]);
    printPath(dest);
}

int main() {
    FILE *file = fopen("./graph.txt", "r");
    char line[100];
    int n = 0;

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, "|");
        strcpy(nodes[n], token);
        token = strtok(NULL, "|");
        while (token != NULL) {
            char dest;
            int weight;
            sscanf(token, " %c:%d", &dest, &weight);
            int destIndex = dest - 'A';
            graph[n][destIndex] = weight;
            token = strtok(NULL, " ");
        }
        n++;
    }

    fclose(file);

    char start, end;
    scanf("%c %c", &start, &end);

    dijkstra(graph, start - 'A', end - 'A', n);

    return 0;
}
