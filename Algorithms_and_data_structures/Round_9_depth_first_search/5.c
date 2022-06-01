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
    int *color;
    struct node **adjLists;
};

struct Graph *createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc((vertices + 5) * sizeof(struct node *));
    graph->color = malloc((vertices + 5) * sizeof(int));

    for (int i = 1; i <= vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->color[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int first, int second) {
    struct node *newNode = createNode(first);
    newNode->next = graph->adjLists[second];
    graph->adjLists[second] = newNode;
}

void topological_sorting(struct Graph *graph, int vertex, Stack *stack) {
    graph->color[vertex] = 10;
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    while (temp != NULL) {
        if (graph->color[temp->vertex] == 0) {
            topological_sorting(graph, temp->vertex, stack);
        } else if (graph->color[temp->vertex] == 10) {
            printf("NO");
            exit(0);
        }
        temp = temp->next;
    }

    graph->color[vertex] = 100;
    push(stack, vertex);
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m, field_1, field_2;
    scanf("%d%d", &n, &m);
    struct Graph *graph = createGraph(n);
    Stack *stack = create();
    Stack *stack_1 = create();
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &field_1, &field_2);
        addEdge(graph, field_1, field_2);
    }

    for (int i = 1; i <= graph->numVertices; i++) {
        if (graph->color[i] == 0) {
            topological_sorting(graph, i, stack);
        }
    }

    int *answer = malloc(sizeof(int) * (n + 5));
    printf("YES\n");
    int count = n, element;
    while (!empty(stack)) {
        element = pop(stack);
        answer[element] = count;
        count--;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}
