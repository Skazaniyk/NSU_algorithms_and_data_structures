#include <stdio.h>
#include "malloc.h"
#include "string.h"
#include "minmax.h"

#define MAX 300000

typedef struct node {
    int vertex;
    struct node *next;
} Node;

typedef struct Queue {
    int size;
    int first;
    int leng;
    int *arr;
} Queue;

Queue *create() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->first = 0;
    q->leng = 0;
    q->size = 1;
    q->arr = (int *) malloc(sizeof(int) * q->size);
    return q;
}

int empty(Queue *q) {
    return (q->leng == 0);
}

void enqueue(Queue *q, int a) {
    if (q->leng == q->size) {
        q->arr = (int *) realloc(q->arr, sizeof(int) * q->size * 2);
        if (q->first > 0)
            memcpy(q->arr + q->size, q->arr, (q->first) * sizeof(int));
        q->size *= 2;
    }
    q->arr[(q->first + q->leng++) % q->size] = a;
}

int dequeue(Queue *q) {
    int a = q->arr[q->first++];
    q->first %= q->size;
    q->leng--;
    return a;
}

Node *createNode(int v) {
    Node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

typedef struct Graph {
    int numVertices;
    int *visited;
    struct node **adjLists;
} Graph;

struct Graph *createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc((vertices + 5) * sizeof(struct node *));
    graph->visited = malloc((vertices + 5) * sizeof(int));

    for (int i = 1; i <= vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = MAX;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void BFS(Graph *graph, int started_vertex) {
    Queue *queue = create();
    graph->visited[started_vertex] = 0;
    enqueue(queue, started_vertex);

    while (!empty(queue)) {
        int current_vertex = dequeue(queue);
        Node *temp = graph->adjLists[current_vertex];

        while (temp) {
            int number_vertex = temp->vertex;

            if (graph->visited[number_vertex] == MAX) {
                enqueue(queue, number_vertex);
            }
            graph->visited[number_vertex] = min(graph->visited[current_vertex] + 1, graph->visited[number_vertex]);

            temp = temp->next;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, field_1, field_2;
    char symbol;
    scanf("%d", &n);
    int **array = malloc(sizeof(int *) * (n + 5));
    for (int i = 0; i <= n; i++) {
        array[i] = malloc(sizeof(int) * (n + 5));
    }
    for (int i = 1; i <= n; i++) {
        scanf("%c", &symbol);
        for (int j = 1; j <= n; j++) {
            scanf("%c", &symbol);
            if (symbol == '1') {
                array[i][j] = 1;
            } else {
                array[i][j] = 0;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (array[i][k] && array[k][j]) {
                    array[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        array[i][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}