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

void DFS(struct Graph *graph, int vertex) {
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    graph->visited[vertex] = 1;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, field_1, field_2;
    scanf("%d", &n);
    struct Graph *graph = createGraph(n);
    while (scanf("%d", &field_1) == 1) {
        scanf("%d", &field_2);
        addEdge(graph, field_1, field_2);
    }

    int count = 0;
    for (int i = 1; i <= graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            DFS(graph, i);
            count++;
        }
    }

    printf("%d", count + 1);
    return 0;
}
