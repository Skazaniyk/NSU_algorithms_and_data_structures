#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

struct node *createNode(int v) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph {
    int numVertices;
    int *visited;
    struct node **adjLists;
};

struct Graph *createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc((vertices + 5) * sizeof(struct node *));
    graph->visited = malloc((vertices + 5) * sizeof(int));

    for (int i = 1; i <= vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest) {

    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(struct Graph *graph, int vertex, int k) {
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    graph->visited[vertex] = k;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex, k);
        }
        temp = temp->next;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m, field_1, field_2, s, number;
    scanf("%d%d", &n, &m);
    struct Graph *graph = createGraph(n);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &field_1, &field_2);
        addEdge(graph, field_1, field_2);
    }

    int count = 0, k = 1;
    for (int i = 1; i <= graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            DFS(graph, i, k);
            count++;
            k++;
        }
    }

    printf("%d\n", count);

    for (int i = 1; i <= graph->numVertices; i++) {
        printf("%d ", graph->visited[i]);
    }

    return 0;
}
