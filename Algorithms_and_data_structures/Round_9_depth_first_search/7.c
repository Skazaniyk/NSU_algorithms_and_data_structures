#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int size;
    int top;
    int *arr;
} Stack;

Stack *create() {
    Stack *s;
    s = (Stack *) malloc(sizeof(Stack));
    s->top = 0;
    s->size = 1;
    s->arr = (int *) malloc(sizeof(int) * s->size);

    return s;
}

int empty(Stack *S) {
    return (S->top == 0);
}

int pop(Stack *S) {
    int a = S->arr[S->top - 1];
    S->top--;
    return a;
}

void push(Stack *S, int a) {
    if (S->top == S->size) {
        S->size *= 2;
        S->arr = (int *) realloc(S->arr, sizeof(int) * S->size);
    }
    S->arr[S->top++] = a;
}

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

void DFS_2(struct Graph *graph, int vertex, Stack *stack) {
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    graph->visited[vertex] = 1;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS_2(graph, connectedVertex, stack);
        }
        temp = temp->next;
    }

    push(stack, vertex);
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m, field_1, field_2;
    scanf("%d%d", &n, &m);
    struct Graph *graph_1 = createGraph(n);
    struct Graph *graph_2 = createGraph(n);
    Stack *stack = create();

    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &field_1, &field_2);
        addEdge(graph_1, field_1, field_2);
        addEdge(graph_2, field_2, field_1);
    }

    for (int i = 1; i <= n; i++) {
        if (graph_1->visited[i] == 0) {
            DFS_2(graph_1, i, stack);
        }
    }

    int number, ans = 1;
    for (int i = 1; i <= n; i++) {
        number = pop(stack);
        if (graph_2->visited[number] == 0) {
            DFS(graph_2, number, ans);
            ans++;
        }
    }

    printf("%d\n", ans - 1);
    for (int i = 1; i <= n; i++) {
        printf("%d ", graph_2->visited[i]);
    }

    return 0;
}
