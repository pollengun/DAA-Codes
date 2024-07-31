#include <stdio.h>
#include <limits.h>
#include <time.h>

#define V 4 // Number of vertices (you can adjust this)

void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int i, j, k;

    // Initialize the distance matrix with the input graph
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Compute shortest paths for all pairs of vertices
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances between all pairs of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    clock_t start_time = clock(); // Start the timer

    floydWarshall(graph);

    clock_t end_time = clock(); // Stop the timer

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Execution time: %.6f seconds\n", execution_time);

    return 0;
}
