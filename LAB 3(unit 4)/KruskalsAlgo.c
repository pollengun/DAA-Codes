#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Find the parent of a vertex using Union-Find
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// Apply union operation
void applyUnion(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Comparison function for qsort
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Kruskal's algorithm with timing
void kruskal(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0, i = 0;

    // Start timing
    clock_t start_time = clock();

    // Sort edges by weight
    qsort(graph->edges, graph->E, sizeof(struct Edge), compareEdges);

    int parent[V], rank[V];
    for (int v = 0; v < V; ++v) {
        parent[v] = v;
        rank[v] = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edges[i++];
        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            applyUnion(parent, rank, x, y);
        }
    }

    // Stop timing
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Edges in the minimum spanning tree:\n");
    for (int j = 0; j < e; ++j)
        printf("%d - %d: %d\n", result[j].src, result[j].dest, result[j].weight);

    printf("Execution time: %.6f seconds\n", execution_time);
}

int main() {
    int V = 6; // Number of vertices
    int E = 9; // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Add edges (src, dest, weight)
    graph->edges[0] = (struct Edge){0, 1, 4};
    graph->edges[1] = (struct Edge){0, 2, 4};
    graph->edges[2] = (struct Edge){1, 2, 2};
    graph->edges[3] = (struct Edge){1, 3, 5};
    graph->edges[4] = (struct Edge){2, 3, 5};
    graph->edges[5] = (struct Edge){3, 4, 7};
    graph->edges[6] = (struct Edge){4, 5, 8};
    graph->edges[7] = (struct Edge){2, 5, 10};
    graph->edges[8] = (struct Edge){3, 5, 11};

    kruskal(graph);

    // Free the allocated memory
    free(graph->edges);
    free(graph);

    return 0;
}
