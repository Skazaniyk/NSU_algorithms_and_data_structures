#include <stdio.h>
#include "malloc.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define MAXN 1000
int p[MAXN], rank[MAXN];

typedef struct node {
    int vertex;
    struct node *next;
} Node;

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

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void makeset(int x) {
    p[x] = x;
    rank[x] = 0;
}

int find_set(int x) {
    if (x == p[x]) return x;
    return p[x] = find_set(p[x]);
}

void union_(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
        return;
    }
    if (rank[x] > rank[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if (rank[x] == rank[y]) {
            ++rank[y];
        }

    }
}

typedef struct Gorod {
    int x;
    int y;
} Gorod;

typedef struct Way {
    int gorod_1;
    int gorod_2;
    int x_1;
    int y_1;
    int x_2;
    int y_2;
    double len_of_path;
} Way;

typedef struct Queue {
    int size;
    int first;
    int leng;
    Way *arr;
} Queue;

Queue *create() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->first = 0;
    q->leng = 0;
    q->size = 1;
    q->arr = (Way *) malloc(sizeof(Way) * q->size);
    return q;
}

void enqueue(Queue *q, Way a) {
    if (q->leng == q->size) {
        q->arr = (Way *) realloc(q->arr, sizeof(Way) * q->size * 2);
        if (q->first > 0)
            memcpy(q->arr + q->size, q->arr, (q->first) * sizeof(Way));
        q->size *= 2;
    }
    q->arr[(q->first + q->leng++) % q->size] = a;
}

double len_vector(int x_1, int y_1, int x_2, int y_2) {
    return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
}

int cmp(const void *one, const void *two) {
    if (((Way *) one)->len_of_path > ((Way *) two)->len_of_path) {
        return 1;
    }
    if (((Way *) one)->len_of_path < ((Way *) two)->len_of_path) {
        return -1;
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m, gorod_1, gorod_2, x, y;
    scanf("%d", &n);
    Graph *graph = createGraph(n + 5);
    Gorod *goroda = malloc(sizeof(Gorod) * (n + 5));
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        goroda[i].x = x;
        goroda[i].y = y;
        makeset(i);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &gorod_1, &gorod_2);
        addEdge(graph, gorod_1, gorod_2);
        union_(gorod_1, gorod_2);
    }

    Queue *array = create();
    Way ways;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (find_set(i) != find_set(j)) {
                ways.gorod_1 = i;
                ways.gorod_2 = j;
                ways.x_1 = goroda[i].x;
                ways.y_2 = goroda[i].y;
                ways.x_2 = goroda[j].x;
                ways.y_2 = goroda[j].y;
                ways.len_of_path = len_vector(goroda[i].x, goroda[i].y, goroda[j].x, goroda[j].y);
                enqueue(array, ways);
                count++;
            }
        }
    }

    qsort(array->arr, count, sizeof(Way), cmp);

    for (int i = 0; i < count; i++) {
        if (find_set(array->arr[i].gorod_1) != find_set(array->arr[i].gorod_2)) {
            addEdge(graph, array->arr[i].gorod_1, array->arr[i].gorod_2);
            union_(array->arr[i].gorod_1, array->arr[i].gorod_2);
            printf("%d %d\n", array->arr[i].gorod_1, array->arr[i].gorod_2);
        }
    }

    return 0;
}